//***************************************************************************************
// Neal A. Dreher         Apr 18, 2000
// CMPSC230               Tues. 6:00
// Page 14.11             Problem 14A
//
// 14b.main.cpp
//
// converts a file of numbers to the output for 0-999
//***************************************************************************************
#include "14b.h"

void main(int argc, char *argv[]) {

        int done = 1;
        char nword[40];

		// this is if there is no input
		if (argc == 1) {
			printf("USAGE: 14B nnn [nnn...]\n");
			return;
		}

		while (done < argc) {
			// changes are char* number to int for processing
			int number = atoi(argv[done]);
            itowords(number, nword);
            printf("%3d  **%s**\n", number, nword);
			done++;
        }
        return;
}