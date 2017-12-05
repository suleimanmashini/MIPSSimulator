#pragma once

#include <stdint.h>
//DEVELOPER NOTE: TO MAINTAIN MEMORY MAPPER I/O CONSISTENCY:
//	SIZE OF ANY I/O INTERACTION IS ALWAYS: 1 BYTE.
//	ANY I/O INTERACTION MUST BE WORD ALIGNED.
//  THE BYTE IS SIGN EXTENDED TO 32 BITS AND THE LSBYTES ARE USED

using namespace std;

class RAM {
private:
	uint32_t INSTRUCTION_ADR[4194304] = { 0 };
	uint32_t READWRITE_ADR[16777216] = { 0 };

public:
	RAM();
	uint32_t getRAM(const int &addressIn) const;
	uint8_t getByteRAM(const int &addressIn) const;
	void writeRAM(const int &addressIn, const uint32_t &dataIn);
	void writeByteRAM(const int &addressIn,const uint8_t &dataIn);
	void loadInstructions(const int &addressIn, const uint32_t &dataIn);
	uint32_t sign_extention(uint8_t imm) const;
};

