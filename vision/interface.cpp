#include "vision/interface.h"
#include <iostream>

namespace vision {
namespace interface {

VisionInterface::VisionInterface() {}

void VisionInterface::operator()() {
  cv::VideoCapture cap;
  cap.open(1);
  cv::Mat raw, image;
  while (running_) {
    VisionOutputProto vision_output;

    cap >> raw;

    // Resizing to reduce processing time
    cv::resize(raw, raw, cv::Size( raw.size().width / 2, raw.size().height / 2));

    // Processing
    {
      // TODO Get user inputs here to set settings on image
      int user_blur_size = raw.size().width - 1;
      cv::ColorConversionCodes user_colorspace_conversion = cv::COLOR_BGR2HSV;

      // Reduce noise from webcam
      cv::GaussianBlur(raw, raw, cv::Size(31, user_blur_size), 0, 0);
                                                                   
      // Change colorspace to whatever user wants it to be         
      cv::cvtColor(raw, image, user_colorspace_conversion);        
      vision_output->set_colorspace(user_colorspace_conversion);   
    }                                                              
                                                                   
    // Kernel Matrix                                               
    //                                                             
    //                                                             
    int user_num_partitions = 10;                                   

    double partition_width =
        double(image.size().width) / double(user_num_partitions);
    int y_pos = int(double(image.size().height) / 2.0);

    for (int i = 0; i < user_num_partitions; i++) {
      // Figure out position of test pixel
      int current_x_pos =
          (double(i) * partition_width) + (partition_width / 2.0);

      vision::Section *pixel_data = vision_output->add_section();
      pixel_data->set_a(image.at<cv::Vec3b>(y_pos, current_x_pos).val[0]);
      pixel_data->set_b(image.at<cv::Vec3b>(y_pos, current_x_pos).val[1]);
      pixel_data->set_c(image.at<cv::Vec3b>(y_pos, current_x_pos).val[2]);
      pixel_data->set_position(double(current_x_pos) /
                               double(image.size().width));
    }

    queue_manager::QueueManager::GetInstance()
        .vision_output_queue()
        .WriteMessage(vision_output);

    // Debug image displaying
    cv::imshow("vision", image);
    cv::imshow("raw", raw);
    cv::waitKey(1);
  }
}

void VisionInterface::Stop() { running_ = false; }
}
}
