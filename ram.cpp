#pragma once

#include "ram.hpp"
#include <iostream>

using namespace std;
RAM::RAM() {
	RAM newRAM;
}

uint32_t RAM::getRAM(const int &addressIn) const {
	int tempAddress = addressIn / 4;
	if (tempAddress < 268435456) {
		return partition1[addressIn];
	}
	else if (tempAddress < 268435456 * 2) {
		return partition2[addressIn - 268435456];
	}
	else if (tempAddress < 268435456 * 3) {
		return partition3[addressIn - (268435456 * 2)];
	}
	else {
		return partition4[addressIn - (268435456 * 3)];
	}
}

uint8_t RAM::getByteRAM(const int &addressIn) const {
	uint32_t temp = this->getRAM(addressIn);
	int shift = addressIn / 4;
	switch (shift) {
	case 0:
		return uint32_t(temp >> 24);
	case 1:
		return uint32_t((temp >> 16) | 0x000000FF);
		break;
	case 2:
		return uint32_t((temp >> 8) | 0x000000FF);
		break;
	case 3:
		return uint32_t(temp | 0x000000FF);
	default:
	}
}

void RAM::writeRAM(const int &addressIn, const uint32_t &dataIn) {
	//THERE IS NO ADDRESS ERROR CHECKING ERROR CHECKING
	int tempAddress = addressIn / 4;
	if (tempAddress < 268435456) {
		partition1[addressIn] = dataIn;
	}
	else if (tempAddress < 268435456 * 2) {
		partition2[addressIn - 268435456] = dataIn;
	}
	else if (tempAddress < 268435456 * 3) {
		partition3[addressIn - (268435456 * 2)] = dataIn;
	}
	else {
		partition4[addressIn - (268435456 * 3)] = dataIn;
	}
	
}


void RAM::writeRAM(const int &addressIn, const uint8_t &dataIn) {
	//WRITE WITHIN A WORD ITSELF
	uint32_t temp = this->getRAM(addressIn);
	uint32_t tempIn = dataIn;
	int shift = addressIn % 4;
	switch (shift) {
	case 0:
		//shift and return
		this->writeRAM(addressIn, ((temp & 0x00FFFFFF) | (tempIn << 24)));
		break;
	case 1:
		this->writeRAM(addressIn, ((temp & 0xFF00FFFF) | (tempIn << 16)));
		break;
	case 2:
		this->writeRAM(addressIn, ((temp & 0xFFFF00FF) | (tempIn << 8)));
		break;
	case 3:
		this->writeRAM(addressIn, ((temp & 0xFFFF00FF) | (tempIn)));
	default:
	}
}
