#include <iostream>

class pluginInterface{
public:
    pluginInterface(){}
    virtual ~pluginInterface(){}

    virtual const char *getInfo() const = 0;
    virtual int command(const char *command, void *data, unsigned int lenData) const = 0;
};

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








