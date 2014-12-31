/*
**	Author:		Martin Schwarz
**	Name:		pluginManager.cpp
**	Project:	mars-pluginmanager
**	Compile:	g++
*/

#include "pluginManager.h"

namespace mplug{


pluginManager::pluginManager(const char *configPath){
    if(configPath != NULL) loadConfig(configPath);
}

pluginManager::~pluginManager(){
    mPlugins.empty();
}

int pluginManager::loadConfig(const char *configPath){
    return 0;
}

int pluginManager::loadPlugin(const char *pluginPath){
    return 0;
}

const char *pluginManager::listPlugins(){
    return NULL;
}

pluginInterface *pluginManager::getPlugin(const char *pluginName){
    return NULL;
}

int pluginManager::deletePlugin(const char *pluginName){
    return 0;
}


} // mplug










