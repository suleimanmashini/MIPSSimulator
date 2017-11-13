#pragma once
#include "instructions.hpp"



void fetchInstructions();
void fetchInstructions(int flag);

void decodeRType(uint32_t instr);

void decodeIType(uint32_t instr);

void decodeJType(uint32_t instr);