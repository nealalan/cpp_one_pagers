//***************************************************************************************
// Neal A. Dreher         Apr 18, 2000
// CMPSC230               Tues. 6:00
// Page 14.8              Problem 14A
//
// 14a.main.cpp
//
// converts a file of numbers to the output for 0-999
//***************************************************************************************
#include "14a.h"

void main() {

	int x;
	char s[40];

	while (scanf("%d", &x) == 1) {
		itowords(x, s);
		printf("%3d  **%s**\n", x, s);
	}
	return;
}
