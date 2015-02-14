#include <iostream>

#include "main.h"

using namespace std;

int main(){
	mag::magInit("pluginconfig.conf");
	mplug::pluginManager *plm = mag::getPluginManager();
    std::cerr << plm->listPlugins();

	mplug::pluginInterface *test = plm->createInstance("res/plugins/plugintest.so");
	std::cerr << test->getInfo() << std::endl;

    mag::sound s = mag::genSinus(44100, 500, 2134);
    s.writeFile("sound.wav");

    mag::sound snd("sound.wav");
	if(!snd.good()) return 0;

    std::cerr << "DEBUG 01" << std::endl;
    snd.addModifier("res/plugins/sampleplugin.so", plm);
    std::cerr << "DEBUG 02" << std::endl;
    snd.getModifier("res/plugins/sampleplugin.so")->setArgument("samplerate:25000;");
    snd.listModifiers();

    snd.play();
    snd.writeFile("newsound.wav");

	mag::magQuit();
	std::cerr << "END" << std::endl;
	return 0;
}













