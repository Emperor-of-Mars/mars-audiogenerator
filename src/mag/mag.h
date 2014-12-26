/*
**	Author:		Martin Schwarz
**	Name:		mag.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG
#define MAG

#include "include.h"

#include "wavWriter.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

class mag{
public:
    mag();
    ~mag();

    unsigned int genSinus(float freq, float ampl, unsigned int len_ms);
    unsigned int genSound();
    unsigned int writeToFile(const char* filename);

private:
    std::vector<int> data;
};

} // mag

#endif // MAG
