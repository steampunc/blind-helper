#ifndef QUEUE_MANAGER_QUEUE_MANAGER_H_
#define QUEUE_MANAGER_QUEUE_MANAGER_H_

#include <thread>
#include <functional>
#include "third_party/proto/stack_proto.h"
#include "third_party/queues/message_queue.h"

#include "vision/queue_types.h"

using muan::queues::MessageQueue;

namespace queue_manager {

// A class that contains all of the queues, and allows anyone to get a reference
// to any queue. This is to avoid having all the queues as global variables
// (because that would be gross). Instead, we can just have an instance of this
// as a global, which is much less sketchy.
class QueueManager {
 public:
  static QueueManager& GetInstance();

  vision::VisionOutputQueue& vision_output_queue();
  void Reset();

 private:
  QueueManager() = default;
  ~QueueManager() = default;

  vision::VisionOutputQueue vision_output_queue_;
};

}  // namespace queue_manager

#endif  // QUEUE_MANAGER_QUEUE_MANAGER_H_
