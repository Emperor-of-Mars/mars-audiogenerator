#include <iostream>
#include "../pluginInterface.h"
#include "../audioData.h"

using namespace mplug;
using namespace mag;

class sampleplugin : public pluginInterface{
public:
	
    virtual const char *getInfo() const{
		return "samplerate:value;\0";
	}
    virtual int command(const char *command, void *data, unsigned int lenData) const{
		std::string c(command);
		c = c.substr(11, c.find(';') - 11);
		int cr = atoi(c.c_str());
		std::cerr << "PLUGIN ARG: " << cr << std::endl;
		std::cerr << "PLUGIN DEBUG 01" << std::endl;
		audioData *ad = new audioData(*(void***)data);
		std::cerr << "PLUGIN DEBUG 02" << std::endl;
		
		ad->mSampleRate = cr;
		std::cerr << "PLUGIN DEBUG 03" << std::endl;
		
		//void **ptr = (void**)data;
		//*((unsigned int *)ptr[1]) = cr;
		
		*(void***)data = ad->toAddressStructure();
		std::cerr << "PLUGIN DEBUG 04" << std::endl;
		
		return 1;
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








