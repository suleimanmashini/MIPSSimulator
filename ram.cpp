
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

//NEED TO SORT OUT THE ENDIANNESS OF THIS*******************
void RAM::writeRAM(const int &addressIn,const uint8_t &dataIn) {
	//WRITE WITHIN A WORD ITSELF
	uint32_t temp = address[addressIn / 4];
	int shift = addressIn % 4;
}
