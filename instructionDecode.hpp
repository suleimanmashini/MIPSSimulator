#pragma once
#include "data.hpp"

void fetchIntstructions();

void decodeRType(uint32_t instr);

void decodeIType(uint32_t instr);

void decodeJType(uint32_t instr);