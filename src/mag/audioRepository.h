/*
**	Author:		Martin Schwarz
**	Name:		audioRepository.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_AUDIOREPOSITORY
#define MAG_AUDIOREPOSITORY

#include "include.h"
#include "audioData.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{

class audioRepository{
public:
    audioRepository();
    ~audioRepository();

	int add(audioData *data);
	int remove(audioData *adress);

private:
    std::vector<audioData *> mData;
};

} // mag

#endif // MAG_AUDIOREPOSITORY





