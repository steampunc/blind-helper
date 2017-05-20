#ifndef AUDIO_GENERATOR_H_
#define AUDIO_GENERATOR_H_

#include "queue_manager/queue_manager.h"
#include <portaudio.h>
#include <iostream>

namespace audio {
namespace generator {

class AudioGenerator {
 public:
  AudioGenerator();
  ~AudioGenerator() = default;

  void operator()();
  void Stop();

 private:
  bool running_ = true;
};
}
}

#endif  // AUDIO_GENERATOR_H_
