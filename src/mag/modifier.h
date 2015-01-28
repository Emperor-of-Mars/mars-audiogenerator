/*
**	Author:		Martin Schwarz
**	Name:		modifier.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef MAG_MODIFIER
#define MAG_MODIFIER

#include "include.h"
#include "audioData.h"

#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{


class modifier{
public:
	modifier();
	modifier(const char *name, mplug::pluginManager *manager);
	~modifier();

	bool refresh(const char *name, mplug::pluginManager *manager = NULL);
	void destroy();

	void activate(bool activate);
	bool getActive();

	bool setArgument(const char *argument);
	const char *getArgumentList();

	std::shared_ptr<audioData> render(std::shared_ptr<audioData> ad);

private:
	mplug::pluginInterface *mInterface;
	mplug::pluginManager *mManager;
	bool mActive;
	std::string mInfo;
	std::string mName;
};


} // mag

#endif // MAG_MODIFIER





