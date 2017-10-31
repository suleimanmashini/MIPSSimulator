#pragma once

#include "data.hpp"
//IMPORTANT ADDRESSES
const int EXIT_ADR = 0;
const int INSTRUCTION_START_ADR = 0x10000000;
const int INPUT_IO_ADR = 0x30000000;
const int OUTPUT_IO_ADR = 0x30000004;
//RAM AND REGISTERS

//REGISTER ADDRESSES
const int R_ZERO = 0; //HARD WIRES TO 0
const int R_AT = 1; //RESERVED FOR PSEUDO-INSTRUCTIONS
const int R_V0 = 2; //RETURN VALUES FROM FUNCTIONS
const int R_V1 = 3; // ***
const int R_A0 = 4; // ARGUMENTS TO FUNCTIONS (NOT PRESERVED BT SUBPROGRAMS)
const int R_A1 = 5; // ***
const int R_A2 = 6; // ***
const int R_A3 = 7; // ***
const int R_T0 = 8; // TEMPORARY DATA (NOT PRESERVED BY SUBPROGRAMS)
const int R_T1 = 9; // ***
const int R_T2 = 10; // ***
const int R_T3 = 11; // ***
const int R_T4 = 12; // ***
const int R_T5 = 13; // ***
const int R_T6 = 14; // ***
const int R_T7 = 15; // ***
const int R_S0 = 16; //SAVED REGISTERS (PRESERVED BY SUBPROGRAMS)
const int R_S1 = 17; // ***
const int R_S2 = 18; // ***
const int R_S3 = 19; // ***
const int R_S4 = 20; // ***
const int R_S5 = 21; // ***
const int R_S6 = 22; // ***
const int R_S7 = 23; // ***
const int R_T8 = 24; //MORE TEMP REGISTERS (NOT PRESERVED BY SUBPROGRAMS)
const int R_T9 = 25; // ***
const int R_K0 = 26; //KERNEL 
const int R_K1 = 27; // ***
const int R_GP = 28; // GLOBAL AREA POINTER
const int R_SP = 29; // STACK POINTER
const int R_FP = 30; //FRAME POINTER
const int R_RA = 31; //RETURN ADDRESS

