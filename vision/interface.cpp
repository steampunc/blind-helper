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

    queue_manager::QueueManager::GetInstance()
        .vision_output_queue()
        .WriteMessage(vision_output);
  }
}

void VisionInterface::Stop() { running_ = false; }
}
}
