#include "instructions.hpp"
#include "instructiondecode.hpp"

using namespace std;
//shift left logicals
void sll(uint8_t rd, uint8_t rt, uint8_t shamt){
    Register[rd] = Register[rt] << shamt;
    PC_advance(default_advance);
}

//shift right logical
void srl(uint8_t rd, uint8_t rt, uint8_t shamt){
    Register[rd] = Register[rt] >> shamt;
    Register[rd] & (32 >> shamt);
    PC_advance(default_advance);
}

//shift right arithmetic, default right shift c++
void sra(uint8_t rd, uint8_t rt, uint8_t shamt){
    Register[rd] = Register[rt] >> shamt;
    PC_advance(default_advance);
}

//shift left logical variable
void sllv(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = Register[rt] << Register[rs];
    PC_advance(default_advance);
}

//shift right logical variable
void srlv(uint8_t rd, uint8_t rt, uint8_t rs){
    Register[rd] = Register[rt] >> Register[rs];
    Register[rd] & (0xFFFFFFFF >> Register[rs]);
    PC_advance(default_advance);
}

//shift right arithmetic variable (default c++)
void srav(uint8_t rd, uint8_t rt, uint8_t rs){
    Register[rd] = Register[rt] >> Register[rs];
    PC_advance(default_advance);
}

//jump register
void jr(uint8_t rs){
	Register[PC] = Register[rs];
}

//jump and link (rtype)
void jalr(uint8_t rd, uint8_t rs){
    //save return address in $31
    Register[RA] = Register[PC] + default_advance;
	Register[PC] = Register[rs];
}

//move from hi
void mfhi(uint8_t rd){
    Register[rd] = HI;
    PC_advance(default_advance);
}

//move to hi
void mthi(uint8_t rs){
    Register[HI] = Register[rs];
    PC_advance(default_advance);
}

//move from low
void mflo(uint8_t rd){
    Register[rd] = Register[LO];
    PC_advance(default_advance);
}

//move to low
void mtlo(uint8_t rs){
    Register[LO] = Register[rs];
    PC_advance(default_advance);
}

//overflow condition ?
void mult(uint8_t rs, uint8_t rt){
	Register[LO] = (uint32_t)(((((int64_t)((int32_t)Register[rs]))*(int64_t)(((int32_t)Register[rt])))) & 0xFFFFFFFF);
	Register[HI] = (uint32_t)(((((int64_t)((int32_t)Register[rs]))*((int64_t)((int32_t)Register[rt]))) >> 32) & 0xFFFFFFFF);
    PC_advance(default_advance);
}

//unsigned mult
void multu(uint8_t rs, uint8_t rt){
    Register[LO] = (uint32_t)(((((uint64_t)Register[rs])*((uint64_t)Register[rt]))) & 0xFFFFFFFF);
    Register[HI] = (uint32_t)(((((uint64_t)Register[rs])*((uint64_t)Register[rt])) >> 32) & 0xFFFFFFFF);
    PC_advance(default_advance);
}

//signed division
void div(uint8_t rs, uint8_t rt){
    if (Register[rt] == 0){
        exit(-10);
    }
    Register[LO] = (int32_t)Register[rs] / (int32_t)Register[rt];
    Register[HI] = (int32_t)Register[rs] % (int32_t)Register[rt];
    PC_advance(default_advance);
}

//unsigned division
void divu(uint8_t rs, uint8_t rt){
    if (Register[rt] == 0){
        exit(-10);
    }
    Register[LO] = Register[rs] / Register[rt];
    Register[HI] = Register[rs] % Register[rt];
    PC_advance(default_advance);
}

//signed addition, exit if overflow
void add(uint8_t rd, uint8_t rs, uint8_t rt){
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
    Register[rd] = Register[rt] + Register[rs];
    PC_advance(default_advance);
}

void sub(uint8_t rd, uint8_t rt, uint8_t rs){
    add(rd, rs, ((Register[rt] ^ 0xFFFFFFFF) + 1));
    
}

//basic subtraction, no concern for overflow
void subu(uint8_t rd, uint8_t rt, uint8_t rs){
    Register[rd] = Register[rs] - Register[rt];
    PC_advance(default_advance);
}

//bitwise and
void M_and(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = Register[rt] & Register[rs];
    PC_advance(default_advance);
}

//bitwise or
void M_or(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = Register[rt] | Register[rs];
    PC_advance(default_advance);
}

//bitwise xor
void M_xor(uint8_t rd, uint8_t rs, uint8_t rt){
	Register[rd] = ((Register[rt] | Register[rs])&(~Register[rt] | ~Register[rs]));
    PC_advance(default_advance);
}

//bitwise nor
void M_nor(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = ~(Register[rt] | Register[rs]);
    PC_advance(default_advance);
}
    
//set if less than equal
void slt(uint8_t rd, uint8_t rs, uint8_t rt){
    int8_t temp1 = (int8_t)Register[rs];
    int8_t temp2 = (int8_t)Register[rt];
    Register[rd] = (Register[rs]<Register[rt])? 1 : 0;
    PC_advance(default_advance);
}

//set if less than equal unsigned version
void sltu(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = (Register[rs] < Register[rt]) ? 1 : 0;
    PC_advance(default_advance);
}

// jump
void j(uint32_t target) {
	Register[PC] = (Register[PC] & 0xF0000000) + target;
}

// jump and link
void jal(uint32_t target) {
	Register[PC] += 4;
	fetchInstructions(1);
	Register[RA] = Register[PC] + 4;
	Register[PC] = (Register[PC] & 0xF0000000) + target;
}
    
void PC_advance(uint32_t advance){
    Register[PC] = Register[PC] + advance;
}

//lui
void lui(uint32_t rt, uint32_t imm) {
	Register[rt] = (imm << 16);
	PC_advance(default_advance);
}
