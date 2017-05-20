#include "audio/generator.h"

namespace audio {
namespace generator {

AudioGenerator::AudioGenerator() {}

void AudioGenerator::operator()() {
  while (running_) {
    auto vision_proto = queue_manager::QueueManager::GetInstance()
                            .vision_output_queue()
                            .ReadLastMessage();

    std::cout << "Hello, running audio" << std::endl;

    if (vision_proto) {
      // Do audio generation
    }
  }
}

void AudioGenerator::Stop() { running_ = false; }
}
}
