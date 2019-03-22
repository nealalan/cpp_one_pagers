//**************************************************************
// Neal A. Dreher         Feb. 22, 2000
// 9g.*.cpp 9g.h
//
// This file converts a letter into what it is supposed to be 
// offset to
//***************************************************************
#include "9g.h"

void convert_number(int innumber, int *ptrinchar) {

	while (innumber > 0) {  // do if need to loop around alphabet

		switch(*ptrinchar) {
		case 'a': case 'A':
			if (islower(*ptrinchar)) *ptrinchar = 'b'; if (isupper(*ptrinchar)) *ptrinchar = 'B';
			innumber--;
			if (innumber<=0) break;
		case 'b': case 'B':
			if (islower(*ptrinchar)) *ptrinchar = 'c'; if (isupper(*ptrinchar)) *ptrinchar = 'C';
			innumber--;
			if (innumber<=0) break;
		case 'c': case 'C':
			if (islower(*ptrinchar)) *ptrinchar = 'd'; if (isupper(*ptrinchar)) *ptrinchar = 'D';
			innumber--;
			if (innumber<=0) break;
		case 'd': case 'D':
			if (islower(*ptrinchar)) *ptrinchar = 'e'; if (isupper(*ptrinchar)) *ptrinchar = 'E';
			innumber--;
			if (innumber<=0) break;
		case 'e': case 'E':
			if (islower(*ptrinchar)) *ptrinchar = 'f'; if (isupper(*ptrinchar)) *ptrinchar = 'F';
			innumber--;
			if (innumber<=0) break;
		case 'f': case 'F':
			if (islower(*ptrinchar)) *ptrinchar = 'g'; if (isupper(*ptrinchar)) *ptrinchar = 'G';
			innumber--;
			if (innumber<=0) break;
		case 'g': case 'G':
			if (islower(*ptrinchar)) *ptrinchar = 'h'; if (isupper(*ptrinchar)) *ptrinchar = 'H';
			innumber--;
			if (innumber<=0) break;
		case 'h': case 'H':
			if (islower(*ptrinchar)) *ptrinchar = 'i'; if (isupper(*ptrinchar)) *ptrinchar = 'I';
			innumber--;
			if (innumber<=0) break;
				case 'i': case 'I':
			if (islower(*ptrinchar)) *ptrinchar = 'j'; if (isupper(*ptrinchar)) *ptrinchar = 'J';
			innumber--;
			if (innumber<=0) break;
		case 'j': case 'J':
			if (islower(*ptrinchar)) *ptrinchar = 'k'; if (isupper(*ptrinchar)) *ptrinchar = 'K';
			innumber--;
			if (innumber<=0) break;
		case 'k': case 'K':
			if (islower(*ptrinchar)) *ptrinchar = 'l'; if (isupper(*ptrinchar)) *ptrinchar = 'L';
			innumber--;
			if (innumber<=0) break;
		case 'l': case 'L':
			if (islower(*ptrinchar)) *ptrinchar = 'm'; if (isupper(*ptrinchar)) *ptrinchar = 'M';
			innumber--;
			if (innumber<=0) break;
		case 'm': case 'M':
			if (islower(*ptrinchar)) *ptrinchar = 'n'; if (isupper(*ptrinchar)) *ptrinchar = 'N';
			innumber--;
			if (innumber<=0) break;
		case 'n': case 'N':
			if (islower(*ptrinchar)) *ptrinchar = 'o'; if (isupper(*ptrinchar)) *ptrinchar = 'O';
			innumber--;
			if (innumber<=0) break;
		case 'o': case 'O':
			if (islower(*ptrinchar)) *ptrinchar = 'p'; if (isupper(*ptrinchar)) *ptrinchar = 'P';
			innumber--;
			if (innumber<=0) break;
		case 'p': case 'P':
			if (islower(*ptrinchar)) *ptrinchar = 'q'; if (isupper(*ptrinchar)) *ptrinchar = 'Q';
			innumber--;
			if (innumber<=0) break;
		case 'q': case 'Q':
			if (islower(*ptrinchar)) *ptrinchar = 'r'; if (isupper(*ptrinchar)) *ptrinchar = 'R';
			innumber--;
			if (innumber<=0) break;
		case 'r': case 'R':
			if (islower(*ptrinchar)) *ptrinchar = 's'; if (isupper(*ptrinchar)) *ptrinchar = 'S';
			innumber--;
			if (innumber<=0) break;
		case 's': case 'S':
			if (islower(*ptrinchar)) *ptrinchar = 't'; if (isupper(*ptrinchar)) *ptrinchar = 'T';
			innumber--;
			if (innumber<=0) break;
		case 't': case 'T':
			if (islower(*ptrinchar)) *ptrinchar = 'u'; if (isupper(*ptrinchar)) *ptrinchar = 'U';
			innumber--;
			if (innumber<=0) break;
		case 'u': case 'U':
			if (islower(*ptrinchar)) *ptrinchar = 'v'; if (isupper(*ptrinchar)) *ptrinchar = 'V';
			innumber--;
			if (innumber<=0) break;
		case 'v': case 'V':
			if (islower(*ptrinchar)) *ptrinchar = 'w'; if (isupper(*ptrinchar)) *ptrinchar = 'W';
			innumber--;
			if (innumber<=0) break;
		case 'w': case 'W':
			if (islower(*ptrinchar)) *ptrinchar = 'x'; if (isupper(*ptrinchar)) *ptrinchar = 'X';
			innumber--;
			if (innumber<=0) break;
		case 'x': case 'X':
			if (islower(*ptrinchar)) *ptrinchar = 'y'; if (isupper(*ptrinchar)) *ptrinchar = 'Y';
			innumber--;
			if (innumber<=0) break;
		case 'y': case 'Y':
			if (islower(*ptrinchar)) *ptrinchar = 'z'; if (isupper(*ptrinchar)) *ptrinchar = 'Z';
			innumber--;
			if (innumber<=0) break;
		case 'z': case 'Z':
			if (islower(*ptrinchar)) *ptrinchar = 'a'; if (isupper(*ptrinchar)) *ptrinchar = 'A';
			innumber--;
			if (innumber<=0) break;
		}
	}
	return;
}
