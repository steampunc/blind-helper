#include "vision/interface.h"
#include "audio/generator.h"
#include <thread>
#include <iostream>

int main() {
  vision::interface::VisionInterface interface;
  audio::generator::AudioGenerator generator;

  std::thread audio_thread{std::ref(generator)};
  std::thread vision_thread{std::ref(interface)};

  audio_thread.detach();
  vision_thread.detach();
  while (true) {
  }
  return 0;
}
