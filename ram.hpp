#pragma once

#include <stdint.h>

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
};

RAM::RAM() {
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
	else if (tempAddress == INPUT_IO_ADR / 4) {
		//INPUT MAP
		exit(-6);
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
	else if (tempAddress == OUTPUT_IO_ADR / 4) {
		//OUTPUT MAP AND CHECK IO WORKS
		uint32_t temp = dataIn;
		char outchar[4];
		int i = 0;
		outchar [0]= (temp >>= 24) & 0xFF;
		outchar [1] = (temp >>= 16) & 0xFF;
		outchar [2] = (temp >>= 8) & 0xFF;
		outchar [3] = temp & 0xFF;
		while (i < 4) {
			//if IO not working then exit
			if (cout) exit(-21);
			cout << outchar[i];
			i++;
		}
	
	}
	else {
		exit(-11);
	}

}

void RAM::writeByteRAM(const int &addressIn, const uint8_t &dataIn) {
	//WRITE WITHIN A WORD ITSELF
	uint32_t temp = this->getRAM(addressIn);
	uint32_t tempIn = dataIn;
	int shift = addressIn % 4;
	//CHECKS IF ADDRESS IS I/O ELSE WRITES TO DATA
	if (addressIn == OUTPUT_IO_ADR / 4) {
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




