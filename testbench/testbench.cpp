#define PIPE_READ 0
#define PIPE_WRITE 1

#include <iostream>
#include <uninstd.h>
#include <sys/types.h>

using namespace std;

void printTitle();
//references for Piping taken from 
//stackoverflow.com/questions/9405985/linux-3-0-executing-child-process-with-piped-stdin-stdout
int runSimulator(const char* szCommand, char* const Arguments[], char* const Environment[], const char* szMessage);
int main() {
	char startIn;
	printTitle();
	cin >> startIn;
	if (startIn == 'y') {
		//start the testbench
	}
	return 0;
}



int runSimulator(const char* szCommand, char* const Arguments[], char* const Environment[], const char* szMessage) {
	int StdinPipe[2];
	int StdoutPipe[2];
	int ChildCheck;
	char nChar;
	int nResult;
	//initialise Pipes
	if (pipe(StdinPipe) < 0) {
		cerr << "IN PIPE FAILED TO INITIALIZE" << endl;
		return -1;
	}
	if (pipe(StdoutPipe) < 0) {
		cerr << "OUT PIPE FAILED TO INITIALIZE" << endl;
		close(aStdinPipe[PIPE_READ]);
		close(aStdinPipe[PIPE_WRITE]);
		return -1;
	}
	ChildCheck = fork();
	if (ChildCheck == 0) {
		//child continues
		//redirect stdin
		if (dup2(StdinPipe[PIPE_WRITE], STDOUT_FILENO) == -1) {
			exit(errno);
		}
		//redirect stdout
		if (dup2(StdoutPipe[PIPE_WRITE], STDOUT_FILENO) == -1) {
			exit(errno);
		}
		//use by parent only
		close(StdinPipe[PIPE_READ]);
		close(StdinPipe[PIPE_WRITE]);
		close(StdoutPipe[PIPE_READ]);
		close(aStdoutPipe[PIPE_WRITE]);
		nResult = execve(szCommand, Arguments, Environment);
		exit(nResult);
	}
	else if (ChildCheck > 0) {
		// close unused file descriptors, these are for child only
		close(StdinPipe[PIPE_READ]);
		close(StdoutPipe[PIPE_WRITE]);
		// Include error check here
		if (NULL != szMessage) {
			write(StdinPipe[PIPE_WRITE], szMessage, strlen(szMessage));
		}
		//**********************************************
		// HERE IS WHERE THE INTERACTION HAPPENS
		//**********************************************

		// Just a char by char read here, you can change it accordingly
		while (read(StdoutPipe[PIPE_READ], &nChar, 1) == 1) {
			write(STDOUT_FILENO, &nChar, 1);
		}

		// done with these in this example program, you would normally keep these
		// open of course as long as you want to talk to the child
		close(StdinPipe[PIPE_WRITE]);
		close(StdoutPipe[PIPE_READ]);
	}
	else {
		// failed to start simulator
		close(StdinPipe[PIPE_READ]);
		close(StdinPipe[PIPE_WRITE]);
		close(StdoutPipe[PIPE_READ]);
		close(StdoutPipe[PIPE_WRITE]);
	}
	return ChildCheck;
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