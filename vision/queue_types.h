#ifndef VISION_QUEUE_TYPES_H_
#define VISION_QUEUE_TYPES_H_

#include "third_party/proto/stack_proto.h"
#include "third_party/queues/message_queue.h"
#include "vision/vision.pb.h"

namespace vision {

using VisionOutputProto = muan::proto::StackProto<VisionOutput, 1024>;

using VisionOutputQueue = muan::queues::MessageQueue<VisionOutputProto, 100>;

}  // namespace vision

#endif  // VISION_QUEUE_TYPES_H_
