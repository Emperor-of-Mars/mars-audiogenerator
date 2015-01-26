/*
**	Author:		Martin Schwarz
**	Name:		audioGen.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "audioGen.h"

namespace mag{


std::shared_ptr<audioData> genSound(const char *type, const char *values){
    return NULL;
}

std::shared_ptr<audioData> genSinus(unsigned int sampleRate, float freq, unsigned int len_ms){
    unsigned int numSamples = sampleRate * len_ms / 1000;
    audioData *s = new audioData;
    s->mData.resize(numSamples * 2);
    for(unsigned int i = 0; i < numSamples * 2; i += 2){
        s->mData[i] = sinf(freq * ((float)i / (float)sampleRate) * 1.5f * M_PI);
        s->mData[i + 1] = sinf(freq * ((float)i / (float)sampleRate) * 2.5f * M_PI);
        //s->mData[i] = 0;
    }
    s->mNumSamples = numSamples;
    s->mSampleRate = sampleRate;
    s->mChannels = 2;
    std::shared_ptr<audioData> sp(s);
    return sp;
}

} // mag










