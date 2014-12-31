#include <iostream>
#include "../pluginInterface.h"

using namespace mplug;

class testplugin : public pluginInterface{
public:
	
    virtual const char *getInfo() const{
		return "testplugin lives!\0";
	}
    virtual int command(const char *command, void *data, unsigned int lenData) const{
		return 666;
	}
};

extern "C" pluginInterface *create(){
	testplugin *tp = new testplugin();
	return tp;
}

extern "C" void destroy(pluginInterface *interface){
	delete interface;
	return;
}








