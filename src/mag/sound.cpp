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
	mStatus &= !audioRenderCurrent;
	mStatus = 0;
}

sound::sound(const char *file){
	mAudioData = mag::readFile(file);
	mResult.reset(new audioData);
	mStatus &= !audioRenderCurrent;
	mStatus = 0;
}

sound::sound(std::shared_ptr<audioData> data){
    mAudioData = data;
	mResult.reset(new audioData);
	mStatus &= !audioRenderCurrent;
	mStatus = 0;
}

sound::~sound(){
}

int sound::operator =(std::shared_ptr<audioData> data){
    if(data == NULL) return -1;
    mAudioData = data;
	mStatus &= !audioRenderCurrent;
    return 0;
}

int sound::writeFile(const char *file, int format){
	render();
	return mag::writeFile(file, mResult, format);
}

int sound::readFile(const char *file){
	mAudioData = mag::readFile(file);
	mStatus &= !audioRenderCurrent;
	if(mAudioData == NULL) return -1;
	return 0;
}

bool sound::good(){
	if(mAudioData == NULL) return false;
	return true;
}

bool sound::addModifier(const char *name, mplug::pluginManager manager){
	//implement this!
	mStatus &= !audioRenderCurrent;
	return false;
}

void sound::removeModifier(const char *name){
	//implement this!
	mStatus &= !audioRenderCurrent;
	return;
}

const char *sound::listModifiers(){
	//implement this!
	return NULL;
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
	//std::cerr << "RENDER: " << mStatus << " " << (mStatus & audioRenderCurrent) << std::endl;
	if((mStatus & audioRenderCurrent) != 0) return 0;
	//std::cerr << "RENDER IN PROGRESS" << std::endl;

	*mResult = *mAudioData;
	for(unsigned int i = 0; i < mModifiers.size(); i++){
		if(mModifiers[i].getActive() == true){
			void** data = mResult->toAddressStructure();
			if(mModifiers[i].calculate(&data, 0) == 1){
				mResult->fromAddressStructure((void**)data);
			}
		}
	}
	mStatus |= audioRenderCurrent;
	return 0;
}

} // mag










