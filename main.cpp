//MIPS SIMULATOR
//SULEIMAN MASHINI, IONUT MOTOI, VICTOR SANCHEZS

#include "data.hpp"
#include "instructionDecode.hpp"
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
	if (inFile.is_open()) {
		char inValue[4];
		uint32_t tempInValue = INSTRUCTION_START_ADR;
		int tempAddressImport = 0;
		// obtain file size:
		while (!inFile.eof()) {
			inFile.read(inValue, 4);
			//writing four chars into a single uint32 value
			tempInValue = (((((uint32_t)inValue[0]) << 24) | ((uint32_t)inValue[1]) << 16) | (((uint32_t)inValue[2]) << 8) | ((uint32_t)inValue[3]));
			mainMemory.writeRAM(tempAddressImport, tempInValue);
			tempAddressImport = tempAddressImport + 4;
		}
		inFile.close();
		//THE SIMULATOR WILL NOW RUN
		fetchIntstructions();
	}
	else {
		cout << "Invalid File";
		exit(12); //EXIT IF INVALID FILE
	}
	return 0;
}
