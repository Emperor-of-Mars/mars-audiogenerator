/*
**	Author:		Martin Schwarz
**	Name:		writeWav.cpp
**	Project:	mars-audiogenerator
**	Compile:	g++
*/

#include "wavWriter.h"

namespace mag{


unsigned int writeToFile(const char* filename, void *data, unsigned int sampleBits, unsigned int numSamples, unsigned int sampleRate){
    unsigned int sampleBytes = sampleBits / 8;
    std::ofstream stream(filename, std::ios::binary);
	char head[44];
	strncpy(&head[0], "RIFF", 4);
	*(uint32_t*)&(head[4]) = (uint32_t)(44 + numSamples * sampleBytes - 8);
	strncpy(&head[8], "WAVE", 4);
	strncpy(&head[12], "fmt ", 4);
	*(uint32_t*)&(head[16]) = 16;
	*(uint16_t*)&(head[20]) = 1;
	*(uint16_t*)&(head[22]) = 1;
	*(uint32_t*)&(head[24]) = sampleRate;
	*(uint32_t*)&(head[28]) = (uint32_t)(sampleRate * 1 * sampleBytes / 8);
	*(uint16_t*)&(head[32]) = (uint16_t)(1 * sampleBytes / 8);
	*(uint16_t*)&(head[34]) = (uint32_t)(sampleBits);
	strncpy(&head[36], "data", 4);
	*(uint32_t*)&(head[40]) = (uint32_t)(numSamples * sampleBytes);

	#if _DEBUG_LEVEL >= 2
        std::cerr << "Writing: " << filename << " :: " << sampleBits << "bit " << numSamples << "samples " << sampleRate << "rate" << std::endl;
    #endif

    stream.write(head, 44);
    stream.write((const char *)(data), (uint32_t)(numSamples * sampleBytes));

    return 0;
}


} // mag










