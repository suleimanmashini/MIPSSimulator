//THIS FILE DESCRIBES EVERY INSTURCTION
//THAT MIPS SHOULD SUPPORT
#pragma once
#include "data.hpp"
#include <cstdlib>
#include <cmath>



//R-type instructions

void sll(uint8_t rd, uint8_t rt, uint8_t shamt);
void srl(uint8_t rd, uint8_t rt, uint8_t shamt);
void sra(uint8_t rd, uint8_t rt, uint8_t shamt);
void sllv(uint8_t rd, uint8_t rs, uint8_t rt);
void srlv(uint8_t rd, uint8_t rt, uint8_t rs);
void srav(uint8_t rd, uint8_t rt, uint8_t rs);
void jr(uint8_t rs);
void jalr(uint8_t rd, uint8_t rs);
void mfhi(uint8_t rd);
void mthi(uint8_t rs);
void mflo(uint8_t rd);
void mtlo(uint8_t rs);
void mult(uint8_t rs, uint8_t rt); //tbc
void multu(uint8_t rs, uint8_t rt);
void div(uint8_t rs, uint8_t rt);
void divu(uint8_t rs, uint8_t rt);
void add(uint8_t rd, uint8_t rs, uint8_t rt); //tbc
void addu(uint8_t rd, uint8_t rs, uint8_t rt);
void sub(uint8_t rd, uint8_t rt, uint8_t rs); //tbc
void subu(uint8_t rd, uint8_t rt, uint8_t rs);
void M_and(uint8_t rd, uint8_t rs, uint8_t rt);
void M_or(uint8_t rd, uint8_t rs, uint8_t rt);
void M_xor(uint8_t rd, uint8_t rs, uint8_t rt);
void M_nor(uint8_t rd, uint8_t rs, uint8_t rt);
void slt(uint8_t rd, uint8_t rs, uint8_t rt);
void sltu(uint8_t rd, uint8_t rs, uint8_t rt);


//general purpose functions
void PC_advance(int advance);
void nop();


// J-Type
void j(uint32_t target);
void jal(uint32_t target);

//I-type

void addi(uint8_t rd, uint8_t rs, uint32_t imm);
void addiu(uint8_t rd, uint8_t rs, uint32_t imm);
void andi(uint8_t rd, uint8_t rs, uint32_t imm);
void lui(uint32_t rt, uint32_t imm); 
void ori(uint8_t rd, uint8_t rs, uint32_t imm);
void slti(uint8_t rt, uint8_t rs, uint32_t imm);
void sltiu(uint8_t rt, uint8_t rs, uint32_t imm);
void xori(uint8_t rd, uint8_t rs, uint32_t imm);
void beq(uint8_t rs, uint8_t rt, uint32_t imm);
void bgez(uint8_t rs, uint32_t imm);
void bgezal(uint8_t rs, uint32_t imm);
void bltz(uint8_t rs, uint32_t imm);
void bltzal(uint8_t rs, uint32_t imm);
void bgtz(uint8_t rs, uint32_t imm);
void blez(uint8_t rs, uint32_t imm);
void bne(uint8_t rs, uint8_t rt, uint32_t imm);
void lbu(uint32_t rt, uint32_t rs, uint32_t offset);
void lb(uint32_t rt, uint32_t rs, uint32_t offset);
void lh(uint32_t rt, uint32_t rs, uint32_t offset);
void lhu(uint32_t rt, uint32_t rs, uint32_t offset);
void lw(uint32_t rt, uint32_t rs, uint32_t offset); 
void sb(uint32_t rt, uint32_t rs, uint32_t offset);
void sh(uint32_t rt, uint32_t rs, uint32_t offset);
void sw(uint32_t rt, uint32_t rs, uint32_t offset); 
void lwl(uint32_t rt, uint32_t rs, uint32_t offset);
void lwr(uint32_t rt, uint32_t rs, uint32_t offset);


