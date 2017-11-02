//THIS FILE DESCRIBES EVERY INSTURCTION
//THAT MIPS SHOULD SUPPORT

#include "ram.hpp"


//R-type
uint32_t sll(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t srl(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t sra(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t sllv(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t srlv(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t srav(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t jr(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t jalr(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t mfhi(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t mthi(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t mflo(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t mtlo(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t mult(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t multu(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t div(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t divu(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t add(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t addu(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t sub(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t subu(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t and(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t or(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t xor(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t nor(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t slt(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
uint32_t sltu(uint32_t& rd[], uint32_t rs[], uint32_t rt[]);
