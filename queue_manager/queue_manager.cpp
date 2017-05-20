#include "queue_manager/queue_manager.h"

namespace queue_manager {

QueueManager& QueueManager::GetInstance() {
  static QueueManager instance;
  return instance;
}

vision::VisionOutputQueue& QueueManager::vision_output_queue() {
  return vision_output_queue_;
}

void QueueManager::Reset() { vision_output_queue_.Reset(); }

}  // namespace queue_manager
