#include <AL/al.h>
#include <AL/alc.h>
#include <iostream>
#include <vector>
#include "wavUtil.h"
#include <cmath>

/**
 * Returns sine wave of format AL_FORMAT_MONO8
 */
unsigned char* generateSine(std::int32_t sampleRate, ALsizei size, double frequency) {
  auto data = new unsigned char[size];
  for(int i = 0; i < size; i++) {
    data[i] = 128 + 128 * sin(frequency * 2 * 3.141592 * ((double)i/sampleRate));
  }
  return data;
}

int main()
{
  auto openALDevice = alcOpenDevice(nullptr);
  ALCenum error;

  if(!openALDevice) {
    std::cerr << "Failed to open device\n";
    return 0;
  }

  auto openALContext = alcCreateContext(openALDevice, nullptr);
  error = alcGetError(openALDevice);

  if(error || !openALContext)
  {
    std::cerr << "ERROR: Could not create audio context" << std::endl;
    return 0;
  }

  ALCboolean contextMadeCurrent = alcMakeContextCurrent(openALContext);
  error = alcGetError(openALDevice);

  if(error || contextMadeCurrent != ALC_TRUE)
  {
    std::cerr << "ERROR: Could not make audio context current" << std::endl;
    return 0;
  }

  std::uint8_t channels = 1;
  std::int32_t sampleRate = 44100;
  std::uint8_t bitsPerSample = 8;
  ALsizei size = 3 * sampleRate;
  /*auto soundData = load_wav("/home/molle/Documents/projects/cppAudio/Alesis-Fusion-Acoustic-Bass-C2.wav", channels, sampleRate, bitsPerSample, size);
  if(!soundData)
  {
    std::cerr << "ERROR: Could not load wav" << std::endl;
    return 0;
  }*/

  auto soundData = generateSine(sampleRate, size, 880.0);

  ALuint buffer;
  alGenBuffers(1, &buffer);


  ALenum format;
  if(channels == 1 && bitsPerSample == 8)
    format = AL_FORMAT_MONO8;
  else if(channels == 1 && bitsPerSample == 16)
    format = AL_FORMAT_MONO16;
  else if(channels == 2 && bitsPerSample == 8)
    format = AL_FORMAT_STEREO8;
  else if(channels == 2 && bitsPerSample == 16)
    format = AL_FORMAT_STEREO16;
  else
  {
    std::cerr
        << "ERROR: unrecognised wave format: "
        << channels << " channels, "
        << bitsPerSample << " bps" << std::endl;
    return 0;
  }

  //alCall(alBufferData, buffer, format, soundData.data(), soundData.size(), sampleRate);
  alBufferData(buffer, format, soundData, size, sampleRate);
  delete[] soundData; // erase the sound in RAM

  error = alcGetError(openALDevice);
  if(error) {
    std::cerr << error << std::endl;
    return 0;
  }

  ALuint source;
  alGenSources(1, &source);
  alSourcef(source, AL_PITCH, 1);
  alSourcef(source, AL_GAIN, 1.0f);
  alSource3f(source, AL_POSITION, 0, 0, 0);
  alSource3f(source, AL_VELOCITY, 0, 0, 0);
  alSourcei(source, AL_LOOPING, AL_FALSE);
  alSourcei(source, AL_BUFFER, buffer);

  alSourcePlay(source);

  ALint state = AL_PLAYING;

  while(state == AL_PLAYING)
  {
    alGetSourcei(source, AL_SOURCE_STATE, &state);
  }

  alDeleteSources(1, &source);
  alDeleteBuffers(1, &buffer);

  contextMadeCurrent = alcMakeContextCurrent(openALContext);
  alcDestroyContext(openALContext);

  std::cout << "Successfully found device and set up\n";
  if(!alcCloseDevice(openALDevice))
    std::cerr << "Field to close device\n";

  return 0;
}