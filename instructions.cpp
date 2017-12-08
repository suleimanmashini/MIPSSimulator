#include "instructions.hpp"
#include "instructiondecode.hpp"

using namespace std;
//shift left logicals
void sll(uint8_t rd, uint8_t rt, uint8_t shamt){
	if (DEBUG) cout << "sll" << endl;
    Register[rd] = Register[rt] << shamt;
    PC_advance(default_advance);
}

//shift right logical
void srl(uint8_t rd, uint8_t rt, uint8_t shamt){
	if (DEBUG) cout << "srl" << endl;
    Register[rd] = Register[rt] >> shamt;
    Register[rd] & (32 >> shamt);
    PC_advance(default_advance);
}

//shift right arithmetic, default right shift c++
void sra(uint8_t rd, uint8_t rt, uint8_t shamt){
	if (DEBUG) cout << "sra" << endl;
	if (((Register[rt] & 0x80000000) >> 31) != 0) {
		Register[rd] = Register[rt] >> shamt;
		Register[rd] = Register[rd] + (0xFFFFFFFF << (32 - shamt));
	}
	else {
		Register[rd] = Register[rt] >> shamt;
	}
    
    PC_advance(default_advance);
}

//shift left logical variable
void sllv(uint8_t rd, uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "sllv" << endl;
    Register[rd] = Register[rt] << Register[rs];
    PC_advance(default_advance);
}

//shift right logical variable
void srlv(uint8_t rd, uint8_t rt, uint8_t rs){
	if (DEBUG) cout << "srlv" << endl;
    Register[rd] = Register[rt] >> Register[rs];
    Register[rd] & (0xFFFFFFFF >> Register[rs]);
    PC_advance(default_advance);
}

//shift right arithmetic variable (default c++)
void srav(uint8_t rd, uint8_t rt, uint8_t rs){
	if (DEBUG) cout << "srav" << endl;
	if (((Register[rt] & 0x80000000) >> 31) != 0) {
		Register[rd] = Register[rt] >> Register[rs];
		Register[rd] = Register[rd] + (0xFFFFFFFF << (32 - Register[rs]));
	}
	else {
		Register[rd] = Register[rt] >> Register[rs];
	}
    PC_advance(default_advance);
}

//jump register
void jr(uint8_t rs){
	if (DEBUG) cout << "jr" << endl;
	PC_advance(default_advance);
	decodeInstructions();
	Register[PC] = Register[rs];
	if (Register[PC] == 0) exit(Register[V0]);
}

//jump and link (rtype)
void jalr(uint8_t rd, uint8_t rs){
	if (DEBUG) cout << "jalr" << endl;
    //save return address in $31
	PC_advance(default_advance);
	decodeInstructions();
    Register[rd] = Register[PC];
	Register[PC] = Register[rs];
	if (Register[PC] == 0) exit(Register[V0]);;
}

//move from hi
void mfhi(uint8_t rd){
	if (DEBUG) cout << "mfhi" << endl;
    Register[rd] = Register[HI];
    PC_advance(default_advance);
}

//move to hi
void mthi(uint8_t rs){
	if (DEBUG) cout << "mthi" << endl;
    Register[HI] = Register[rs];
    PC_advance(default_advance);
}

//move from low
void mflo(uint8_t rd){
	if (DEBUG) cout << "mflo" << endl;
    Register[rd] = Register[LO];
    PC_advance(default_advance);
}

//move to low
void mtlo(uint8_t rs){
	if (DEBUG) cout << "mtlo" << endl;
    Register[LO] = Register[rs];
    PC_advance(default_advance);
}

//overflow condition ?
void mult(uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "mult" << endl;
	Register[LO] = (uint32_t)(((((int64_t)((int32_t)Register[rs]))*(int64_t)(((int32_t)Register[rt])))) & 0xFFFFFFFF);
	Register[HI] = (uint32_t)(((((int64_t)((int32_t)Register[rs]))*((int64_t)((int32_t)Register[rt]))) >> 32) & 0xFFFFFFFF);
    PC_advance(default_advance);
}

