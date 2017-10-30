#pragma once

#include <stdint.h>

using namespace std;

class RAM {
public:
	uint32_t address[805306376] = { 0 };
private:
	RAM();
	uint32_t getRAM(int address);
};

RAM mainMemory;



