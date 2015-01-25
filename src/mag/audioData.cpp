/*
**	Author:		Martin Schwarz
**	Name:		audioData.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "audioData.h"

namespace mag{


audioData::audioData(){
    mSampleRate = 0;
    mNumSamples = 0;
    mChannels = 0;
    mPos = 0;
}

audioData::~audioData(){
    mData.empty();
    mSampleRate = 0;
    mNumSamples = 0;
    mChannels = 0;
    mPos = 0;
}


} // mag
