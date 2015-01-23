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
	audioStream *data = (audioStream *)userData;
	float *out = (float *)outputBuffer;
	unsigned long realCount = frameCount;

	if(data->mNumSamples <= 0) return paComplete;

	if(frameCount > data->mNumSamples) realCount = data->mNumSamples;

	//memccpy(out, &(data->mData[data->mPosition]), realCount, sizeof(float) * data->mChannels);

	for(unsigned int i = 0; i < realCount; i++){
        out[i] = data->mData[data->mPosition + i];
    }

/*
    for(unsigned int i = 0; i < realCount * 2; i += 2){
        out[i] = sinf(500 * ((float)i / (float)44100) * 1.f * M_PI) * 0.6;
        out[i + 1] = sinf(500 * ((float)i / (float)44100) * 1.5f * M_PI) * 0.6;
    }
*/

	data->mPosition += realCount;
	data->mNumSamples -= realCount;

	return paContinue;
}

int playAudio(soundData *data){
	if(data == NULL) return -1;

	std::cerr << "playaudio" << std::endl;

	PaError err;
	if((err = Pa_Initialize()) != paNoError){
		std::cerr << "pa could not initialize: " << Pa_GetErrorText(err) << std::endl;
		return 1;
	}


    audioStream st;
    st.mData = &(data->mData[0]);
    st.mNumSamples = data->mNumSamples;
    st.mChannels = data->mChannels;
    st.mPosition = 0;

    PaStream *stream = NULL;
    err = Pa_OpenDefaultStream(&stream, 0, data->mChannels, paFloat32, data->mSampleRate, 512, audioPlayerCallback, &st);
    if(err != paNoError){
		std::cerr << "pa could not open stream: " << Pa_GetErrorText(err) << std::endl;
		return 1;
    }

    if((err = Pa_StartStream(stream)) != paNoError){
		std::cerr << "pa could not start stream: " << Pa_GetErrorText(err) << std::endl;
		return 1;
    }

    Pa_Sleep(5 * 1000);

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








