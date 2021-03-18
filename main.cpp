#include <AL/al.h>
#include <vector>
#include <cmath>
#include <memory>
#include "AudioController.h"

/**
 * Returns sine wave of format AL_FORMAT_MONO8
 */
char* generateSine(std::int32_t sampleRate, ALsizei size, double frequency) {
  auto data = new char[size];
  for(int i = 0; i < size; i++) {
    data[i] = 128 + 128 * sin(frequency * 2 * 3.141592 * ((double)i/sampleRate));
  }
  return data;
}

int main() {
    int sampleRate = 44100;
    int duration = 2;

    std::unique_ptr<AudioController> audio = std::make_unique<AudioController>();
    audio->init();
    audio->playSound(0,
                     generateSine(sampleRate, duration * sampleRate, 220.0),
                     duration * sampleRate, sampleRate);

    audio->playSound(1,
                     generateSine(sampleRate, duration * sampleRate, 440.0),
                     duration * sampleRate, sampleRate);

    while(audio->getSourceStatus(0) == AL_PLAYING);
    return 0;
}