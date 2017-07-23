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

    // Cropping
    {
      int offset_x = 0;
      int offset_y = 100;

      cv::Rect roi;
      roi.x = offset_x;
      roi.y = offset_y;
      roi.width = raw.size().width;
      roi.height = 50;
      raw = raw(roi);
    }

    // Processing
    {
      // TODO Get user inputs here to set settings on image
      int user_blur_size = 20;
      cv::ColorConversionCodes user_colorspace_conversion = cv::COLOR_BGR2HSV;

      // Reduce noise from webcam
      cv::blur(raw, raw, cv::Size(user_blur_size, user_blur_size));

      // Change colorspace to whatever user wants it to be
      cv::cvtColor(raw, image, user_colorspace_conversion);
      vision_output->set_colorspace(user_colorspace_conversion);
    }

    int user_scan_speed = 30;
    int user_scan_delay = 3 * user_scan_speed;
    bool user_scanning = false;

    int user_num_partitions = 5;

    double partition_width =
        double(image.size().width) / double(user_num_partitions);
    int y_pos = int(double(image.size().height) / 2.0);

    if (user_scanning) {
      vision::Section *pixel_data = vision_output->add_section();

      if (scanning_pos_ >= 0) {
        pixel_data->set_a(image.at<cv::Vec3b>(y_pos, scanning_pos_).val[0]);
        pixel_data->set_b(image.at<cv::Vec3b>(y_pos, scanning_pos_).val[1]);
        pixel_data->set_c(image.at<cv::Vec3b>(y_pos, scanning_pos_).val[2]);
        pixel_data->set_position(double(scanning_pos_) /
                                 double(image.size().width));
      } else {
        pixel_data->set_a(0);
        pixel_data->set_b(0);
        pixel_data->set_c(0);
      }

      scanning_pos_ += user_scan_speed;
      if (scanning_pos_ > image.size().width) {
        scanning_pos_ = -user_scan_delay;
      }

    } else {
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
