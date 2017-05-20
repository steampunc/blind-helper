#ifndef VISION_INTERFACE_H_
#define VISION_INTERFACE_H_

#include "vision/queue_types.h"
#include "queue_manager/queue_manager.h"
#include <opencv2/opencv.hpp>

namespace vision {
namespace interface {

class VisionInterface {
 public:
  VisionInterface();
  ~VisionInterface() = default;

  void operator()();
  void Stop();

 private:
  bool running_ = true;
};
}
}

#endif
