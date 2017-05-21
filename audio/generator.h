#ifndef AUDIO_GENERATOR_H_
#define AUDIO_GENERATOR_H_

#include "queue_manager/queue_manager.h"
#include <portaudio.h>
#include <iostream>

#define SAMPLE_RATE (44100)

namespace audio {
namespace generator {

typedef struct {
  float left_phase;
  float right_phase;
} PaTestData;

static PaTestData data;

class AudioGenerator {
 public:
  AudioGenerator();
  ~AudioGenerator() = default;

  void operator()();
  void Stop();

  static int Callback(const void *input, void *output, unsigned long frameCount,
                      const PaStreamCallbackTimeInfo *timeInfo,
                      PaStreamCallbackFlags statusFlags, void *userData);

  void EvalError(PaError error);

 private:
  bool running_ = true;
};
}
}

#endif  // AUDIO_GENERATOR_H_
