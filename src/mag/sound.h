/*
**	Author:		Martin Schwarz
**	Name:		sound.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_SOUND
#define MAG_SOUND

#include "include.h"
#include "wavWriter.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

class sound{
public:
    sound();
    sound(std::vector<float> data, unsigned int numSamples, unsigned int sampleRate, unsigned int freq, unsigned int amplitude);
    ~sound();

    unsigned int manipulate(const char* key, const char* value);

    unsigned int writeToFile(const char* filename);

    uint8_t *genRaw8();
    uint16_t *genRaw16();
    uint32_t *genRaw32();

//private:
    std::vector<float> mData;
    unsigned int mNumSamples;
    unsigned int mSampleRate;
    unsigned int mFreq;
    unsigned int mAmplitude;
};

} // mag

#endif // MAG_SOUND
