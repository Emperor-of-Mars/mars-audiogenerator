/*
**	Author:		Martin Schwarz
**	Name:		pluginLoader.h
**	Project:	mars-audiogenerator
**	Compile:	g++
*/


#ifndef PLUGIN_LOADER
#define PLUGIN_LOADER

#include "include.h"


#ifndef _DEBUG_LEVEL
	#define _DEBUG_LEVEL 2
#endif // _DEBUG_LEVEL

namespace mag{


class pluginInterface{
public:
    pluginInterface();
    virtual ~pluginInterface();

    virtual const char *getInfo() const = 0;
    virtual int command(const char *command, void *data, unsigned int lenData) const = 0;
};

typedef pluginInterface *create_t();
typedef void destroy_t(pluginInterface *);

class pluginLoader{
public:
    pluginLoader(const char *path = NULL);
    ~pluginLoader();

    int load(const char *path);
    pluginInterface *create();
    int destroy(pluginInterface *instance);

private:
    void *mPlugin;
    create_t *mCreate;
    destroy_t *mDestroy;
    const char *mName;
    std::vector<pluginInterface *> mInstances;
};


} // mag

#endif // PLUGIN_LOADER






