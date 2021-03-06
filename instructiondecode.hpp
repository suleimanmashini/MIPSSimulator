#pragma once
#include "instructions.hpp"

void decodeInstructions();

void decodeRType(uint32_t instr);

void decodeIType(uint32_t instr);

void decodeJType(uint32_t instr);

uint32_t sign_extention(uint16_t imm);
