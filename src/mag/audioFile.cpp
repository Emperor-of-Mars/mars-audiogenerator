/*
**	Author:		Martin Schwarz
**	Name:		audioFile.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "audioFile.h"

namespace mag{


int writeToFile(const char *file, soundData *s, int format){
	SNDFILE* f = NULL;
	SF_INFO info;

	info.samplerate = s->mSampleRate;
	info.channels = s->mChannels;
	info.format = format;

	if(!(f = sf_open(file, SFM_WRITE, &info))){
		#if _DEBUG_LEVEL >= 1
			std::cerr << "unable to open file!" << std::endl;
		#endif // _DEBUG_LEVEL
		sf_close(f);
		return -1;
	}

	if(sf_write_float(f, &s->mData[0], (sf_count_t)(s->mNumSamples * s->mChannels)) !=
							(sf_count_t)(s->mNumSamples * s->mChannels)){
		#if _DEBUG_LEVEL >= 1
			std::cerr << "unable to write to file!" << std::endl;
		#endif // _DEBUG_LEVEL
		sf_close(f);
		return -1;
	}

	sf_write_sync(f);
	sf_close(f);

	#if _DEBUG_LEVEL >= 2
		std::cerr << "writing succesfull" << std::endl;
	#endif // _DEBUG_LEVEL

    return 0;
}

soundData *readFile(const char *file){
	SNDFILE* f = NULL;
	SF_INFO info;

	if(!(f = sf_open(file, SFM_READ, &info))){
		#if _DEBUG_LEVEL >= 1
			std::cerr << "unable to open file!" << std::endl;
		#endif // _DEBUG_LEVEL
		sf_close(f);
		return NULL;
	}

	soundData *s = new soundData;
	s->mData.resize(info.frames * info.channels);
	s->mNumSamples = info.frames;
	s->mSampleRate = info.samplerate;
	s->mChannels = info.channels;

	if(sf_read_float(f, &s->mData[0], s->mNumSamples * s->mChannels) != (sf_count_t)(s->mNumSamples * s->mChannels)){
		#if _DEBUG_LEVEL >= 1
			std::cerr << "unable to read from file!" << std::endl;
		#endif // _DEBUG_LEVEL
		sf_close(f);
		return NULL;
	}

	sf_close(f);

	#if _DEBUG_LEVEL >= 2
		std::cerr << "reading succesfull" << std::endl;
	#endif // _DEBUG_LEVEL


	return s;
}


} // mag










