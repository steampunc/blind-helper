load("//third_party/protobuf:protobuf.bzl", "cc_proto_library")
licenses(["notice"])

cc_library(
    name = "stack_proto",
    srcs = ["stack_proto.cpp"],
    hdrs = ["stack_proto.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//third_party/protobuf",
    ],
)

cc_proto_library(
    name = "test_proto",
    srcs = ["test_proto.proto"],
    default_runtime = "//third_party/protobuf",
    protoc = "//third_party/google/protobuf:protoc",
)
