#pragma once

#include "ram.hpp"

using namespace std;
RAM::RAM() {
	RAM newRAM;
}

uint32_t RAM::getRAM(int addressIn) {
	return address[addressIn];
}