//***************************************************************************************
// Neal A. Dreher         Apr 11, 2000
// 13a.getansstu.cpp
//
//  gets the grades for each student
//***************************************************************************************
#include "13a.h"

void getansstu(char* ptransstu, int ansamounts) {

	char* ptransstuhere = ptransstu;

	// go past the student ID number
	for (int i=0; i<10; getchar(), i++);
	
	for (i=-2; i<ansamounts; *ptransstuhere++ = getchar(), i++) {
		
		if (*(ptransstuhere - 1) != 10 && // null char at end
			*(ptransstuhere - 1) != 65 && // a
			*(ptransstuhere - 1) != 66 && // b
			*(ptransstuhere - 1) != 67 && // c
			*(ptransstuhere - 1) != 68 && // d
			*(ptransstuhere - 1) != 69)   // e
			*(ptransstuhere - 1) = 70;	  // make else F
	} 
	return;
}