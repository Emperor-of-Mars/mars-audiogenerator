/*
**	Author:		Martin Schwarz
**	Name:		pluginInterface.h
**	Project:	mars-pluginmanager
**	Compile:	g++
*/


#ifndef PLUGIN_INTERFACE
#define PLUGIN_INTERFACE

#include "include.h"


#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mplug{


class pluginInterface{
public:
    pluginInterface(){};
    virtual ~pluginInterface(){};

    virtual const char *getInfo() const = 0;
    virtual int command(const char *command, void *data, unsigned int lenData) const = 0;
};

typedef pluginInterface *create_t();
typedef void destroy_t(pluginInterface *);


} // mplug

#endif // PLUGIN_INTERFACE






