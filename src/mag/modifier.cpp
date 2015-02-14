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
			mActive = false;
			return false;
		}
		mActive = true;
	}
	return true;
}

void modifier::destroy(){
	if(mInterface != NULL && mManager != NULL){
		mManager->destroyInstance(mName.c_str(), mInterface);
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

const char *modifier::getName(){
	return mName.c_str();
}

const char *modifier::getInfo(){
	return mInfo.c_str();
}

bool modifier::setArgument(const char *argument){
	std::string tmp(argument);
	if(tmp[tmp.size() - 1] != ';') return -1;
	else{
		mArguments.append(tmp);
	}
	return 0;
}

const char *modifier::getArgumentList(){
	return mArguments.c_str();
}

std::shared_ptr<audioData> modifier::render(std::shared_ptr<audioData> ad){
	return NULL;
}

int modifier::calculate(void *data, unsigned int lenData){
	if(mInterface == NULL) return -1;
	return mInterface->command(mArguments.c_str(), data, lenData);
}


} // mag










