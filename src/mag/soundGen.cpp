/*
**	Author:		Martin Schwarz
**	Name:		sound.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "soundGen.h"

namespace mag{


sound *genSinus(unsigned int sampleRate, float freq, unsigned int ampl, unsigned int len_ms){
    unsigned int numSamples = sampleRate * len_ms / 1000;
    std::vector<float>data;
    data.resize(numSamples);
    for(unsigned int i = 0; i < numSamples; i ++){
        data[i] = sinf(freq * ((float)i / (float)sampleRate) * 2.f * M_PI);
    }
    sound *s = new sound(data, numSamples, sampleRate, freq, ampl);
    return s;
}

} // mag










