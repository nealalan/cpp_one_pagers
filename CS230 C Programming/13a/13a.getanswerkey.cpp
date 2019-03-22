//***************************************************************************************
// Neal A. Dreher         Apr 11, 2000
// 13a.getanswerkey.cpp
//
//  gets the answer key out of the input file
//***************************************************************************************
#include "13a.h"


int getanswerkey(char* ptranskey) {

	char* ptranskeyhere = ptranskey;

	// ignores the leading 0's that show answer key
	for (int i=0; i<10; getchar(), i++);

	while ((*ptranskeyhere = getchar()) != 10) ptranskeyhere++;
	// return the amount of answers that were read in
	return ptranskeyhere - ptranskey - 1;
}