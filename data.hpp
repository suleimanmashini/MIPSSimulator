
//THE PURPOSE OF THIS FILE IS TO ACCESS ALL DATA NEEDED
//REGISTERS AND RAM CAN BE ACCESSED USING THIS

#include "ram.hpp"

extern RAM mainMemory;
extern uint32_t Register[32] = { 0 };

//IMPORTANT ADDRESSES
extern const int EXIT_ADR = 0;
extern const int INSTRUCTION_START_ADR = 0x10000000;
extern const int INPUT_IO_ADR = 0x30000000;
extern const int OUTPUT_IO_ADR = 0x30000004;
//RAM AND REGISTERS

//REGISTER ADDRESSES
extern const int R_ZERO = 0; //HARD WIRES TO 0
extern const int R_AT = 1; //RESERVED FOR PSEUDO-INSTRUCTIONS
extern const int R_V0 = 2; //RETURN VALUES FROM FUNCTIONS
extern const int R_V1 = 3; // ***
extern const int R_A0 = 4; // ARGUMENTS TO FUNCTIONS (NOT PRESERVED BT SUBPROGRAMS)
extern const int R_A1 = 5; // ***
extern const int R_A2 = 6; // ***
extern const int R_A3 = 7; // ***
extern const int R_T0 = 8; // TEMPORARY DATA (NOT PRESERVED BY SUBPROGRAMS)
extern const int R_T1 = 9; // ***
extern const int R_T2 = 10; // ***
extern const int R_T3 = 11; // ***
extern const int R_T4 = 12; // ***
extern const int R_T5 = 13; // ***
extern const int R_T6 = 14; // ***
extern const int R_T7 = 15; // ***
extern const int R_S0 = 16; //SAVED REGISTERS (PRESERVED BY SUBPROGRAMS)
extern const int R_S1 = 17; // ***
extern const int R_S2 = 18; // ***
extern const int R_S3 = 19; // ***
extern const int R_S4 = 20; // ***
extern const int R_S5 = 21; // ***
extern const int R_S6 = 22; // ***
extern const int R_S7 = 23; // ***
extern const int R_T8 = 24; //MORE TEMP REGISTERS (NOT PRESERVED BY SUBPROGRAMS)
extern const int R_T9 = 25; // ***
extern const int R_K0 = 26; //KERNEL 
extern const int R_K1 = 27; // ***
extern const int R_GP = 28; // GLOBAL AREA POINTER
extern const int R_SP = 29; // STACK POINTER
extern const int R_FP = 30; //FRAME POINTER
extern const int R_RA = 31; //RETURN ADDRESS
