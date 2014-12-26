/*
**	Author:		Martin Schwarz
**	Name:		mag.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "mag.h"

namespace mag{

mag::mag(){
}

mag::~mag(){
}

unsigned int mag::genSinus(float freq, float ampl, unsigned int len_ms){
    int samplecount = 44100 * len_ms / 1000;
    data.resize(samplecount);
    for(unsigned int i = 0; i < samplecount; i ++){
        data[i] = (int)(sinf(freq * ((float)i / samplecount) * 2 * M_PI) * ampl * 2147483647);
        //std::cout << data[i] << std::endl;
    }

    return 0;
}

unsigned int mag::genSound(){

    return 0;
}

unsigned int mag::writeToFile(const char* filename){
    std::ofstream stream(filename, std::ios::binary);

	char head[44];
	memset(head, 0, 44);
	strncpy(&head[0], "RIFF", 4);
	*(uint32_t*)&(head[4]) = (uint32_t)(44 + data.size() * sizeof(int) - 8);
	*(uint32_t*)&(head[4]) = 1;
	strncpy(&head[8], "WAVE", 4);
	strncpy(&head[12], "fmt ", 4);
	*(uint32_t*)&(head[16]) = 16;
	*(uint16_t*)&(head[20]) = 1;
	*(uint16_t*)&(head[22]) = 1;
	*(uint32_t*)&(head[24]) = 44100;
	*(uint32_t*)&(head[28]) = (uint32_t)(44100 * 1 * sizeof(int) / 8);
	*(uint16_t*)&(head[32]) = (uint16_t)(1 * sizeof(int) / 8);
	*(uint16_t*)&(head[34]) = (uint32_t)(sizeof(int) * 8);
	strncpy(&head[36], "data", 4);
	*(uint32_t*)&(head[40]) = (uint32_t)(data.size() * sizeof(int));

    stream.write(head, sizeof(head));
    stream.write((const char *)(&data[0]), (uint32_t)(data.size() * sizeof(int)));

    return 0;
}

}












