/*
**	Author:		Martin Schwarz
**	Name:		audioData.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "audioData.h"

namespace mag{


audioData::audioData(){
    mSampleRate = 0;
    mNumSamples = 0;
    mChannels = 0;
    mPos = 0;
}

audioData::audioData(void **addressStructure){
	if(addressStructure == NULL) return;
	fromAddressStructure(addressStructure);
}

audioData::~audioData(){
    mData.empty();
    mSampleRate = 0;
    mNumSamples = 0;
    mChannels = 0;
    mPos = 0;
}

int audioData::operator =(audioData *data){
	if(data == NULL) return -1;

    mData = data->mData;
    mSampleRate = data->mSampleRate;
    mNumSamples = data->mNumSamples;
    mChannels = data->mChannels;

	return 0;
}

void **audioData::toAddressStructure(){
	void **ads = new void*[5];

	ads[0] = &mData[0];
	ads[1] = &mSampleRate;
	ads[2] = &mNumSamples;
	ads[3] = &mChannels;
	ads[4] = &mPos;

	return ads;
}

int audioData::fromAddressStructure(void **addressStructure){
	if(addressStructure == NULL) return 0;

	mSampleRate = *(unsigned int *)addressStructure[1];
	mNumSamples = *(unsigned long int *)addressStructure[2];
	mChannels = *(unsigned short *)addressStructure[3];
	mPos = *(unsigned long int *)addressStructure[4];

	mData.clear();
	mData.insert(mData.end(), &((float *)addressStructure[0])[0], &((float *)addressStructure[0])[mNumSamples * mChannels - 1]);

	return 0;
}

} // mag













