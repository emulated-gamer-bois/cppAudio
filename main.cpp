#include <AL/al.h>
#include <vector>
#include <cmath>
#include <memory>

#include <chrono>
#include <thread>

#include "AudioController.h"

/**
 * Returns sine wave of format AL_FORMAT_MONO8
 */
char* generateSine(std::int32_t sampleRate, ALsizei size, double frequency) {
  auto data = new char[size];
  for(int i = 0; i < size; i++) {
    data[i] = sin(frequency * 2 * 3.141592 * ((double)i/sampleRate)) > 0 ? 255 : 0;
  }
  return data;
}

int main() {
    /**
     *
    //Playing two unpleasant tones at once
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
     */

    std::unique_ptr<AudioController> audio = std::make_unique<AudioController>();
    audio->init();

    double frequencies[] = {65.4, 82.4, 98.0};
    for(int i = 0; i < 3; i++) {
        for(int k = 0; k < 4; k++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
            audio->playSquare(k, 0b10, frequencies[k]);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            audio->stopSource(i);
            frequencies[k] *= 2;
        }
    }

    //Plays the Game Boy boot sound, given the values provided by the boot rom
    /*audio->playSquare(0, 2, 0x783);
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    audio->stopSource(0);
    audio->playSquare(1, 2, 0x7FF);
    std::this_thread::sleep_for(std::chrono::milliseconds(400));*/

    return 0;
}