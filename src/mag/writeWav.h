/*
**	Author:		Martin Schwarz
**	Name:		writeWav.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_WRITE_WAV
#define MAG_WRITE_WAV

#include "include.h"


#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

class writeWav{
public:
    writeWav();
    ~writeWav();

    unsigned int writeToFile();
};

} // mag

#endif // MAG_WRITE_WAV
