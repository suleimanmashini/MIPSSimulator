simulator: main.cpp ram.cpp instructions.cpp instructiondecode.cpp data.hpp instructions.hpp instructiondecode.hpp ram.hpp
	g++ -W -O2 -std=c++11 main.cpp ram.cpp instructions.cpp instructiondecode.cpp -o ./bin/mips_simulator

testbench:
	cp mips_testbench ./bin
