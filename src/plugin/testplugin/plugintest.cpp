#include <iostream>
#include "../pluginInterface.h"

class testplugin : public mag::pluginInterface{
public:
	
    virtual const char *getInfo() const{
		return "testplugin lives!\0";
	}
    virtual int command(const char *command, void *data, unsigned int lenData) const{
		return 666;
	}
};

extern "C" mag::pluginInterface *create(){
	testplugin *tp = new testplugin();
	return tp;
}

extern "C" void destroy(mag::pluginInterface *interface){
	delete interface;
	return;
}








