/*
**	Author:		Martin Schwarz
**	Name:		audioData.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_AUDIODATA
#define MAG_AUDIODATA

#include "include.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

struct audioData{
    audioData();
    ~audioData();

    std::vector<float> mData;

    unsigned int mSampleRate;
    unsigned long int mNumSamples;
    unsigned short mChannels;

    unsigned long int mPos;
};

} // mag

#endif // MAG_AUDIODATA





