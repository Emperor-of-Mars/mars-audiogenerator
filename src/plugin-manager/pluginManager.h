/*
**	Author:		Martin Schwarz
**	Name:		pluginManager.h
**	Project:	mars-pluginmanager
**	Compile:	g++
*/


#ifndef PLUGIN_MAN
#define PLUGIN_MAN

#include "include.h"
#include "pluginLoader.h"


#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mplug{


class pluginManager{
public:
    pluginManager(const char *configPath = NULL);
    ~pluginManager();

    int loadConfig(const char *configPath = NULL);
    int loadPlugin(const char *pluginPath);

    const char *listPlugins();
    pluginInterface *createInstance(const char *pluginName);
    int destroyInstance(const char *pluginName, pluginInterface *instance);

    int deletePlugin(const char *pluginName);

private:
    std::vector<pluginLoader *> mPlugins;
};


} // mplug

#endif // PLUGIN_MAN






