#include <iostream>

#include "main.h"

using namespace std;

int main(){
    cout << "Generating WAV" << endl;
    mag::sound s = mag::genSinus(44100, 500, 1000000000, 5000);
    s.writeToFile("sound.wav");
    return 0;
}
