#include <iostream>
#include "../pluginInterface.h"

using namespace mplug;

struct audioData{
    audioData();
    audioData(void **addressStructure);
    ~audioData();

    int operator =(audioData *data);

    void **toAddressStructure();
    int fromAddressStructure(void **addressStructure);

    std::vector<float> mData;

    unsigned int mSampleRate;
    unsigned long int mNumSamples;
    unsigned short mChannels;

    unsigned long int mPos;
};

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



class sampleplugin : public pluginInterface{
public:
	
    virtual const char *getInfo() const{
		return "samplerate:value;\0";
	}
    virtual int command(const char *command, void *data, unsigned int lenData) const{
		std::string c(command);
		c = c.substr(11, c.find(';') - 11);
		int cr = atoi(c.c_str());
		std::cerr << "PLUGIN ARG: " << c << " " << cr << std::endl;
		std::cerr << "PLUGIN DEBUG 01" << std::endl;
		audioData *ad = new audioData((void**)data);
		std::cerr << "PLUGIN DEBUG 02" << std::endl;
		
		ad->mSampleRate = 20000;
		std::cerr << "PLUGIN DEBUG 03" << std::endl;
		void **ptr = (void**)data;
		*((unsigned int *)ptr[1]) = cr;
		
		data = ad->toAddressStructure();
		std::cerr << "PLUGIN DEBUG 04" << std::endl;
		
		return cr;
	}
};

extern "C" pluginInterface *create(){
	sampleplugin *tp = new sampleplugin();
	return tp;
}

extern "C" void destroy(pluginInterface *interface){
	delete (sampleplugin *)interface;
	return;
}








