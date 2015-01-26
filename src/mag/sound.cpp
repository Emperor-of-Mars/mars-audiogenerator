/*
**	Author:		Martin Schwarz
**	Name:		sound.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "sound.h"

namespace mag{


sound::sound(){
	mResult.reset(new audioData);
	mStatus = 0;
}

sound::sound(const char *file){
	mAudioData = mag::readFile(file);
	mResult.reset(new audioData);
	mStatus = 0;
}

sound::sound(std::shared_ptr<audioData> data){
    mAudioData = data;
	mResult.reset(new audioData);
	mStatus = 0;
}

sound::~sound(){
}

int sound::operator =(std::shared_ptr<audioData> data){
    if(data == NULL) return -1;
    mAudioData = data;
    return 0;
}

int sound::writeFile(const char *file, int format){
	render();
	return mag::writeFile(file, mResult, format);
}

int sound::readFile(const char *file){
	mAudioData = mag::readFile(file);
	if(mAudioData == NULL) return -1;
	return 0;
}

int sound::play(){
	render();
	return mag::playAudio(mResult.get());
}

std::shared_ptr<audioData> sound::getAudioData(){
	return mAudioData;
}

int sound::render(){
	if(mAudioData == NULL) return -1;
	*mResult = *mAudioData;
	return 0;
}

} // mag










