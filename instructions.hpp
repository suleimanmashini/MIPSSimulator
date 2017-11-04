//THIS FILE DESCRIBES EVERY INSTURCTION
//THAT MIPS SHOULD SUPPORT

#include "data.hpp"


//R-type
void sll(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa);
void srl(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa);
void sra(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa);
void sllv(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void srlv(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void srav(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);

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

bool add(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void addu(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void sub(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void subu(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void and(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void or(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void xor(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void nor(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);

void slt();
void sltu();
