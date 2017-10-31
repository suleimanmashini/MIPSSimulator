#pragma once

#include <stdint.h>

using namespace std;

class RAM {
private:
	uint32_t address[805306376] = { 0 };
public:
	RAM();
	uint32_t getRAM(const int &addressIn) const;
	uint8_t getByteRAM(const int &addressIn) const;
	void writeRAM(const int &addressIn, const uint32_t &dataIn);
	void writeRAM(const int &addressIn,const uint8_t &dataIn);
	
};





