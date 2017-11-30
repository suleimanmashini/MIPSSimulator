//MIPS SIMULATOR
//SULEIMAN MASHINI, IONUT MOTOI, VICTOR SANCHEZS
#include "instructiondecode.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	//PROBLEMS WITH THE FILE IMPORT INTERFACE!
	if (argc < 2) exit(-12);
	ifstream inFile;
	string inBinary;
	inFile.open(argv[1], ios::binary | ios::in);
	if (inFile.is_open()) {
		char inValue[4];
		uint32_t tempInValue;
		int tempAddressImport = 0;
		// obtain file size:
		while (inFile.read(inValue, 4)) {
			cout << inValue[0] << inValue[1] << inValue[2] << inValue[3] << endl;
			//writing four chars into a single uint32 value
			tempInValue = ((((uint32_t)inValue[0]) << 24) | (((uint32_t)inValue[1]) << 16) | (((uint32_t)inValue[2]) << 8) | ((uint32_t)inValue[3]));
			mainMemory.loadInstructions(INSTRUCTION_START_ADR + tempAddressImport, tempInValue);
			tempAddressImport = tempAddressImport + 4;
		}
		inFile.close();
		if (DEBUG) cout << "FILE IN" << endl;
		//THE SIMULATOR WILL NOW RUN
		fetchInstructions();
	}
	else {
		exit(12); //EXIT IF INVALID FILE
	}
	
	return 0;
}
