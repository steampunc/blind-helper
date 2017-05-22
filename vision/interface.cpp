#include "vision/interface.h"
#include <iostream>

namespace vision {
namespace interface {

VisionInterface::VisionInterface() {}

void VisionInterface::operator()() {
  cv::VideoCapture cap;
  cap.open(0);
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
      // Reduce noise from webcam
      cv::blur(raw, raw, cv::Size(user_blur_size, user_blur_size));

      // Change colorspace to whatever user wants it to be
      cv::cvtColor(raw, image, user_colorspace_conversion);
    }

      vision::Section* pixel_data = vision_output->add_section();
      pixel_data->set_hue(image.at<uchar>(
          int(double(image.size().height) / 2.0), current_x_pos));
      pixel_data->set_saturation(0);
      pixel_data->set_value(0);
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
