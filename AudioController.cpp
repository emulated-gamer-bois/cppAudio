//
// Created by David Möller on 2021-03-18.
//

#include "AudioController.h"
#include <AL/alc.h>
#include <iostream>

AudioController::~AudioController() {
    alDeleteSources(N_SOURCES, sources);
    alDeleteBuffers(N_SOURCES, buffers);

    alcMakeContextCurrent(context);
    alcDestroyContext(context);

    if(!alcCloseDevice(device))
        std::cerr << "Field to close device\n";
}

void AudioController::init() {
    device = alcOpenDevice(nullptr);
    ALCenum error;

    if(!device) {
        std::cerr << "Failed to open device\n";
        return;
    }

    context = alcCreateContext(device, nullptr);
    error = alcGetError(device);

    if(error || !context) {
        std::cerr << "ERROR: Could not create audio context" << std::endl;
        return;
    }

    auto contextMadeCurrent = alcMakeContextCurrent(context);
    error = alcGetError(device);

    if(error || contextMadeCurrent != ALC_TRUE) {
        std::cerr << "ERROR: Could not make audio context current" << std::endl;
        return;
    }

    alGenBuffers(N_SOURCES, buffers);
    alGenSources(N_SOURCES, sources);

    for(int i = 0; i < N_SOURCES; i++) {
        alSourcef(sources[i], AL_PITCH, 1);
        alSourcef(sources[i], AL_GAIN, 1.0f);
        alSource3f(sources[i], AL_POSITION, 0, 0, 0);
        alSource3f(sources[i], AL_VELOCITY, 0, 0, 0);
        alSourcei(sources[i], AL_LOOPING, AL_FALSE);
    }
}

void AudioController::playSound(int source, char *soundData, int size, int sampleRate) {
    if(source > N_SOURCES || source < 0) return;
    if(getSourceStatus(source) == AL_PLAYING) return;

    alBufferData(buffers[source], AL_FORMAT_MONO8, soundData, size, sampleRate);
    alSourcei(sources[source], AL_BUFFER, buffers[source]);
    alSourcei(sources[source], AL_LOOPING, 0);
    alSourcePlay(sources[source]);
}

ALint AudioController::getSourceStatus(int source) {
    ALint state;
    alGetSourcei(sources[source], AL_SOURCE_STATE, &state);
    return state;
}

//Plays square wave sound
void AudioController::playSquare(int source, char duty, ALsizei frequency) {
    if(source > N_SOURCES || source < 0) return;
    if(getSourceStatus(source) == AL_PLAYING) return;

    alSourcei(sources[source], AL_BUFFER, 0);
    alBufferData(
        buffers[source],
        AL_FORMAT_MONO8,
        duties[duty],
        SQUARE_SAMPLE_RATE,
        SQUARE_SAMPLE_RATE * frequency);
    alSourcei(sources[source], AL_BUFFER, buffers[source]);
    alSourcei(sources[source], AL_LOOPING, 1);
    alSourcePlay(sources[source]);
}

void AudioController::playGBSquare(int source, char duty, unsigned short frequency) {
    this->playSquare(source, duty, 131072.0/(2048 - frequency));
}

AudioController::AudioController() {

    //Assigns default values to duties
    //Duty   Waveform    Ratio
    //-------------------------
    //0      00000001    12.5%
    //1      10000001    25%
    //2      10000111    50%
    //3      01111110    75%
    //The waveforms are stretched out to SQUARE_SAMPLE_RATE number of bytes instead of 8 bits

    const unsigned char dutyPatterns[4] = {0x01, 0x81, 0x87, 0x7E};
    const int stepLength = SQUARE_SAMPLE_RATE / 8;
    unsigned char value;
    int j;

    for(int i = 0; i < 4; i++) {
        j = 0;
        while(j < SQUARE_SAMPLE_RATE) {
            value = ((dutyPatterns[i] >> (7 - (j / stepLength))) & 1) * 0xFF;
            do {
                duties[i][j] = value;
                j++;
            } while(j % stepLength);
        }
    }
}
void AudioController::stopSource(int source) {
    alSourceRewind(sources[source]);
}
