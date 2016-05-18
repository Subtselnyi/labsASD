#include <stdio.h>
#include <string.h>
#define Nmax 1000
#include <cctype>

using namespace std;

enum Signals { sg0, sg1, sg2, nSg };
enum States { S1=1, S2, S3, S4, S5, S6, S7, nS};
int mkSignal(char);

int matrState[nS][nSg] = {
    {nS, nS, nS},//0
	{S6, S6, S4},//1
	{S5, S3, S5},//2
	{S5, S3, S7},//3
	{S6, S6, S6},//4
	{S1, S2, S7},//5
	{S2, S2, S7},//6
	{S1, S1, S4},//7
};

void newState(int& state, char signal) {
	state = matrState[state][mkSignal(signal)];
}

int mkSignal(char ch) {
	if (isalpha(ch)) return 0;
	if (isdigit(ch)) return 1;
	return 2;
}


int main() {
	int signal, state = S1;
	char ch[Nmax];

	printf("State: %3d\n", state);

	while (true) {
		printf("Input next char: ");
		gets(ch);
		newState(state, ch[0]);
		printf("State: %3d\n", state);
	}
	return 0;
}
