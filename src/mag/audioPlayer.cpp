/*
**	Author:		Martin Schwarz
**	Name:		audioPlayer.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "audioPlayer.h"

namespace mag{


int audioPlayerCallback(const void *inputBuffer, void *outputBuffer,
						  unsigned long frameCount,
                          const PaStreamCallbackTimeInfo* timeInfo,
						  PaStreamCallbackFlags statusFlags,
						  void *userData)
{
	audioData *data = (audioData *)userData;
	float *out = (float *)outputBuffer;
	unsigned long realCount = frameCount;

	if(data->mNumSamples <= 0) return paComplete;

	if(frameCount > data->mNumSamples) realCount = data->mNumSamples;

	for(unsigned int i = 0; i < realCount * data->mChannels; i++){
        out[i] = (data->mData)[data->mPos * data->mChannels + i];
    }

	data->mPos += realCount;
	data->mNumSamples -= realCount;

	return paContinue;
}

int playAudio(audioData *data){
	if(data == NULL) return -1;

	PaError err;
	if((err = Pa_Initialize()) != paNoError){
		std::cerr << "pa could not initialize: " << Pa_GetErrorText(err) << std::endl;
		return 1;
	}

    PaStream *stream = NULL;
    err = Pa_OpenDefaultStream(&stream, 0, data->mChannels, paFloat32, data->mSampleRate, 512, audioPlayerCallback, data);
    if(err != paNoError){
		std::cerr << "pa could not open stream: " << Pa_GetErrorText(err) << std::endl;
		return 1;
    }

    if((err = Pa_StartStream(stream)) != paNoError){
		std::cerr << "pa could not start stream: " << Pa_GetErrorText(err) << std::endl;
		return 1;
    }

    Pa_Sleep(2 * 1000);

    if((err = Pa_StopStream(stream)) != paNoError){
		std::cerr << "pa could not stop stream: " << Pa_GetErrorText(err) << std::endl;
		return 1;
    }

    if((err = Pa_CloseStream(stream)) != paNoError){
		std::cerr << "pa could not close stream: " << Pa_GetErrorText(err) << std::endl;
		return 1;
    }

	if((err = Pa_Terminate()) != paNoError){
		std::cerr << "pa could not terminate: " << Pa_GetErrorText(err) << std::endl;
		return 1;
	}

	return 0;
}


} // mag








