/*
**	Author:		Martin Schwarz
**	Name:		audioPlayer.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_AUDIOPLAYER
#define MAG_AUDIOPLAYER

#include "include.h"
#include "audioData.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

//move this into audiostream
int audioPlayerCallback(const void *inputBuffer, void *outputBuffer,
								unsigned long framesPerBuffer,
                          		const PaStreamCallbackTimeInfo* timeInfo,
						  		PaStreamCallbackFlags statusFlags,
								void *userData);

int playAudio(audioData *data);

class audioStream{
public:
	audioStream();
	~audioStream();

	int init();
	int close();

	int play(audioData *ad);
	int pause(bool pause);
	int stop();
	int setPos(float pos);

private:
	audioData *mAudioData;
};


} // mag

#endif // MAG_AUDIOPLAYER





