#include "constants.hpp"
#include "ram.hpp"
#include <iostream>

using namespace std;
RAM::RAM() {
	RAM newRAM;
}
// I NEED TO SIT DOWN AND FIX ALL THE RAM
uint32_t RAM::getRAM(const int &addressIn) const {
	int tempAddress = addressIn / 4;
	if (tempAddress == 0) {
		exit(0);
	}
	else if (tempAddress <= 0x4000000 && tempAddress >= 0x4400000) {
		return INSTRUCTION_ADR[addressIn - 0x4000000];
	}
	else if (tempAddress == 0xC000000) {
		exit(-6);
		//ENABLE IO
	}
	else if (tempAddress == 0xC000001){
		exit(-6);
		//ENABLE IO
	}
	else {
		exit(-11);
	}
}

uint8_t RAM::getByteRAM(const int &addressIn) const {
	uint32_t temp = this->getRAM(addressIn);
	int shift = addressIn / 4;
	switch (shift) {
	case (0):
		return uint32_t(temp >> 24);
	case (1):
		return uint32_t((temp >> 16) | 0x000000FF);
		break;
	case (2):
		return uint32_t((temp >> 8) | 0x000000FF);
		break;
	default:
		return uint32_t(temp | 0x000000FF);
	
	}
}

void RAM::writeRAM(const int &addressIn, const uint32_t &dataIn) {
	//THERE IS NO ADDRESS ERROR CHECKING ERROR CHECKING
	int tempAddress = addressIn / 4;
	if (tempAddress >= 0x8000000 && tempAddress <= 0x9000000) {
		READWRITE_ADR[addressIn - 0x8000000] = dataIn;
	}
	else {
		exit(-11);
	}
	
}

void RAM::writeRAM(const int &addressIn, const uint8_t &dataIn) {
	//WRITE WITHIN A WORD ITSELF
	uint32_t temp = this->getRAM(addressIn);
	uint32_t tempIn = dataIn;
	int shift = addressIn % 4;
	switch (shift) {
	case (0):
		//shift and return
		this->writeRAM(addressIn, ((temp & 0x00FFFFFF) | (tempIn << 24)));
		break;
	case (1):
		this->writeRAM(addressIn, ((temp & 0xFF00FFFF) | (tempIn << 16)));
		break;
	case (2):
		this->writeRAM(addressIn, ((temp & 0xFFFF00FF) | (tempIn << 8)));
		break;
	default:
		this->writeRAM(addressIn, ((temp & 0xFFFF00FF) | (tempIn)));
	
	}
}

RAM mainMemory;
uint32_t Register[35] = {
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0, INSTRUCTION_START_ADR };
