#pragma once

#include "instructionDecode.hpp"
#include "data.hpp"

using namespace std;
//why do you have global variables? you should move them to the revelant functions
//this will free space up in the heap... 

uint32_t address = INSTRUCTION_START_ADR;
uint32_t instr;
int opcode;
void fetchIntstrucions() {
	

	do {
		instr = mainMemory.getRAM(address);
		//changed to +4 not 32, youre incrementing by bytes not bits
		address += 4;

		opcode = instr;
		opcode >> 26;

		switch (opcode) {
		case 0:
			decodeRType();
			break;

		}
	} while (instr != 0);
}

// Decodes the funct of the R-Type instruction
void decodeRType() {
	//why are you left shifting then right shifting? isnt that redundant?
	//why isnt instr just passed as an argument for function?
	int funct = instr;
	funct << 26;
	funct >> 26;

	switch (funct) {
	case 0b000000:
		// sll
		break;
	case 0b000010:
		// srl
		break;
	case 0b000011:
		// sra
		break;
	case 0b000100:
		// sllv
		break;
	case 0b000110:
		// srlv
		break;
	case 0b000111:
		// srav
		break;
	case 0b001000:
		// jr
		break;
	case 0b001001:
		// jalr
		break;
	case 0b010000:
		// mfhi
		break;
	case 0b010001:
		// mthi
		break;
	case 0b010010:
		// mflo
		break;
	case 0b010011:
		// mtlo
		break;
	case 0b011000:
		// mult
		break;
	case 0b011001:
		// multu
		break;
	case 0b011010:
		// div
		break;
	case 0b011011:
		// divu
		break;
	case 0b100000:
		// add
		break;
	case 0b100001:
		// addu
		break;
	case 0b100010:
		// sub
		break;
	case 0b100011:
		// subu
		break;
	case 0b100100:
		// and
		break;
	case 0b100101:
		// or
		break;
	case 0b100110:
		// xor
		break;
	case 0b100111:
		// nor
		break;
	case 0b101010:
		// slt
		break;
	case 0b101011:
		// sltu
		break;
	}

}