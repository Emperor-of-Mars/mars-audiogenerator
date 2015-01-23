/*
**	Author:		Martin Schwarz
**	Name:		soundData.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_SOUNDDATA
#define MAG_SOUNDDATA

#include "include.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

struct soundData{
    soundData();
    ~soundData();

    std::vector<float> mData;

    unsigned int mSampleRate;
    unsigned long int mNumSamples;
    unsigned short mChannels;
};

} // mag

#endif // MAG_SOUNDDATA