//unsigned mult
void multu(uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "multu" << endl;
    Register[LO] = (uint32_t)(((((uint64_t)Register[rs])*((uint64_t)Register[rt]))) & 0xFFFFFFFF);
    Register[HI] = (uint32_t)(((((uint64_t)Register[rs])*((uint64_t)Register[rt])) >> 32) & 0xFFFFFFFF);
    PC_advance(default_advance);
}

//signed division
void div(uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "div" << endl;
    if (Register[rt] == 0){
        exit(-10);
    }
    Register[LO] = (int32_t)Register[rs] / (int32_t)Register[rt];
    Register[HI] = Register[rs] % Register[rt];
    PC_advance(default_advance);
}

//unsigned division
void divu(uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "divu" << endl;
    if (Register[rt] == 0){
        exit(-10);
    }
    Register[LO] = Register[rs] / Register[rt];
    Register[HI] = Register[rs] % Register[rt];
    PC_advance(default_advance);
}

//signed addition, exit if overflow
void add(uint8_t rd, uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "add" << endl;
    Register[rd] = Register[rt] + Register[rs];
    PC_advance(default_advance);
    
    
    //different signs, no overflow possible
     
    if((Register[rt] & 0x80000000) ^ (Register[rs] & 0x80000000) != 0){
        return;
    }
    
    //same signs:
    else{
        //result has same sign as operands ==>  no overflow
        if((Register[rt] & 0x80000000) ^ (Register[rd] & 0x80000000) == 0){
            return;
        }
        //result has different sign from operands ==>  overflow
        else{
            exit(-10);
        }
     }
    
    
}


//basic add, no concern for overflow
void addu(uint8_t rd, uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "addu" << endl;
    Register[rd] = Register[rt] + Register[rs];
    PC_advance(default_advance);
}

void sub(uint8_t rd, uint8_t rt, uint8_t rs){
	if (DEBUG) cout << "sub" << endl;
	Register[rt] = (Register[rt] ^ 0xFFFFFFFF) + 1;
    add(rd, rs, rt);
	Register[rt] = (Register[rt] ^ 0xFFFFFFFF) + 1;
}

//basic subtraction, no concern for overflow
void subu(uint8_t rd, uint8_t rt, uint8_t rs){
	if (DEBUG) cout << "subu" << endl;
    Register[rd] = Register[rs] - Register[rt];
    PC_advance(default_advance);
}

//bitwise and
void M_and(uint8_t rd, uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "and" << endl;
    Register[rd] = Register[rt] & Register[rs];
    PC_advance(default_advance);
}

//bitwise or
void M_or(uint8_t rd, uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "or" << endl;
    Register[rd] = Register[rt] | Register[rs];
    PC_advance(default_advance);
}

//bitwise xor
void M_xor(uint8_t rd, uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "xor" << endl;
	Register[rd] = ((Register[rt] | Register[rs])&(~Register[rt] | ~Register[rs]));
    PC_advance(default_advance);
}

//bitwise nor
void M_nor(uint8_t rd, uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "nor" << endl;
    Register[rd] = ~(Register[rt] | Register[rs]);
    PC_advance(default_advance);
}
    
//set if less than equal
void slt(uint8_t rd, uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "slt" << endl;
    int8_t temp1 = (int8_t)Register[rs];
    int8_t temp2 = (int8_t)Register[rt];
    Register[rd] = ((int8_t) Register[rs]<(int8_t) Register[rt])? 1 : 0;
    PC_advance(default_advance);
}

//set if less than equal unsigned version
void sltu(uint8_t rd, uint8_t rs, uint8_t rt){
	if (DEBUG) cout << "sltu" << endl;
    Register[rd] = (Register[rs] < Register[rt]) ? 1 : 0;
    PC_advance(default_advance);
}

