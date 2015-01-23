/*
**	Author:		Martin Schwarz
**	Name:		audioPlayer.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_AUDIOPLAYER
#define MAG_AUDIOPLAYER

#include "include.h"
#include "soundData.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{


struct audioStream{
	unsigned long int mPosition;
	unsigned long int mNumSamples;
    unsigned short mChannels;
	std::vector<float> *mData;
};

int audioPlayerCallback(const void *inputBuffer, void *outputBuffer,
								unsigned long framesPerBuffer,
                          		const PaStreamCallbackTimeInfo* timeInfo,
						  		PaStreamCallbackFlags statusFlags,
								void *userData);

int playAudio(soundData *data);


} // mag

#endif // MAG_AUDIOPLAYER





