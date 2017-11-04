//THIS FILE DESCRIBES EVERY INSTURCTION
//THAT MIPS SHOULD SUPPORT

#include "data.hpp"
#include <cmath>


//R-type
//done
void sll(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa);
void srl(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa);
void sra(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa);
void sllv(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt);
void srlv(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void srav(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);


void jr(uint32_t *Register, uint32_t rs){
    
}
void jalr(uint32_t *Register, uint32_t rd, uint32_t rs);


void mfhi(uint32_t *Register, uint32_t rd);
void mthi(uint32_t *Register, uint32_t rs);
void mflo(uint32_t *Register, uint32_t rd);
void mtlo(uint32_t *Register, uint32_t rs);
void mult(uint32_t *Register, uint32_t rs, uint32_t rt);
void multu(uint32_t *Register, uint32_t rs, uint32_t rt);
void div(uint32_t *Register, uint32_t rs, uint32_t rt);
void divu(uint32_t *Register, uint32_t rs, uint32_t rt);

//done
bool add(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt);
void addu(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt);
void sub(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void subu(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs);
void and(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt);
void or(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt);
void xor(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt);
void nor(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt);
void slt(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt);
void sltu(uint32_t *Register, uint32_t rd, uint32_t rs, uint32_t rt);
