load("//third_party/protobuf:protobuf.bzl", "cc_proto_library")

cc_library(
  name = 'interface',
  srcs = ['interface.cpp'],
  hdrs = ['interface.h'],
  deps = ['//queue_manager:queue_manager',
          ':vision_queues',
          '@opencv//:opencv'],
  visibility = ["//visibility:public"],
  linkopts = ['-lopencv_video', '-lopencv_highgui', '-lopencv_imgproc', '-lopencv_core']
)

cc_library(
  name = 'vision_queues',
  hdrs = ['queue_types.h'],
  deps = [':vision_proto',
          '//third_party/proto:stack_proto',
          '//third_party/queues:queues'],
  visibility = ['//visibility:public']
)

cc_proto_library(
  name = 'vision_proto',
  srcs = ['vision.proto'],
  protoc = '//third_party/protobuf:protoc',
  default_runtime = '//third_party/protobuf',
)
