/*
**	Author:		Martin Schwarz
**	Name:		pluginManager.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef PLUGIN_MAN
#define PLUGIN_MAN

#include "include.h"
#include "pluginLoader.h"


#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{


class pluginManager{
public:
    pluginManager(const char *configPath = NULL);
    ~pluginManager();

    int loadConfig(const char *configPath = NULL);
    int loadPlugin(const char *pluginPath);

    const char *listPlugins();
    pluginInterface *getPlugin(const char *pluginName);

    int deletePlugin(const char *pluginName);

private:
    std::vector<pluginLoader *> mPlugins;
};


} // mag

#endif // PLUGIN_MAN






