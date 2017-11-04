//THIS FILE DESCRIBES EVERY INSTURCTION
//THAT MIPS SHOULD SUPPORT

#include "data.hpp"


//R-type
void sll();
void srl();
void sra();
void sllv();
void srlv();
void srav();
void jr();
void jalr(uint8_t rs, uint8_t rd, uint8_t rt);
void mfhi(uint8_t rs, uint8_t rd, uint8_t rt);
void mthi(uint8_t rs, uint8_t rd, uint8_t rt);
void mflo(uint8_t rs, uint8_t rd, uint8_t rt);
void mtlo(uint8_t rs, uint8_t rd, uint8_t rt);
void mult(uint8_t rs, uint8_t rd, uint8_t rt);
void multu(uint8_t rs, uint8_t rd, uint8_t rt);
void div(uint8_t rs, uint8_t rd, uint8_t rt);
void divu(uint8_t rs, uint8_t rd, uint8_t rt);

void add(uint32_t Register[32], int rd, int rs, int rt)



void addu(uint8_t rs, uint8_t rd, uint8_t rt);
void sub(uint8_t rs, uint8_t rd, uint8_t rt);
void subu(uint8_t rs, uint8_t rd, uint8_t rt);
void and(uint8_t rs, uint8_t rd, uint8_t rt);
void or(uint8_t rs, uint8_t rd, uint8_t rt);
void xor(uint8_t rs, uint8_t rd, uint8_t rt);
void nor(uint8_t rs, uint8_t rd, uint8_t rt);
void slt(uint8_t rs, uint8_t rd, uint8_t rt);
void sltu(uint8_t rs, uint8_t rd, uint8_t rt);
