/*
**	Author:		Martin Schwarz
**	Name:		writeWav.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_WRITE_WAV
#define MAG_WRITE_WAV

#include "include.h"
#include "sound.h"


#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

unsigned int writeToFile(const char* filename, void *data, unsigned int sampleBits, unsigned int numSamples, unsigned int sampleRate);

} // mag

#endif // MAG_WRITE_WAV
