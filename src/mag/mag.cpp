/*
**	Author:		Martin Schwarz
**	Name:		mag.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "mag.h"

namespace mag{

mplug::pluginManager *gPlugManager = NULL;

int magInit(const char *configpath){
	gPlugManager = new mplug::pluginManager(configpath);

	return 0;
}

int magQuit(){
	//if(gPlugManager != NULL) delete gPlugManager;	//FIX THIS
	return 0;
}

mplug::pluginManager *getPluginManager(){
	return gPlugManager;
}

}












