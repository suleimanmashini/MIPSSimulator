#include "data.hpp"
#include "ram.hpp"
#include <iostream>

using namespace std;

RAM mainMemory;
uint32_t Register[35] = {
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0, INSTRUCTION_START_ADR };
