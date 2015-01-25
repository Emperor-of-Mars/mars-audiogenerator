/*
**	Author:		Martin Schwarz
**	Name:		audioStructure.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "audioStructure.h"

namespace mag{


audioStructure::audioStructure(){
	mStatus = 0;
}

audioStructure::~audioStructure(){
}

std::shared_ptr<audioData> audioStructure::getResult(){
	return mResult;
}


} // mag










