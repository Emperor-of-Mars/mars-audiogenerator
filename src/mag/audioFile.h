/*
**	Author:		Martin Schwarz
**	Name:		audioFile.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_AUDIOFILE
#define MAG_AUDIOFILE

#include "include.h"
#include "audioData.h"


#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

int writeFile(const char *file, std::shared_ptr<audioData> data, int format = SF_FORMAT_WAV | SF_FORMAT_PCM_16);
std::shared_ptr<audioData> readFile(const char *file);

} // mag

#endif // MAG_AUDIOFILE
