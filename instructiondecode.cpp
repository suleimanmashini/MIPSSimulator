#pragma once

#include "instructionDecode.hpp"
#include "data.hpp"

using namespace std;

void fetchIntstructions() {
	uint32_t address = INSTRUCTION_START_ADR;
	uint32_t instr = mainMemory.getRAM(address);
	uint8_t opcode;

	while (instr != 0 && address <= (INSTRUCTION_START_ADR + 0x1000000)) {
		instr = mainMemory.getRAM(address);
		address += 4;

		opcode = instr >> 26;

		switch (opcode) {
		case 0:
			decodeRType(instr);
			break;
		case 0b000010:
		case 0b000011:
			decodeJType(instr);
			break;
		default:
			decodeIType(instr);
		}
	}
}

// Decodes the funct of the R-Type instruction
void decodeRType(uint32_t instr) {
	// Extracts the fields
	uint8_t rs = instr << 6;
	rs >>= 27;

	uint8_t rt = instr << 11;
	rt >>= 27;

	uint8_t rd = instr << 16;
	rd >>= 27;

	uint8_t shamt = instr << 21;
	shamt >>= 27;

	uint8_t funct = instr << 26;
	funct >>= 26;

	// Decodes the funct field
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

void decodeIType(uint32_t instr) {
	// Extracts the fields
	uint8_t opcode = instr >> 26;

	uint8_t rs = instr << 6;
	rs >>= 27;

	uint8_t rt = instr << 11;
	rt >>= 27;

	uint16_t const_addr = instr << 16;
	const_addr >>= 16;

	// Decodes the opcode field
	switch (opcode) {
	case 0b001000:
		// addi
		break;
	case 0b001001:
		// addiu
		break;
	case 0b001100:
		// andi
		break;
	case 0b001111:
		// lui
		break;
	case 0b001101:
		// ori
		break;
	case 0b001010:
		// slti
		break;
	case 0b001011:
		// sltiu
		break;
	case 0b001110:
		// xori
	case 0b000100:
		// beq
		break;
	case 0b000001:
		// bgez, bgezal, bltz, bltzal
		break;
	case 0b000111:
		// bgtz
		break;
	case 0b000110:
		// blez
		break;
	case 0b000101:
		// bne
		break;
	case 0b100000:
		// lb
		break;
	case 0b100100:
		// lbu
		break;
	case 0b100001:
		// lh
		break;
	case 0b100101:
		// lhu
		break;
	case 0b100011:
		// lw
		break;
	case 0b101000:
		// sb
		break;
	case 0b101001:
		// sh
		break;
	case 0b101011:
		// sw
		break;
	}
}

void decodeJType(uint32_t instr) {
	// Extracts the fields
	uint8_t opcode = instr >> 26;
	uint32_t target = instr << 6;
	target >>= 6;

	// Decodes the op field
	if (opcode == 0b000010) {} // j
	else {} // jal
}