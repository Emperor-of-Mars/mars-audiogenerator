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

struct soundData{
    soundData();
    ~soundData();
    std::vector<float> mData;
    unsigned int mNumSamples;
    unsigned int mSampleRate;
    unsigned int mFreq;
    unsigned int mAmplitude;
};

class sound{
public:
    sound();
    sound(soundData *s);
    sound(std::vector<float> data, unsigned int numSamples, unsigned int sampleRate, unsigned int freq, unsigned int amplitude);
    sound(float *data, unsigned int numSamples, unsigned int sampleRate, unsigned int freq, unsigned int amplitude);
    ~sound();

    int operator =(const sound *s);
    int operator =(const soundData *s);

    int manipulate(const char* key, const char* value);

    int writeToFile(const char* filename);

    uint8_t *genRaw8();
    uint16_t *genRaw16();
    uint32_t *genRaw32();

private:
    soundData mSoundData;
};

} // mag

#endif // MAG_SOUND





