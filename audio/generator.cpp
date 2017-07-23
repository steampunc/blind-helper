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

    float constant = 2.0 * M_PI * (double(data->counter) / double(SAMPLE_RATE));
    double user_sound_range_constant = 3;
    double user_sound_base_constant = 100;

    if (vision_input) {
      for (int j = 0; j < vision_input.value()->section_size(); j++) {
        double left_pitch = double(vision_input.value()->section(j).a()) *
                                user_sound_range_constant +
                            user_sound_base_constant;
        double right_pitch = double(vision_input.value()->section(j).a()) *
                                 user_sound_range_constant +
                             user_sound_base_constant;

        double left_amplitude =
            (1.0 - vision_input.value()->section(j).position()) *
            (1.0 - (100.0 / (vision_input.value()->section(j).b() + 100.0) * 0 +
                    100.0 / (vision_input.value()->section(j).c() + 100.0)));
        double right_amplitude =
            (vision_input.value()->section(j).position()) *
            (1.0 - (100.0 / (vision_input.value()->section(j).b() + 100.0) * 0 +
                    100.0 / (vision_input.value()->section(j).c() + 100.0)));

        data->left_phase += left_amplitude * sin(constant * left_pitch);
        data->right_phase += right_amplitude * sin(constant * right_pitch);
      }
    }

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
