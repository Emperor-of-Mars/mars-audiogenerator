#include <iostream>

#include "main.h"

using namespace std;

int main(){
    cout << "Generating WAV" << endl;
    mag::sound s = mag::genSinus(44100, 500, 1000000000, 5000);
    s.writeToFile("sound.wav");

    cout << "Plugin Loader" << endl;
    mag::pluginLoader plug("src/plugins/plugintest.so");
    mag::pluginInterface *pli = plug.get();
    if(pli == NULL) return 1;
    std::cout << pli->getInfo() << std::endl;

    return 0;
}
