/*
**	Author:		Martin Schwarz
**	Name:		sound.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "sound.h"

namespace mag{


sound::sound(){
	mSoundData = NULL;
}

sound::sound(soundData *s){
    mSoundData = s;
}

sound::~sound(){
	if(mSoundData != NULL) delete mSoundData;
}

int sound::operator =(sound *s){
    if(s == 0) return -1;
    *mSoundData = *(s->mSoundData);
    return 0;
}

int sound::operator =(soundData *s){
    if(s == 0) return -1;
	delete mSoundData;
    mSoundData = s;
    return 0;
}

soundData *sound::getSoundData(){
	return mSoundData;
}


} // mag










