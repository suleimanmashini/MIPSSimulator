#include "instructions.hpp"

//shift left logical
void sll(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa){
    Register[rd] = rt << sa;
}

//shift right logical
void srl(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa){
    Register[rd] = rt >> sa;
    Rgister[rd] & (0xFFFFFFFF >> sa);
}

//shift right arithmetic, default right shift c++
void sra(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t sa){
    Register[rd] = rt >> sa;
}

//shift left logical variable
void sllv(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs){
    Register[rd] = rs << rt;
}

//shift right logical variable
void srlv(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs){
    Register[rd] = rt >> rs;
    Rgister[rd] & (0xFFFFFFFF >> rs);
}

//shift right arithmetic variable (default c++)
void srav(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs){
    Register[rd] = rt >> sa;
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

void add(uint32_t *Register, uint32_t rd, uint32_t rt, uint32_t rs){
    Registe[rd] = rt + rs;
}

void addu();
void sub();
void subu();
void and();
void or();
void xor();
void nor();
void slt();
void sltu();
