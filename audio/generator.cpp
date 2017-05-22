#include "audio/generator.h"

namespace audio {
namespace generator {

AudioGenerator::AudioGenerator() {}

void AudioGenerator::operator()() {
  // Setup PortAudio to generate audio
  PaError error = Pa_Initialize();
  EvalError(error);

  PaStream *stream;
  data.counter = 0;
  error = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32, SAMPLE_RATE, 256,
                               Callback, &data);
  EvalError(error);

  error = Pa_StartStream(stream);
  EvalError(error);

  while (running_) {
    Pa_Sleep(1e20);
  }

  error = Pa_StopStream(stream);
  EvalError(error);

  // Close streams and terminate PortAudio once done
  error = Pa_CloseStream(stream);
  EvalError(error);

  error = Pa_Terminate();
  EvalError(error);
}

int AudioGenerator::Callback(const void *input, void *output,
                             unsigned long frameCount,
                             const PaStreamCallbackTimeInfo *timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData) {
  PaTestData *data = (PaTestData *)userData;
  float *out = (float *)output;

  for (uint64_t i = 0; i < frameCount; i++, (data->counter)++) {
    auto vision_input = queue_manager::QueueManager::GetInstance()
                            .vision_output_queue()
                            .ReadLastMessage();

    data->left_phase = 0.0;
    data->right_phase = 0.0;

    if (vision_input) {
      for (int j = 0; j < vision_input.value()->section_size(); j++) {
        data->left_phase +=
            vision_input.value()->section(j).position() *
            sin(constant * ((double(vision_input.value()->section(j).hue()) *
                             user_sound_range_constant) +
                            user_sound_base_constant));
        data->right_phase +=
            (1.0 - vision_input.value()->section(j).position()) *
            sin(constant * ((double(vision_input.value()->section(j).hue()) *
                             user_sound_range_constant) +
                            user_sound_base_constant));
      }
    }

    std::cout << data->left_phase << ", " << data->right_phase << ", "
              << double(i) / double(SAMPLE_RATE) << std::endl;

    *out++ = data->left_phase;  /* left */
    *out++ = data->right_phase; /* right */
  }

  return 0;
}

void AudioGenerator::Stop() { running_ = false; }

void AudioGenerator::EvalError(PaError error) {
  if (error != paNoError) std::cout << "PortAudio error: " + error << std::endl;
}
}
}
