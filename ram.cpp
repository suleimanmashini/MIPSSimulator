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
	else if (addressIn == INPUT_IO_ADR) {
		uint32_t returnVal = 0;
		uint8_t temp;
		if (cin) {
			if (cin.eof()) {
				return 0xFFFFFFFF;
			} 
			else {
			 return(sign_extention(getchar()));
			}
		} else exit(-21);
	}
	else {
		exit(-11);
	}
}

uint8_t RAM::getByteRAM(const int &addressIn) const {
	int shift = addressIn % 4;
	int tempAddress = addressIn / 4;
	if (addressIn == INPUT_IO_ADR) {
		if (cin) {
			if (cin.eof()) {
				return 0xFF;
			}
			else {
				return (sign_extention((uint8_t)(getchar())));
			}
		}
		else exit(-21);
	}
	if (!((tempAddress >= 0x4000000 && tempAddress <= 0x4400000) || (tempAddress >= 0x8000000 && tempAddress <= 0x9000000))) {
		exit(-11);
	}
	uint32_t temp = this->getRAM(addressIn - shift);
	switch (shift) {
	case (0):
		return (temp >> 24);
	case (1):
		return ((temp >> 16) & 0xFF);
	case (2):
		return ((temp >> 8) & 0xFF);
	default:
		return (temp & 0xFF);

	}
}

void RAM::writeRAM(const int &addressIn, const uint32_t &dataIn) {
	//THERE IS NO ADDRESS ERROR CHECKING ERROR CHECKING
	int tempAddress = addressIn / 4;
	if (addressIn == OUTPUT_IO_ADR) {
		//OUTPUT MAP AND CHECK IO WORKS
		char outchar = (char) (dataIn & 0xFF);
		if (!cout) exit(-21);
		cout << outchar;
		return;
	}
	else if (addressIn == 0) {
		//EXIT WITH REGISTER $2
		exit((uint8_t)(Register[V0] & 0xFF));
	}
	else if (tempAddress >= 0x8000000 && tempAddress <= 0x9000000) {
		READWRITE_ADR[tempAddress - 0x8000000] = dataIn;
	}
	else {
		exit(-11);
	}

}

void RAM::writeByteRAM(const int &addressIn, const uint8_t &dataIn) {
	//WRITE WITHIN A WORD ITSELF
	if (addressIn == OUTPUT_IO_ADR) {
		char outchar = dataIn;
		//if IO not working then exit
		if (!cout) exit(-21);
		cout << outchar;
		return;
	}
	if (!(addressIn / 4 >= 0x8000000 && addressIn / 4 <= 0x9000000)) exit(-11);
	int shift = addressIn % 4;
	uint32_t temp = this->getRAM(addressIn - shift);
	uint32_t tempIn = dataIn;
	if (addressIn >= 0 && addressIn <= 4) {
		//EXIT WITH REGISTER $2
		exit((uint8_t) (Register[V0] & 0xFF));
	}
	//CHECKS IF ADDRESS IS I/O ELSE WRITES TO DATA

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


uint32_t RAM::sign_extention(uint8_t imm) const {
	if (imm & 0x80) {
		return (0xFFFFFF00 + imm);
	}
	else {
		return (0x00000000 + imm);
	}
}