//THIS FILE DESCRIBES EVERY INSTURCTION
//THAT MIPS SHOULD SUPPORT
#pragma once
#include "data.hpp"
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
void PC_advance(uint32_t advance);


// J-Type
void j(uint32_t target);
void jal(uint32_t target);

//I-type

void addi(); //victor
void addiu(); //victor
void andi(); //victor
void lui(uint32_t rt, uint32_t imm); //sam
void ori(); //victor
void slti(); //victor
void sltiu(); //victor
void xori(); //victor
void beq(); //john
void bgez(); //john
void bgezal(); //john
void bltz(); //john
void bltzal(); //john
void bgtz(); //john
void blez(); //john
void bne(); //john
void lbu(uint32_t rt, uint32_t rs, uint32_t offset);
void lb(uint32_t rt, uint32_t rs, uint32_t offset);
void lh(); //sam
void lhu(); //sam
void lw(uint32_t rt, uint32_t rs, uint32_t offset); //sam
void sb(); //sam
void sh(); //sam
void sw(); //sam