// jump
void j(uint32_t target) {
	if (DEBUG) cout << "j" << endl;
	PC_advance(default_advance);
	decodeInstructions();
	PC_advance(-4);
	Register[PC] = (Register[PC] & 0xF0000000) + target;
}

// jump and link
void jal(uint32_t target) {
	if (DEBUG) cout << "jal" << endl;
	Register[PC] += 4;
	decodeInstructions();
	Register[RA] = Register[PC];
	Register[PC] = (Register[PC] & 0xF0000000) + target;
}

//addi 
void addi(uint8_t rt, uint8_t rs, uint32_t imm){
	if (DEBUG) cout << "addi" << endl;
    Register[rt] = Register[rs] + imm;
    PC_advance(default_advance);
    
    
    //different signs, no overflow possible
    
    if((Register[rs] & 0x80000000) ^ (imm & 0x80000000) != 0){

        return;
    }
    
    //same signs:
    else{
        //result has same sign as operands ==>  no overflow
        if((Register[rs] & 0x80000000) ^ (Register[rt] & 0x80000000) == 0){
            return;
        }
        //result has different sign from operands ==>  overflow
        else{
            exit(-10);
        }
    }
    
    
    //different signs, no overflow possible
    
    
}

void addiu(uint8_t rt, uint8_t rs, uint32_t imm) {
	if (DEBUG) cout << "addiu" << endl;
	imm = imm & 0xFFFF;
	Register[rt] = Register[rs] + imm;
	PC_advance(default_advance);
}

void andi(uint8_t rt, uint8_t rs, uint32_t imm) {
    
    Register[rt] = Register[rs] & (uint32_t)imm;
    PC_advance(default_advance);
}



// beq
void beq(uint8_t rs, uint8_t rt, uint32_t imm) {
	if (DEBUG) cout << "beq" << endl;
	PC_advance(default_advance);
	decodeInstructions();
	if (Register[rs] == Register[rt])
		PC_advance((int32_t)(imm << 2));
		
}

// bgez
void bgez(uint8_t rs, uint32_t imm) {
	if (DEBUG) cout << "bgez" << endl;
	PC_advance(default_advance);
	decodeInstructions();
	if ((int32_t)Register[rs] >= 0)
		PC_advance((imm << 2) - 8);

}

// bgezal
void bgezal(uint8_t rs, uint32_t imm) {
	if (DEBUG) cout << "bgezal" << endl;
	PC_advance(default_advance);
	decodeInstructions();
	if ((int32_t)(Register[rs]) >= 0) {
		Register[RA] = Register[PC];
		PC_advance((imm << 2) - 8);

	}
}

// bgtz
void bgtz(uint8_t rs, uint32_t imm) {
	if (DEBUG) cout << "bgtz" << endl;
	PC_advance(default_advance);
	decodeInstructions();
	if ((int32_t)(Register[rs]) > 0)
		PC_advance((imm << 2) - 8);

}

// blez
void blez(uint8_t rs, uint32_t imm) {
	if (DEBUG) cout << "blez" << endl;
	PC_advance(default_advance);
	decodeInstructions();
	if ((int32_t) Register[rs] <= 0)
		PC_advance((imm << 2) - 8);
}

// bltz
void bltz(uint8_t rs, uint32_t imm) {
	if (DEBUG) cout << "bltz" << endl;
	PC_advance(default_advance);
	decodeInstructions();
	if ((int32_t) Register[rs] < 0)
		PC_advance((imm << 2) - 8);
}

// bltzal
void bltzal(uint8_t rs, uint32_t imm) {
	if (DEBUG) cout << "bltzal" << endl;
	PC_advance(default_advance);
	decodeInstructions();
	if ((int32_t) Register[rs] < 0) {
		Register[RA] = Register[PC];
		PC_advance((imm << 2) - 8);
	}
}

