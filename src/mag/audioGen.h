/*
**	Author:		Martin Schwarz
**	Name:		audioGen.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_AUDIOGEN
#define MAG_AUDIOGEN

#include "include.h"

#include "sound.h"


#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

std::shared_ptr<audioData> genSound(const char *type, const char *values);
std::shared_ptr<audioData> genSinus(unsigned int sampleRate, float freq, unsigned int len_ms);

} // mag

#endif // MAG_AUDIOGEN
