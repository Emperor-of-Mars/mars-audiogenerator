/*
**	Author:		Martin Schwarz
**	Name:		sound.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "sound.h"

namespace mag{


sound::sound(){
	mAudioData = NULL;
	mStatus = 0;
}

sound::sound(const char *file){
	mAudioData = mag::readFile(file);
	mStatus = 0;
}

sound::sound(audioData *s){
    mAudioData = s;
	mStatus = 0;
}

sound::~sound(){
	if(mAudioData != NULL) delete mAudioData;
}

int sound::operator =(audioData *s){
    if(s == 0) return -1;
	if(mAudioData != NULL) delete mAudioData;
    mAudioData = s;
    return 0;
}

int sound::readFile(const char *file){
	mAudioData = mag::readFile(file);
	if(mAudioData == NULL) return -1;
	return 0;
}

int sound::writeToFile(const char *file, int format){
	return mag::writeToFile(file, mAudioData, format);
}

int sound::play(){
	return mag::playAudio(mAudioData);
}

audioData *sound::getAudioData(){
	return mAudioData;
}


} // mag










