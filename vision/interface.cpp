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
    cv::cvtColor(raw, image, CV_BGR2HSV);
    cv::imshow("vision", image);
    cv::waitKey(1);

    vision::Section* pixel_data = vision_output->add_section();
    pixel_data->set_hue(image.at<cv::Vec3b>(0, 0)[2] * 2 + 200);
    pixel_data->set_saturation(0);
    pixel_data->set_value(0);
    pixel_data->set_position(0);

    queue_manager::QueueManager::GetInstance()
        .vision_output_queue()
        .WriteMessage(vision_output);
  }
}

void VisionInterface::Stop() { running_ = false; }
}
}
