//THIS FILE DESCRIBES EVERY INSTURCTION
//THAT MIPS SHOULD SUPPORT

#include "data.hpp"
#include <cmath>

//default pc incrementer
uint32_t default_advance = 4;

//R-type
//done
void sll(uint8_t rd, uint8_t rt, uint8_t shamt);
void srl(uint8_t rd, uint8_t rt, uint8_t shamt);
void sra(uint8_t rd, uint8_t rt, uint8_t shamt);
void sllv(uint8_t rd, uint8_t rs, uint8_t rt);
void srlv(uint8_t rd, uint8_t rt, uint8_t rs);
void srav(uint8_t rd, uint8_t rt, uint8_t rs);
void jr(uint8_t rs);

//to do
void jalr(uint8_t rd, uint8_t rs);

//done
void mfhi(uint8_t rd);
void mthi(uint8_t rs);
void mflo(uint8_t rd);
void mtlo(uint8_t rs);
bool mult(uint8_t rs, uint8_t rt);
void multu(uint8_t rs, uint8_t rt);
void div(uint8_t rs, uint8_t rt);
void divu(uint8_t rs, uint8_t rt);
bool add(uint8_t rd, uint8_t rs, uint8_t rt);
void addu(uint8_t rd, uint8_t rs, uint8_t rt);
void sub(uint8_t rd, uint8_t rt, uint8_t rs);
void subu(uint8_t rd, uint8_t rt, uint8_t rs);
void and(uint8_t rd, uint8_t rs, uint8_t rt);
void or(uint8_t rd, uint8_t rs, uint8_t rt);
void xor(uint8_t rd, uint8_t rs, uint8_t rt);
void nor(uint8_t rd, uint8_t rs, uint8_t rt);
void slt(uint8_t rd, uint8_t rs, uint8_t rt);
void sltu(uint8_t rd, uint8_t rs, uint8_t rt);

//general purpose functions
void PC_advance(uint32_t advance);
