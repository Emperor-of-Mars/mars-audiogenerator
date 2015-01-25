/*
**	Author:		Martin Schwarz
**	Name:		audioFile.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_AUDIOFILE
#define MAG_AUDIOFILE

#include "include.h"
#include "sound.h"


#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

int writeToFile(const char *file, audioData *s, int format = SF_FORMAT_WAV | SF_FORMAT_PCM_16);
audioData *readFile(const char *file);

} // mag

#endif // MAG_AUDIOFILE
