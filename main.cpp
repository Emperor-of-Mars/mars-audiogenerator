#include <iostream>

#include "main.h"

using namespace std;

int main(){
    /*cout << "Plugin Loader" << endl;
    mplug::pluginLoader plug("res/plugins/plugintest.so");
    mplug::pluginInterface *pli = plug.create();
    if(pli == NULL) return 1;
    std::cout << pli->getInfo() << std::endl;
    plug.destroy(pli);*/

    cout << "Generating WAV" << endl;
    mag::sound s = mag::genSinus(44100, 500, 1000000000, 2000);
    mag::writeToFile("sound.wav", s.getSoundData());

    mag::sound snd1 = mag::readFile("sound.wav");
    mag::writeToFile("newsound.wav", snd1.getSoundData());

    mag::playAudio(snd1.getSoundData());

    /*mplug::pluginManager plm("pluginconfig.conf");
    std::cerr << plm.listPlugins();
    std::cerr << plm.createInstance("res/plugins/plugintest.so")->getInfo() << std::endl;*/

    return 0;
}
