#include <iostream>

using namespace std;

void printTitle();

int main() {
	char startIn;
	printTitle();
	cin >> startIn;
	if (startIn == 'y') {
		//start the testbench
	}
	return 0;
}

void printTitle() {
	cout << "...................................." << endl;
	cout << "......__...__..__..______...____...." << endl;
	cout << "...../  |./  |.| |.| __  \./ ___|..." << endl;
	cout << "..../   |/   |.| |.| |_| |.\ \__...." << endl;
	cout << ".../         |.| |.|  ___/..\__ \..." << endl;
	cout << "../  /|   /| |.| |.| |......__| |..." << endl;
	cout << "./__/ |__/ |_|.|_|.|_|.....|____/..." << endl;
	cout << "...................................." << endl;
	cout << "SULEIMAN MASHINI - IONUT MOTOI - VICTOR SANCHEZ" << endl << endl;
	cout << "Start TestBench? (y/n)" << endl;
}