/*
**	Author:		Martin Schwarz
**	Name:		sound.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "wavWriter.h"

namespace mag{


sound::sound(){
    mNumSamples = 0;
    mSampleRate = 0;
    mFreq = 0;
    mAmplitude = 0;
}

sound::sound(std::vector<float> data, unsigned int numSamples, unsigned int sampleRate, unsigned int freq, unsigned int amplitude){
    mData = data;
    mNumSamples = numSamples;
    mSampleRate = sampleRate;
    mFreq = freq;
    mAmplitude = amplitude;
}

sound::~sound(){
    mData.empty();
    mNumSamples = 0;
    mSampleRate = 0;
    mFreq = 0;
    mAmplitude = 0;
}

unsigned int sound::manipulate(const char* key, const char* value){
    return 0;
}

unsigned int sound::writeToFile(const char* filename){
    return mag::writeToFile(filename, genRaw16(), 16, mNumSamples, mSampleRate);
}

uint8_t *sound::genRaw8(){
    uint8_t *ret = new uint8_t[mNumSamples];
    for(unsigned int i = 0; i < mNumSamples; i++) ret[i] = (uint8_t)(mData[i] * (uint8_t)(mAmplitude / 0xffffff));
    return ret;
}

uint16_t *sound::genRaw16(){
    uint16_t *ret = new uint16_t[mNumSamples];
    for(unsigned int i = 0; i < mNumSamples; i++) ret[i] = (uint16_t)(mData[i] * (uint16_t)(mAmplitude / 0xffff));
    return ret;
}

uint32_t *sound::genRaw32(){
    uint32_t *ret = new uint32_t[mNumSamples];
    for(unsigned int i = 0; i < mNumSamples; i++) ret[i] = (uint32_t)(mData[i] * mAmplitude);
    return ret;
}



} // mag










