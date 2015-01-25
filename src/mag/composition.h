/*
**	Author:		Martin Schwarz
**	Name:		composition.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_COMPOSITION
#define MAG_COMPOSITION

#include "include.h"
#include "sound.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

class composition{
public:
    composition();
    ~composition();

	int readFile(const char *file);
	int writeToFile(const char *file, int format = SF_FORMAT_WAV | SF_FORMAT_PCM_16);

	int play();

	audioData *getAudioData();

private:

};

} // mag

#endif // MAG_COMPOSITION





