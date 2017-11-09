#include "instructions.hpp"
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
    PC_advance(Register[rs]);
}

//jump and link (rtype)
void jalr(uint8_t rd, uint8_t rs){
    //save return address in $31
    Register[RA] = Register[PC] + default_advance;
    PC_advance(Register[rs]);
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

//overflow ?
void div(uint8_t rs, uint8_t rt){
    Register[LO] = Register[rs] / Register[rt];
    Register[HI] = Register[rs] % Register[rt];
    PC_advance(default_advance);
}

//unsigned division
void divu(uint8_t rs, uint8_t rt){
    Register[LO] = Register[rs] / Register[rt];
    Register[HI] = Register[rs] % Register[rt];
    PC_advance(default_advance);
}

//return 1 when overflow occurs
void add(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = Register[rt] + Register[rs];
    PC_advance(default_advance);
    
    /*
    //different signs, no overflow possible
    if(Register[rd]*Register[rt] <= 0){ //***CHECK THAT UR STATEMENTS WORK!!
        return 0;
    }
    
    //same signs:
    else{
        //result has different sign from operands ==> overflow
        if(Register[rd]*Register[rt] < 0){
            return 1;
        }
        else{
            return 0;
        }
     }
     */
    
}


//basic add, no concern for overflow
void addu(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = Register[rt] + Register[rs];
    PC_advance(default_advance);
}

void sub(uint8_t rd, uint8_t rt, uint8_t rs){
    Register[rd] = Register[rs] - Register[rt];
    PC_advance(default_advance);
    //same signs, no overflow possible
    /*
    if(Register[rd]*Register[rt] >= 0){
        return 0;
    }
    
    //different signs:
    else{
        //result has different sign from subtrahend ==> overflow
        if(Register[rd]*Register[rt] < 0){
            return 1;
        }
        else{
            return 0;
        }
    }
     */
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
    
    
void PC_advance(uint32_t advance){
    Register[PC] = Register[PC] + advance;
}
