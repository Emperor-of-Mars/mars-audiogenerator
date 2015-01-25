/*
**	Author:		Martin Schwarz
**	Name:		audioFile.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "audioFile.h"

namespace mag{


int writeFile(const char *file, std::shared_ptr<audioData> data, int format){
	SNDFILE* f = NULL;
	SF_INFO info;

	if(data == NULL){
		#if _DEBUG_LEVEL >= 1
			std::cerr << "null pointer!" << std::endl;
		#endif // _DEBUG_LEVEL
		return -1;
	}

	info.samplerate = data->mSampleRate;
	info.channels = data->mChannels;
	info.format = format;

	if(!(f = sf_open(file, SFM_WRITE, &info))){
		#if _DEBUG_LEVEL >= 1
			std::cerr << "unable to open file!" << std::endl;
		#endif // _DEBUG_LEVEL
		sf_close(f);
		return -1;
	}

	if(sf_write_float(f, &data->mData[0], (sf_count_t)(data->mNumSamples * data->mChannels)) !=
							(sf_count_t)(data->mNumSamples * data->mChannels)){
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

std::shared_ptr<audioData> readFile(const char *file){
	SNDFILE* f = NULL;
	SF_INFO info;

	if(!(f = sf_open(file, SFM_READ, &info))){
		#if _DEBUG_LEVEL >= 1
			std::cerr << "unable to open file!" << std::endl;
		#endif // _DEBUG_LEVEL
		sf_close(f);
		return NULL;
	}

	audioData *data = new audioData;
	data->mData.resize(info.frames * info.channels);
	data->mNumSamples = info.frames;
	data->mSampleRate = info.samplerate;
	data->mChannels = info.channels;

	if(sf_read_float(f, &data->mData[0], data->mNumSamples * data->mChannels) != (sf_count_t)(data->mNumSamples * data->mChannels)){
		#if _DEBUG_LEVEL >= 1
			std::cerr << "unable to read from file!" << std::endl;
		#endif // _DEBUG_LEVEL
		sf_close(f);
		delete data;
		return NULL;
	}

	sf_close(f);

	std::shared_ptr<audioData> sp(data);

	#if _DEBUG_LEVEL >= 2
		std::cerr << "reading succesfull" << std::endl;
	#endif // _DEBUG_LEVEL


	return sp;
}


} // mag










