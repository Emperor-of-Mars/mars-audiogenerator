/*
**	Author:		Martin Schwarz
**	Name:		pluginLoader.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "pluginLoader.h"

namespace mag{


pluginInterface::pluginInterface(){
}

pluginInterface::~pluginInterface(){
}

pluginLoader::pluginLoader(const char *path){
    mPlugin = NULL;
    mPluginInterface = NULL;
    mCreate = NULL;
    mDestroy = NULL;
    mName = NULL;
    if(path != NULL) load(path);
}

pluginLoader::~pluginLoader(){
    destroy();

    if(mPlugin != NULL && mDestroy != NULL){
        mDestroy(mPluginInterface);
        //delete mPlugin too
    }
    delete [] mName;
    mPlugin = NULL;
    mPluginInterface = NULL;
    mCreate = NULL;
    mDestroy = NULL;
    mName = NULL;
}

int pluginLoader::load(const char *path){
    if(path == NULL){
        #if _DEBUG_LEVEL >= 1
            std::cerr << "plugin path is NULL!" << std::endl;
        #endif
        return -1;
    }

    if(mPlugin != NULL){
        #if _DEBUG_LEVEL >= 1
            std::cerr << "plugin is already loaded!" << std::endl;
        #endif
        return -1;
    }

    mPlugin = dlopen(path, RTLD_LAZY);
    if(!mPlugin){
        #if _DEBUG_LEVEL >= 1
            std::cerr << "loading plugin: " << path << " failed! " << dlerror() << std::endl;
        #endif
        return -2;
    }
    dlerror();

    mCreate = (create_t *)dlsym(mPlugin, "create");
    if(!mCreate){
        #if _DEBUG_LEVEL >= 1
            std::cerr << "loading createfunction from: " << path << " failed! " << dlerror() << std::endl;
        #endif
        return -2;
    }
    dlerror();

    mDestroy = (destroy_t *)dlsym(mPlugin, "destroy");
    if(!mDestroy){
        #if _DEBUG_LEVEL >= 1
            std::cerr << "loading destroyfunction from: " << path << " failed! " << dlerror() << std::endl;
        #endif
        return -2;
    }
    dlerror();

    mPluginInterface = mCreate();
    return 0;
}

pluginInterface *pluginLoader::get(){
    return mPluginInterface;
}

int pluginLoader::destroy(){
    if(mPlugin == NULL || mDestroy == NULL){
        #if _DEBUG_LEVEL >= 1
            std::cerr << "plugin not loaded!" << std::endl;
        #endif
        return -1;
    }
    mDestroy(mPluginInterface);
    dlclose(mPlugin);

    if(mName != NULL) delete [] mName;

    mPlugin = NULL;
    mPluginInterface = NULL;
    mCreate = NULL;
    mDestroy = NULL;
    mName = NULL;
    return 0;
}


} // mag










