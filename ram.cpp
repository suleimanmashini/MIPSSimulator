#include "data.hpp"
#include "ram.hpp"
#include <iostream>

using namespace std;

RAM mainMemory;
uint32_t Register[35] = {
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0, INSTRUCTION_START_ADR };


RAM::RAM() {
}

uint32_t RAM::getRAM(const int &addressIn) const {
	int tempAddress = addressIn / 4;
	if (tempAddress >= 0x4000000 && tempAddress <= 0x4400000) {
		return INSTRUCTION_ADR[tempAddress - 0x4000000];
		
	}
	else if (tempAddress >= 0x8000000 && tempAddress <= 0x9000000) {
		return READWRITE_ADR[tempAddress - 0x8000000];
	}
	else if (tempAddress == INPUT_IO_ADR / 4) {
		//INPUT MAP
		uint32_t returnVal = 0;
		uint8_t temp;
		for (int i = 0; i < 4; i++) {
			//if IO not working then exit
			temp = getByteRAM(OUTPUT_IO_ADR);
			returnVal = returnVal | (temp << (24 - (i * 8)));
			return returnVal;
		}
	}
	else {
		exit(-11);
	}
}

uint8_t RAM::getByteRAM(const int &addressIn) const {
	int shift = addressIn / 4;
	if (addressIn == INPUT_IO_ADR) {
		if (!cin) exit(-21);
		char temp = getchar();
		return temp;
	}
	uint32_t temp = this->getRAM(addressIn -shift);
	switch (shift) {
	case (0):
		return uint32_t(temp >> 24);
	case (1):
		return uint32_t((temp >> 16) | 0x000000FF);
	case (2):
		return uint32_t((temp >> 8) | 0x000000FF);
	default:
		return uint32_t(temp | 0x000000FF);

	}
}

void RAM::writeRAM(const int &addressIn, const uint32_t &dataIn) {
	//THERE IS NO ADDRESS ERROR CHECKING ERROR CHECKING
	int tempAddress = addressIn / 4;

	if (addressIn == 0) {
		//EXIT WITH REGISTER $2
		exit((uint8_t)(Register[V0] & 0xFF));
	}
	if (tempAddress >= 0x8000000 && tempAddress <= 0x9000000) {
		READWRITE_ADR[tempAddress - 0x8000000] = dataIn;
	}
	else if (addressIn == OUTPUT_IO_ADR) {
		//OUTPUT MAP AND CHECK IO WORKS
		uint32_t temp = dataIn;
		char outchar[4];
		outchar[0] = (temp >>= 24) & 0xFF;
		outchar[1] = (temp >>= 16) & 0xFF;
		outchar[2] = (temp >>= 8) & 0xFF;
		outchar[3] = temp & 0xFF;
		for (int i = 0; i < 4; i++) {
			//if IO not working then exit
			writeByteRAM(OUTPUT_IO_ADR, (outchar[i] << 24 - (i * 8)) & 0xFF);
		}
	}
	else {
		exit(-11);
	}

}

void RAM::writeByteRAM(const int &addressIn, const uint8_t &dataIn) {
	//WRITE WITHIN A WORD ITSELF
	int shift = addressIn % 4;
	uint32_t temp = this->getRAM(addressIn - shift);
	uint32_t tempIn = dataIn;
	if (addressIn >= 0 && addressIn <= 4) {
		//EXIT WITH REGISTER $2
		exit((uint8_t) (Register[V0] & 0xFF));
	}
	//CHECKS IF ADDRESS IS I/O ELSE WRITES TO DATA
	if (addressIn == OUTPUT_IO_ADR) {
		char outchar = dataIn;
		//if IO not working then exit
		if (!cout) exit(-21);
		cout << outchar;
		return;
	}
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

void RAM::loadInstructions(const int &addressIn, const uint32_t &dataIn) {
	//THERE IS NO ADDRESS ERROR CHECKING ERROR CHECKING
	int tempAddress = addressIn / 4;
	if (tempAddress >= 0x4000000 && tempAddress <= 0x4400000) {
		INSTRUCTION_ADR[tempAddress - 0x4000000] = dataIn;
	}
	else {
		exit(-11);
	}

}
