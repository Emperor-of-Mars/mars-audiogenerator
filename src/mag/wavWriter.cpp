/*
**	Author:		Martin Schwarz
**	Name:		writeWav.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "wavWriter.h"

namespace mag{


int writeToFile(const char *file, sound *s){
	SNDFILE* f = NULL;
	SF_INFO info;

	//info.frames = s->getSoundData()->mNumSamples;
	info.samplerate = s->getSoundData()->mSampleRate;
	info.channels = s->getSoundData()->mChannels;
	info.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

	if(!(f = sf_open(file, SFM_WRITE, &info))){
		#if _DEBUG_LEVEL >= 1
			std::cerr << "unable to open file!" << std::endl;
		#endif // _DEBUG_LEVEL
		sf_close(f);
		return -1;
	}

	if(sf_write_float(f, &s->getSoundData()->mData[0], (sf_count_t)s->getSoundData()->mNumSamples) != (sf_count_t)s->getSoundData()->mNumSamples){
		#if _DEBUG_LEVEL >= 1
			std::cerr << "unable to write to file!" << std::endl;
		#endif // _DEBUG_LEVEL
		sf_close(f);
		return -1;
	}

	sf_write_sync(f);
	sf_close(f);

    return 0;
}


} // mag










