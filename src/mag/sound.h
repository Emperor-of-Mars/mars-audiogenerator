/*
**	Author:		Martin Schwarz
**	Name:		sound.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_SOUND
#define MAG_SOUND

#include "include.h"
#include "audioStructure.h"
#include "audioRepository.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{


class sound : public audioStructure{
public:
    sound();
    sound(const char *file);
    sound(std::shared_ptr<audioData> data);
    ~sound();

    int operator =(std::shared_ptr<audioData> data);

	virtual int writeFile(const char *file, int format = SF_FORMAT_WAV | SF_FORMAT_PCM_16);
	int readFile(const char *file);

	bool good();

	bool addModifier(const char *name, mplug::pluginManager *manager = gPlugManager);
	modifier *getModifier(const char *name);
	void removeModifier(const char *name);
	const char *listModifiers();

	virtual int play();

	std::shared_ptr<audioData> getAudioData();

private:
	virtual int render();

    std::shared_ptr<audioData> mAudioData;
    std::vector<modifier> mModifiers;

    static audioRepository *mRepo;
};

} // mag

#endif // MAG_SOUND





