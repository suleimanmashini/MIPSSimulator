
//THE PURPOSE OF THIS FILE IS TO ACCESS ALL DATA NEEDED
//REGISTERS AND RAM CAN BE ACCESSED USING THIS

#include "ram.hpp"


//IMPORTANT ADDRESSES
 enum {
	EXIT_ADR = 0,
	INSTRUCTION_START_ADR = 0x10000000,
	INPUT_IO_ADR = 0x30000000,
	OUTPUT_IO_ADR = 0x30000004
};

extern RAM mainMemory;
extern uint32_t Register[35] = { 
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0, INSTRUCTION_START_ADR};

//IMPORTANT ADDRESSES
//RAM AND REGISTERS
enum {
	RZERO, //HARD WIRES TO 0
	AT,  //RESERVED FOR PSEUDO-INSTRUCTIONS
	V0, V1, //RETURN VALUES FROM FUNCTIONS
	A0, A1, A2, A3, //ARGUMENTS TO FUNCTIONS (NOT PRESERVED BY SUBPROGRAMS)
	T0, T1, T2, T3, T4, T5, T6, T7, //TEMPORARY DATA (NOT PRESERVED BY SUBPROGRAMS)
	S0, S1, S2, S3, S4, S5, S6, S7, //SAVED REGISTERS (PRESERVED BY SUPROGRAMS)
	T8, T9, //MORE TEMP REGISTERS (NOT PRESEVED BY SUBPROGRAMS)
	K0, K1, //KERNEL
	GP, //GLOBAL AREA POINTED
	SP, //STACK POINTER
	FP, //FRAME POINTER
	RA, //RETURN ADDRESS
	HI, LO,
	PC
};