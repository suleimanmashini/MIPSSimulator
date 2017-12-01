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
		unsigned char inValue[4];
		uint32_t tempInValue;
		int tempAddressImport = 0;
		// obtain file size:
		while (inFile.read(reinterpret_cast <char*> (&inValue), sizeof(uint32_t))) {
			//writing four chars into a single uint32 value
			tempInValue = (inValue[0] << 24) + (inValue[1] << 16) + (inValue[2] << 8) + (inValue[3]);
			
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
