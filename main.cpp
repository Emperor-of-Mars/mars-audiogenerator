#include <iostream>

#include "main.h"

using namespace std;

int main(){
    cout << "Plugin Loader" << endl;
    mplug::pluginLoader plug("res/plugins/plugintest.so");
    mplug::pluginInterface *pli = plug.create();
    if(pli == NULL) return 1;
    std::cout << pli->getInfo() << std::endl;
    plug.destroy(pli);

    cout << "Generating WAV" << endl;
    mag::sound s = mag::genSinus(44100, 500, 1000000000, 5000);
    s.writeToFile("sound.wav");

    return 0;
}
