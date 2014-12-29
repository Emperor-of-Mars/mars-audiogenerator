/*
**	Author:		Martin Schwarz
**	Name:		sound.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "sound.h"

namespace mag{


soundData::soundData(){
    mNumSamples = 0;
    mSampleRate = 0;
    mFreq = 0;
    mAmplitude = 0;
}

soundData::~soundData(){
    mData.empty();
    mNumSamples = 0;
    mSampleRate = 0;
    mFreq = 0;
    mAmplitude = 0;
}


sound::sound(){
}

sound::sound(soundData *s){
    mSoundData = *s;
}

sound::sound(std::vector<float> data, unsigned int numSamples, unsigned int sampleRate, unsigned int freq, unsigned int amplitude){
    mSoundData.mData = data;
    mSoundData.mNumSamples = numSamples;
    mSoundData.mSampleRate = sampleRate;
    mSoundData.mFreq = freq;
    mSoundData.mAmplitude = amplitude;
}

sound::sound(float *data, unsigned int numSamples, unsigned int sampleRate, unsigned int freq, unsigned int amplitude){
    mSoundData.mData.insert(mSoundData.mData.end(), &data[0], &data[numSamples]);
    mSoundData.mNumSamples = numSamples;
    mSoundData.mSampleRate = sampleRate;
    mSoundData.mFreq = freq;
    mSoundData.mAmplitude = amplitude;
}

sound::~sound(){
}

int sound::operator =(const sound *s){
    if(s == 0) return -1;
    mSoundData = s->mSoundData;
    return 0;
}

int sound::operator =(const soundData *s){
    if(s == 0) return -1;
    mSoundData = *s;
    return 0;
}

int sound::manipulate(const char* key, const char* value){
    return 0;
}

int sound::writeToFile(const char* filename){
    uint16_t *data = genRaw16();
    unsigned int ret = mag::writeToFile(filename, data, 16, mSoundData.mNumSamples, mSoundData.mSampleRate);
    delete [] data;
    return ret;
}

uint8_t *sound::genRaw8(){
    uint8_t *ret = new uint8_t[mSoundData.mNumSamples];
    for(unsigned int i = 0; i < mSoundData.mNumSamples; i++) ret[i] = (uint8_t)(mSoundData.mData[i] * (uint8_t)(mSoundData.mAmplitude / 0xffffff));
    return ret;
}

uint16_t *sound::genRaw16(){
    uint16_t *ret = new uint16_t[mSoundData.mNumSamples];
    for(unsigned int i = 0; i < mSoundData.mNumSamples; i++) ret[i] = (uint16_t)(mSoundData.mData[i] * (uint16_t)(mSoundData.mAmplitude / 0xffff));
    return ret;
}

uint32_t *sound::genRaw32(){
    uint32_t *ret = new uint32_t[mSoundData.mNumSamples];
    for(unsigned int i = 0; i < mSoundData.mNumSamples; i++) ret[i] = (uint32_t)(mSoundData.mData[i] * mSoundData.mAmplitude);
    return ret;
}



} // mag










