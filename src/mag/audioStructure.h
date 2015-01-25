/*
**	Author:		Martin Schwarz
**	Name:		audioStructure.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_AUDIOSTRUCTURE
#define MAG_AUDIOSTRUCTURE

#include "include.h"
#include "audioData.h"
#include "audioFile.h"
#include "audioPlayer.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

class audioStructure{
public:
    audioStructure();
    virtual ~audioStructure();

	virtual int writeFile(const char *file, int format = SF_FORMAT_WAV | SF_FORMAT_PCM_16) = 0;

	virtual int play() = 0;

	virtual std::shared_ptr<audioData> getResult();

protected:
	virtual int render() = 0;

    std::shared_ptr<audioData> mResult;
    int mStatus;
};

} // mag

#endif // MAG_AUDIOSTRUCTURE





