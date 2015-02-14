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
	if(configPath == NULL) return -1;

	std::ifstream conf(configPath);
	if(!conf.good()) return -2;

	std::string input, dir;
	while(std::getline(conf, input)){
		while(input.size() > 0 && input[0] == ' ') input.erase(input.begin());
		if(input.size() > 0 && input[0] == '#') continue;
		else if(input.size() > 12 && input.substr(0, 12) == "plugin:load="){
			loadPlugin((dir + input.substr(12, input.size())).c_str());
		}
		else if(input.size() > 14 && input.substr(0, 14) == "plugin:setdir="){
			dir = input.substr(14, input.size());
		}
		else if(input.size() > 15 && input.substr(0, 15) == "plugin:loaddir="){
			//std::string loaddir = input.substr(15, input.size());
			//load a whole directory
		}
		else{
			//nothing
		}

		if(dir.size() > 0 && dir[dir.size() - 1] != '/') dir = dir + "/";

	}
    return 0;
}

int pluginManager::loadPlugin(const char *pluginPath){
	if(pluginPath == NULL) return -1;

	pluginLoader *pl = new pluginLoader(pluginPath);
	if(pl->good()) mPlugins.push_back(pl);
	else delete pl;

    return 0;
}

const char *pluginManager::listPlugins(){
	std::string *pluglist = new std::string;
    for(unsigned int i = 0; i < mPlugins.size(); i++){
	    pluglist->append(mPlugins[i]->getName());
	    pluglist->append("\n");
    }
    return pluglist->c_str();
}

pluginInterface *pluginManager::createInstance(const char *pluginName){
	if(pluginName == NULL) return NULL;
    for(unsigned int i = 0; i < mPlugins.size(); i++){
	    if(std::string(mPlugins[i]->getName()) == pluginName) return mPlugins[i]->create();
    }
    return NULL;
}

int pluginManager::destroyInstance(const char *pluginName, pluginInterface *instance){
	if(pluginName == NULL) return -1;
    for(unsigned int i = 0; i < mPlugins.size(); i++){
	    if(std::string(mPlugins[i]->getName()) == pluginName) return mPlugins[i]->destroy(instance);
    }
	return 0;
}

int pluginManager::deletePlugin(const char *pluginName){
	if(pluginName == NULL) return -1;
    for(unsigned int i = 0; i < mPlugins.size(); i++){
	    if(std::string(mPlugins[i]->getName()) == pluginName == 0){
			mPlugins.erase(mPlugins.begin() + i);
	    }
    }
    return 0;
}


} // mplug