// bne
void bne(uint8_t rs, uint8_t rt, uint32_t imm) {
	if (DEBUG) cout << "bne" << endl;
	PC_advance(default_advance);
	decodeInstructions();
	if (Register[rs] != Register[rt]) {
		PC_advance((imm << 2) - 8); 
	}
}

//lui
void lui(uint32_t rt, uint32_t imm) {
	if (DEBUG) cout << "lui" << endl;
	imm = imm & 0xFFFF;
	imm = imm << 16;
	Register[rt] = imm;
	PC_advance(default_advance);
}


//lw
void lw(uint32_t rt, uint32_t rs, uint32_t offset) {
	if (DEBUG) cout << "lw" << endl;
	Register[rt] = mainMemory.getRAM(Register[rs] + offset);
	PC_advance(default_advance);
}

//lbu
void lbu(uint32_t rt, uint32_t rs, uint32_t offset) {
	if (DEBUG) cout << "lbu" << endl;
	Register[rt] = mainMemory.getByteRAM(Register[rs] + offset);
	PC_advance(default_advance);
}

//lb
void lb(uint32_t rt, uint32_t rs, uint32_t offset) {
	if (DEBUG) cout << "lb" << endl;
	Register[rt] = mainMemory.getByteRAM(Register[rs] + offset);
	if ((Register[rt] & 0x80) != 0) Register[rt] = Register[rt] | 0xFFFFFF00;
	PC_advance(default_advance);
}

//lwl
void lwl(uint32_t rt, uint32_t rs, uint32_t offset) {
	if (DEBUG) cout << "lwl" << endl;
	offset = offset & 0xFFFF;
	int alignment = (Register[rs] + offset) % 4;
	//extra protections for I/O
	if (((int)(Register[rs] + offset - alignment) == 0x30000000) && alignment != 0)
		exit(-12);
	uint32_t temp = mainMemory.getRAM((Register[rs] + offset) - alignment);
	//if alignment == 0 then lowest byte if 3 then MSByte
	switch (alignment) {
	case 0:
		Register[rt] = temp;
		break;
	case 1:
		Register[rt] = (Register[rt] & 0xFF000000) + ((temp >> 8) & 0xFFFFFF);
		break;
	case 2:
		Register[rt] = (Register[rt] & 0xFFFF0000) + ((temp >> 16) & 0xFFFF);
		break;
	case 3:
		Register[rt] = (Register[rt] & 0XFFFFFF00) + ((temp >> 24) & 0xFF);
		break;
	}
	PC_advance(default_advance);
}

//lwr
void lwr(uint32_t rt, uint32_t rs, uint32_t offset) {
	if (DEBUG) cout << "lwr" << endl;
	offset = offset & 0xFFFF;
	int alignment = (Register[rs] + offset) % 4;
	if (((int)(Register[rs] + offset - alignment) == 0x30000000) && alignment != 0)
		exit(-12);
	uint32_t temp = mainMemory.getRAM((Register[rs] + offset) - alignment);
	switch (alignment) {
	case 0:
		Register[rt] = (Register[rt] & 0xFFFFFF) + ((temp << 24) & 0xFF000000);
		break;
	case 1:
		Register[rt] = (Register[rt] & 0xFFFF) + ((temp << 16) & 0xFFFF0000);
		break;
	case 2:
		Register[rt] = (Register[rt] & 0xFF) + ((temp << 8) & 0xFFFFFF00);
		break;
	case 3:
		Register[rt] = temp;
		break;
	}
	PC_advance(default_advance);
}

//CAN BE CHANGED TO BE CLEANER
void lhu(uint32_t rt, uint32_t rs, uint32_t offset) {
	if (DEBUG) cout << "lhu" << endl;
	if ((Register[rs] + offset) % 2 != 0) exit(-12);
	if (((int)(Register[rs] + offset) == 0x30000002))
		exit(-11);
	if (offset + Register[rs] == INPUT_IO_ADR) {
		Register[rt] = mainMemory.getRAM(INPUT_IO_ADR) & 0xFFFF;
	}
	else Register[rt] = ((mainMemory.getByteRAM(Register[rs] + offset) << 8) + (mainMemory.getByteRAM(Register[rs] + offset + 1) & 0xFF)) & 0xFFFF;
	PC_advance(default_advance);
}

