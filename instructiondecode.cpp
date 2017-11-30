#include "instructiondecode.hpp"

using namespace std;

void fetchInstructions() {
	while (1) {
		decodeInstructions;
	}
}

void decodeInstructions(){

	uint32_t instr = mainMemory.getRAM(Register[PC]);
	uint8_t opcode;

	if (Register[PC] <= (INSTRUCTION_START_ADR + 0x1000000)) {
		instr = mainMemory.getRAM(Register[PC]);

		if (instr == 0) nop();

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
	else exit(-11);
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
		sll(rd, rt, shamt);
		break;
	case 0b000010:
		srl(rd, rt, shamt);
		break;
	case 0b000011:
		sra(rd, rt, shamt);
		break;
	case 0b000100:
		sllv(rd, rs, rt);
		break;
	case 0b000110:
		srlv(rd, rt, rs);
		break;
	case 0b000111:
		srav(rd, rt, rs);
		break;
	case 0b001000:
		jr(rs);
		break;
	case 0b001001:
		jalr(rd, rs);
		break;
	case 0b010000:
		mfhi(rd);
		break;
	case 0b010001:
		mthi(rs);
		break;
	case 0b010010:
		mflo(rd);
		break;
	case 0b010011:
		mtlo(rs);
		break;
	case 0b011000:
		mult(rs, rt);
		break;
	case 0b011001:
		multu(rs, rt);
		break;
	case 0b011010:
		div(rs, rt);
		break;
	case 0b011011:
		divu(rs, rt);
		break;
	case 0b100000:
		add(rd, rs, rt);
		break;
	case 0b100001:
		addu(rd, rs, rt);
		break;
	case 0b100010:
		sub(rd, rt, rs);
		break;
	case 0b100011:
		subu(rd, rt, rs);
		break;
	case 0b100100:
		M_and(rd, rt, rs);
		break;
	case 0b100101:
		M_or(rd, rs, rt);
		break;
	case 0b100110:
		M_xor(rd, rs, rt);
		break;
	case 0b100111:
		M_nor(rd, rs, rt);
		break;
	case 0b101010:
		slt(rd, rs, rt);
		break;
	case 0b101011:
		sltu(rd, rs, rt);
		break;
	default:
		exit(-12);
	}
}

void decodeIType(uint32_t instr) {
	// Extracts the fields
	uint8_t opcode = instr >> 26;

	uint8_t rs = (instr >> 21) & 0x0000001F;

	uint8_t rt = (instr >> 16) & 0x0000001F;

	uint16_t imm = instr & 0x0000FFFF;

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
		lui(rt, imm);
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
		beq(rs, rt, imm);
		break;
	case 0b000001:
		// bgez, bgezal, bltz, bltzal
		switch (rt) {
		case 0b00001:
			bgez(rs, imm);
			break;
		case 0b10001:
			bgezal(rs, imm);
			break;
		case 0b00000:
			bltz(rs, imm);
			break;
		case 0b10000 :
			bltzal(rs, imm);
			break;
		}
		break;
	case 0b000111:
		// bgtz
		bgtz(rs, imm);
		break;
	case 0b000110:
		// blez
		blez(rs, imm);
		break;
	case 0b000101:
		// bne
		bne(rs, rt, imm);
		break;
	case 0b100000:
		// lb
		lb(rt, rs, imm);
		break;
	case 0b100100:
		// lbu
		lbu(rt, rs, imm);
		break;
	case 0b100001:
		lh(rt, rs, imm);
		break;
	case 0b100101:
		// lhu
		lhu(rt, rs, imm);
		break;
	case 0b100011:
		// lw
		lw(rs, rt, imm);
		break;
	case 0b101000:
		// sb
		sb(rt, rs, imm);
		break;
	case 0b101001:
		// sh
		sh(rt, rs, imm);
		break;
	case 0b101011:
		// sw
		sw(rt, rs, imm);
		break;
	default:
		exit(-12);
	}
}

void decodeJType(uint32_t instr) {
	// Extracts the fields
	uint8_t opcode = instr >> 26;
	uint32_t target = instr << 6;
	target >>= 4; // right shift only by 4 (and not 6) because the 
				  // j instruction multiplies the target by 4

	// Decodes the op field
	if (opcode == 0b000010) j(target);
	else jal(target);
}