package(default_visibility = ["//visibility:public"])
licenses(["notice"])

cc_library(
    name = "queues",
    srcs = ["message_queue.hpp"],
    hdrs = ["message_queue.h"],
    linkstatic = 1,
    deps = [
        "//third_party/proto:stack_proto",
        "//third_party/optional",
    ],
)
