
#include "ram.hpp"
#include <iostream>

using namespace std;
RAM::RAM() {
	RAM newRAM;
}

uint32_t RAM::getRAM(const int &addressIn) const {
	int tempAddress = addressIn / 4;
	return address[tempAddress];
}

void RAM::writeRAM(const int &addressIn,const uint32_t &dataIn) {
	//THERE IS NO ADDRESS ERROR CHECKING ERROR CHECKING
	int tempAddress = addressIn / 4;
	address[tempAddress] = dataIn;
}


void RAM::writeRAM(const int &addressIn,const uint8_t &dataIn) {
	//WRITE WITHIN A WORD ITSELF
	uint32_t temp = address[addressIn / 4];
	uint32_t tempIn = dataIn;
	int shift = addressIn % 4;
	switch (shift) {
	case 0:
		//shift and return
		address[addressIn / 4] = ((temp & 0x00FFFFFF) | (tempIn << 24));
		break;
	case 1:
		address[addressIn / 4] = ((temp & 0xFF00FFFF) | (tempIn << 16));
		break;
	case 2:
		address[addressIn / 4] = ((temp & 0xFFFF00FF) | (tempIn << 8));
		break;
	case 3:
		address[addressIn / 4] = ((temp & 0xFFFF00FF) | (tempIn));
		break;
	default:
	}
}
