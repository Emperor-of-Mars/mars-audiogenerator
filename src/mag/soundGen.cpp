/*
**	Author:		Martin Schwarz
**	Name:		sound.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "soundGen.h"

namespace mag{


soundData *genSound(const char *type, const char *values){
    return NULL;
}

soundData *genSinus(unsigned int sampleRate, float freq, unsigned int ampl, unsigned int len_ms){
    unsigned int numSamples = sampleRate * len_ms / 1000;
    soundData *s = new soundData;
    s->mData.resize(numSamples);
    for(unsigned int i = 0; i < numSamples; i ++){
        s->mData[i] = sinf(freq * ((float)i / (float)sampleRate) * 2.f * M_PI);
    }
    s->mNumSamples = numSamples;
    s->mSampleRate = sampleRate;
    s->mFreq = freq;
    s->mAmplitude = ampl;
    return s;
}

} // mag










