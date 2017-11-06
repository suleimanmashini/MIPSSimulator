//MIPS SIMULATOR
//SULEIMAN MASHINI, IONUT MOTOI, VICTOR SANCHEZS

#include "data.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	
	ifstream inFile;
	string inBinary;
	cout << "Please input the binary file name" << endl;
	cin >> inBinary;
	inFile.open(inBinary.c_str(), ios::binary);
	if (!inFile.is_open()) {
		cout << "Invalid File";
		exit (12); //EXIT IF INVALID FILE
	}
	else {
		
		char inValue[4];
		uint32_t tempInValue = 0;
		int tempAddressImport = 0;
		// obtain file size:
		while (!inFile.eof()) {
			inFile.read(inValue, 4);
			tempAddressImport = 0;
			tempInValue = (((((uint32_t)inValue[0]) << 24) | ((uint32_t)inValue[1]) << 16) | (((uint32_t)inValue[2]) << 8) | ((uint32_t)inValue[3]) );
			mainMemory.writeRAM(INSTRUCTION_START_ADR + tempAddressImport, tempInValue);
		}
	}
	return 0;
}
