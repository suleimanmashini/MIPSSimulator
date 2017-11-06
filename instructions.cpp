#include "instructions.hpp"

//shift left logical
void sll(uint8_t rd, uint8_t rt, uint8_t shamt){
    Register[rd] = Register[rt] << shamt;
}

//shift right logical
void srl(uint8_t rd, uint8_t rt, uint8_t shamt){
    Register[rd] = Register[rt] >> shamt;
    Register[rd] & (0xFFFFFFFF >> shamt);
}

//shift right arithmetic, default right shift c++
void sra(uint8_t rd, uint8_t rt, uint8_t shamt){
    Register[rd] = Register[rt] >> shamt;
}

//shift left logical variable
void sllv(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = Register[rt] << Register[rs];
}

//shift right logical variable
void srlv(uint8_t rd, uint8_t rt, uint8_t rs){
    Register[rd] = Register[rt] >> Register[rs];
    Register[rd] & (0xFFFFFFFF >> Register[rs]);
}

//shift right arithmetic variable (default c++)
void srav(uint8_t rd, uint8_t rt, uint8_t rs){
    Register[rd] = Register[rt] >> Register[rs];
}

//jump register
void jr(uint8_t rs){
    uint8_t nPC = Register[rs];
    Register[PC] = nPC;
}

//not sure what this does
void jalr();

//move from hi
void mfhi(uint8_t rd){
    Register[rd] = HI;
}

//move to hi
void mthi(uint8_t rs){
    Register[HI] = Register[rs];
}

//move from low
void mflo(uint8_t rd){
    Register[rd] = LO;
}

//move to low
void mtlo(uint8_t rs){
    Register[LO] = Register[rs];
}

//overflow condition ?
bool mult(uint8_t rs, uint8_t rt){
   Register[LO] = (Register[rs]*Register[rt]) << 0xFFFFFFFF;
    Register[HI] = (Register[rs]*Register[rt]) >> 0xFFFFFFFF;
}

//unsigned mult
void multu(uint8_t rs, uint8_t rt){
    Register[LO] = (Register[rs]*Register[rt]) << 0xFFFFFFFF;
    Register[HI] = (Register[rs]*Register[rt]) >> 0xFFFFFFFF;
}

//overflow ?
void div(uint8_t rs, uint8_t rt){
    Register[LO] = Register[rs] / Register[rt];
    Register[HI] = Register[rs] % Register[rt];
}

//unsigned division
void divu(uint8_t rs, uint8_t rt){
    Register[LO] = Register[rs] / Register[rt];
    Register[HI] = Register[rs] % Register[rt];
}

//return 1 when overflow occurs
bool add(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = Register[rt] + Register[rs];
    
    //different signs, no overflow possible
    if(Register[rd]*Register[rt] =< 0){ //***CHECK THAT UR STATEMENTS WORK!!
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
}

//basic add, no concern for overflow
void addu(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = Register[rt] + Register[rs];
}

bool sub(uint8_t rd, uint8_t rt, uint8_t rs){
    Register[rd] = Register[rs] - Register[rt];
    //same signs, no overflow possible
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
}

//basic subtraction, no concern for overflow
void subu(uint8_t rd, uint8_t rt, uint8_t rs){
    Register[rd] = Register[rs] - Register[rt];
}

//bitwise and
void and(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = Register[rt] & Register[rs];
}

//bitwise or
void or(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = Register[rt] | Register[rs];
}

//bitwise xor
void xor(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = ((Register[rt] | Register[rs])&(~Register[rt] | ~Register[rs]))
}

//bitwise nor
void nor(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = ~(Register[rt] | Register[rs]);
}
    
//set if less than equal
void slt(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = (Register[rs]<Register[rt])? 1 : 0;
}

//set if less than equal unsigned version
void sltu(uint8_t rd, uint8_t rs, uint8_t rt){
    Register[rd] = (abs(Register[rs]) < abs(Register[rt]))? 1 : 0; //**** YOU DIDNT INCLUDE MATHS TO PERFORM ABSOLUTE (WHY ARE YOU USING ABSOLUTE ITS AN UNSIGNED INTEGER??)
}
        
