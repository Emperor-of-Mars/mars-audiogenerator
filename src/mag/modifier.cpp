/*
**	Author:		Martin Schwarz
**	Name:		modifier.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "modifier.h"

namespace mag{


modifier::modifier(){
	mInterface = NULL;
	mManager = NULL;
	mActive = false;
	return;
}

modifier::modifier(const char *name, mplug::pluginManager *manager){
	refresh(name, manager);
	return;
}

modifier::~modifier(){
	destroy();
	return;
}

bool modifier::refresh(const char *name, mplug::pluginManager *manager){
	if(manager != NULL){
		mName = name;
		mManager = manager;
		mInterface = mManager->createInstance(name);
		if(mInterface == NULL){
			destroy();
			return false;
		}
		mActive = true;
	}
	return true;
}

void modifier::destroy(){
	if(mInterface != NULL && mManager != NULL){
		mManager->deletePlugin(mName.c_str());
		mActive = false;
	}
	mInterface = NULL;
	mManager = NULL;
	mActive = false;
	return;
}

void modifier::activate(bool activate){
	mActive = activate;
}

bool modifier::getActive(){
	return mActive;
}

bool setArgument(const char *argument){
	return 0;
}

const char *getArgumentList(){
	return NULL;
}

std::shared_ptr<audioData> modifier::render(std::shared_ptr<audioData> ad){
	return NULL;
}


} // mag










