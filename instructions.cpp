#include "instructions.hpp"

//shift left logical
void sll(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa){
    Register[rd] = Register[rt] << sa;
}

//shift right logical
void srl(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa){
    Register[rd] = Register[rt] >> sa;
    Rgister[rd] & (0xFFFFFFFF >> sa);
}

//shift right arithmetic, default right shift c++
void sra(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa){
    Register[rd] = Register[rt] >> sa;
}

//shift left logical variable
void sllv(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt){
    Register[rd] = Register[rt] << Register[rs];
}

//shift right logical variable
void srlv(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs){
    Register[rd] = Register[rt] >> Register[rs];
    Rgister[rd] & (0xFFFFFFFF >> Registe[rs]);
}

//shift right arithmetic variable (default c++)
void srav(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs){
    Register[rd] = Register[rt] >> sa;
}


void jr();
void jalr();
void mfhi();
void mthi();
void mflo();
void mtlo();
void mult();
void multu();
void div();
void divu();

//return 1 when overflow occurs
bool add(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt){
    Register[rd] = Register[rt] + Register[rs];
    
    //different signs, no overflow possible
    if(Register[rd]*Register[rt] =< 0){
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
void addu(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt){
    Register[rd] = Register[rt] + Register[rs];
}

bool sub(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs){
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
void subu(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs){
    Register[rd] = Register[rs] - Register[rt];
}

//bitwise and
void and(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt){
    Register[rd] = Register[rt] & Register[rs];
}

//bitwise or
void or(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt){
    Register[rd] = Register[rt] | Register[rs];
}

//bitwise xor
void xor(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt){
    Register[rd] = ((Register[rt] | Register[rs])&(~Register[rt] | ~Register[rs]))
}

//bitwise nor
void nor(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt){
    Register[rd] = ~(Register[rt] | Register[rs]);
}
    
//set if less than equal
void slt(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt){
    Register[rd] = (Register[rs]<Register[rt])? 1 : 0;
}

//set if less than equal unsigned version
void sltu(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt){
    Register[rd] = (abs(Register[rs]) < abs(Register[rt]))? 1 : 0;
}
        
