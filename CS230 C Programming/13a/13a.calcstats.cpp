//***************************************************************************************
// Neal A. Dreher         Apr 11, 2000
// 13a.calcstats.cpp
//
//  calculate the answers that were chosen by all the student by question # and letter
//***************************************************************************************
#include "13a.h"

int calcstats(char* ptransstu, int* anscounts) {

	char* ptransstuhere = ptransstu;
	int place, question = 0;

	// read in the answers till after the last one
	while (*ptransstuhere != 10) {

		// figure the choice and put it in storage by 
		//  anscounts[question#][0-5 according to choice]
		switch (*ptransstuhere) {
		case 65:
			place = 0;  // a
			break;
		case 66:
			place = 1;  // b
			break;
		case 67:
			place = 2;  // c
			break;
		case 68:
			place = 3;  // d
			break;
		case 69:
			place = 4;  // e
			break;
		case 70: 
			place = 5;  // f (everything else)
			break;
		}

		// inc the array (according to ques and letter)
		anscounts[place] += 1;
		anscounts += POSSIBLE_ANSWERS;

		ptransstuhere++;  // go to next ans mem location and grade
	}
	return ptransstuhere - ptransstu;
		
}