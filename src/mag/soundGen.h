/*
**	Author:		Martin Schwarz
**	Name:		soundGen.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_SOUNDGEN
#define MAG_SOUNDGEN

#include "include.h"

#include "sound.h"


#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

sound *genSinus(unsigned int sampleRate, float freq, unsigned int ampl, unsigned int len_ms);

} // mag

#endif // MAG_SOUNDGEN
