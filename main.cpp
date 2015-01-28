#include <iostream>

#include "main.h"

using namespace std;

int main(){
    mplug::pluginManager plm("pluginconfig.conf");
    std::cerr << plm.listPlugins();
    std::cerr << plm.createInstance("res/plugins/plugintest.so")->getInfo() << std::endl;

    mag::sound s = mag::genSinus(44100, 500, 2134);
    s.writeFile("sound.wav");

    mag::sound snd("sound.wav");

	void** data = snd.getAudioData()->toAddressStructure();
	plm.createInstance("res/plugins/sampleplugin.so")->command("samplerate:25000;", &data, 1000);

    snd.getAudioData()->fromAddressStructure((void**)data);

    snd.play();
    snd.writeFile("newsound.wav");

    return 0;
}
