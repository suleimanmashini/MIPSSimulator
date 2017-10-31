//MIPS SIMULATOR
//SULEIMAN MASHINI, IONUT MOTOI, VICTOR SANCHEZS

#include "data.hpp"
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	string inBinary;
	long lSize;
	cout << "Please input the binary file name" << endl;
	cin >> inBinary;
	FILE * pFile;
	pFile= fopen(inBinary.c_str(), "r");
	if (pFile == NULL) {
		cout << "Invalid File";
		exit (12); //EXIT IF INVALID FILE
	}
	else {
		int count = 0;
		uint32_t* tempIn;
		tempIn = new uint32_t;
		// obtain file size:
		while (!feof(pFile)) {
			fread(tempIn, 4, lSize, pFile);
			mainMemory.writeRAM(INSTRUCTION_START_ADR + count, *tempIn);
			count += 4;
		}
	}
	return 0;
}