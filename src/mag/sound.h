/*
**	Author:		Martin Schwarz
**	Name:		sound.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_SOUND
#define MAG_SOUND

#include "include.h"
#include "audioData.h"
#include "audioFile.h"
#include "audioPlayer.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

class sound{
public:
    sound();
    sound(const char *file);
    sound(audioData *s);
    ~sound();

    int operator =(audioData *s);

	int readFile(const char *file);
	int writeToFile(const char *file, int format = SF_FORMAT_WAV | SF_FORMAT_PCM_16);

	int play();

	audioData *getAudioData();

private:
    audioData *mAudioData;
/*
    std::vector<float> mData;

    unsigned int mSampleRate;
    unsigned long int mNumSamples;
    unsigned short mChannels;

    unsigned long int mPos;
*/
    int mStatus;
};

} // mag

#endif // MAG_SOUND





