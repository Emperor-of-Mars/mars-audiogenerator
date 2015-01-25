#include <iostream>

#include "main.h"

using namespace std;

int main(){
    mag::sound s = mag::genSinus(44100, 500, 1000000000, 2000);
    s.writeFile("sound.wav");

    mag::sound snd("sound.wav");
    //snd.play();
    snd.writeFile("newsound.wav");

    mplug::pluginManager plm("pluginconfig.conf");
    std::cerr << plm.listPlugins();
    std::cerr << plm.createInstance("res/plugins/plugintest.so")->getInfo() << std::endl;

    return 0;
}
