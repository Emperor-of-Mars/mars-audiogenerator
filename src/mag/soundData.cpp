/*
**	Author:		Martin Schwarz
**	Name:		soundData.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "soundData.h"

namespace mag{


soundData::soundData(){
    mSampleRate = 0;
    mNumSamples = 0;
    mChannels = 0;
}

soundData::~soundData(){
    mData.empty();
    mSampleRate = 0;
    mNumSamples = 0;
    mChannels = 0;
}


} // mag
