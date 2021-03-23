//
// Created by David Möller on 2021-03-18.
//

#pragma once
#include <AL/alc.h>
#include <AL/al.h>

class AudioController {
 public:
    AudioController();
    ~AudioController();
    void init();
    void playSquare(int source, char duty, ALsizei frequency) ;
    void playGBSquare(int source, char duty, unsigned short frequency);
    void playSound(int source, char *soundData, int size, int sampleRate);
    void stopSource(int source);
    ALint getSourceStatus(int source);

 private:
    const static int N_SOURCES = 4;
    const static int SQUARE_SAMPLE_RATE = 32;
    unsigned char duties[4][SQUARE_SAMPLE_RATE];

    ALuint buffers[N_SOURCES];
    ALuint sources[N_SOURCES];

    ALCdevice* device;
    ALCcontext* context;
};
