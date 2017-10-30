#pragma once

#include <stdint.h>

using namespace std;

class RAM {
public:
	uint32_t address[805306376] = { 0 };
private:
	RAM();
	uint32_t getRAM(int addressIn);
	void writeRAM(int addressIn, uint32_t dataIn);
	void writeRAM(int addressIn, uint8_t dataIn);
	int addressToArrayInex(int addressIn);
};





