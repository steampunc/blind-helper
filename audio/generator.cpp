#include "audio/generator.h"

namespace audio {
namespace generator {

AudioGenerator::AudioGenerator() {}

void AudioGenerator::operator()() {
  // Setup PortAudio to generate audio
  PaError error = Pa_Initialize();
  EvalError(error);

  PaStream *stream;
  error = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32, SAMPLE_RATE, 256,
                               Callback, &data);
  EvalError(error);

  error = Pa_StartStream(stream);
  EvalError(error);

  Pa_Sleep(30000);

  /* while (running_) { */
  /*   auto vision_proto = queue_manager::QueueManager::GetInstance() */
  /*                           .vision_output_queue() */
  /*                           .ReadLastMessage(); */

  /*   if (vision_proto) { */
  /*     // Do audio generation */
  /*   } */
  /* } */

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

  for (unsigned long i = 0; i < frameCount; i++) {
    auto vision_input = queue_manager::QueueManager::GetInstance()
                            .vision_output_queue()
                            .ReadLastMessage();

    data->left_phase = 0.0;
    data->right_phase = 0.0;
    if (vision_input) {
      for (int j = 0; j < vision_input.value()->section_size(); j++) {
        data->left_phase =
            sin(2.0 * M_PI * vision_input.value()->section(j).hue() *
                (double(i) / double(SAMPLE_RATE)));
        data->right_phase =
            sin(2.0 * M_PI * vision_input.value()->section(j).hue() *
                (double(i) / double(SAMPLE_RATE)));
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
