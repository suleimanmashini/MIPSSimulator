
#include "ram.hpp"
#include <iostream>

using namespace std;
RAM::RAM() {
	RAM newRAM;
}

uint32_t RAM::getRAM(int addressIn) {
	return address[addressIn];
}

void RAM::writeRAM(int addressIn, uint32_t dataIn) {
	//THERE IS NO ADDRESS ERROR CHECKING ERROR CHECKING
}


void RAM::writeRAM(int addressIn, uint8_t dataIn) {

}