void lh(uint32_t rt, uint32_t rs, uint32_t offset) {
	if (DEBUG) cout << "lh" << endl;
	if ((Register[rs] + offset) % 2 != 0) exit(-12);
	if (((int)(Register[rs] + offset) == 0x30000002))
		exit(-11);
	if (offset + Register[rs] == INPUT_IO_ADR) {
		Register[rt] = mainMemory.getRAM(INPUT_IO_ADR) & 0xFFFF;
	}
	else Register[rt] = ((mainMemory.getByteRAM(Register[rs] + offset) << 8) + (mainMemory.getByteRAM(Register[rs] + offset + 1) & 0xFF)) & 0xFFFF;
	if (((Register[rt] & 0x8000) >> 15) != 0) {
			Register[rt] = Register[rt] | 0xFFFF0000;
	}
	PC_advance(default_advance);
}

void ori(uint8_t rt, uint8_t rs, uint32_t imm){
	if (DEBUG) cout << "ori" << endl;
	Register[rt] = Register[rs] | (imm & 0xFFFF);
    PC_advance(default_advance);
}

void slti(uint8_t rt, uint8_t rs, uint32_t imm){
	if (DEBUG) cout << "slti" << endl;
    int32_t temp1 = imm;
    int32_t temp2;
    if((Register[rs] & 0x80) == 0){
        temp2 = Register[rs];
    }
    else{
        temp2 = Register[rs] | 0xFFFFFF00;
    }
    
    PC_advance(default_advance);
    if(temp2 < temp1){
        Register[rt] = 1;
    }
    else{
        Register[rt] = 0;
    }
}

void sltiu(uint8_t rt, uint8_t rs, uint32_t imm){
	if (DEBUG) cout << "sltiu" << endl;
    imm = imm & 0xFFFF;
    PC_advance(default_advance);
    if(Register[rs] < (uint32_t)imm){
        Register[rt] = 1;
    }
    else{
        Register[rt] = 0;
    }
}

void sw(uint32_t rt, uint32_t rs, uint32_t offset) {
	if (DEBUG) cout << "sw" << endl;
	mainMemory.writeRAM(Register[rs] + offset, Register[rt]);
	PC_advance(default_advance);
}

void sh(uint32_t rt, uint32_t rs, uint32_t offset) {
	if (DEBUG) cout << "sh" << endl;
	if ((offset + Register[rs]) % 2 != 0) exit(-12);
	if (offset + Register[rs] == OUTPUT_IO_ADR) {
		mainMemory.writeRAM(OUTPUT_IO_ADR, Register[rt] & 0xFFFF);
	}
	else {
		mainMemory.writeByteRAM(Register[rs] + offset, ((Register[rt] >> 8) & 0xFFFF));
		mainMemory.writeByteRAM(Register[rs] + offset + 1, (Register[rt] & 0xFFFF));
	}
	PC_advance(default_advance);
}

void sb(uint32_t rt, uint32_t rs, uint32_t offset) {
	if (DEBUG) cout << "sb" << endl;
	mainMemory.writeByteRAM(Register[rs] + offset, Register[rt]);
	PC_advance(default_advance);
}

void xori(uint8_t rt, uint8_t rs, uint32_t imm){
	if (DEBUG) cout << "xori" << endl;
    Register[rt] = ((uint32_t)imm) ^ Register[rs];
    PC_advance(default_advance);
}

void nop() {
	if (DEBUG) cout << "nop" << endl;
	PC_advance(default_advance);
}


void PC_advance(int advance) {
	Register[PC] = Register[PC] + advance;
}

