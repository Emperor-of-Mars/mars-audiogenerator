/*
**	Author:		Martin Schwarz
**	Name:		sound.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_SOUND
#define MAG_SOUND

#include "include.h"
#include "soundData.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

class sound{
public:
    sound();
    sound(soundData *s);
    ~sound();

    int operator =(sound *s);
    int operator =(soundData *s);

	soundData *getSoundData();

private:
    soundData *mSoundData;
    unsigned long int mPosition;
    unsigned long int mBegin;
    unsigned long int mEnd;
};

} // mag

#endif // MAG_SOUND





