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
    alSourcePlay(sources[source]);
}

ALint AudioController::getSourceStatus(int source) {
    ALint state;
    alGetSourcei(sources[source], AL_SOURCE_STATE, &state);
    return state;
}
