#include <iostream>

#include "main.h"

using namespace std;

int main(){
    cout << "Generating WAV" << endl;
    mag::mag m;
    m.genSinus(500, 1, 10000);
    cout << "writing file" << endl;
    m.writeToFile("sinus.wav");
    cout << "finished" << endl;
    return 0;
}
