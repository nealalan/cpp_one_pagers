//***************************************************************************************
// Neal A. Dreher         Apr 4, 2000
// 1lp.stringdelete.cpp
//***************************************************************************************

#include "11p.h"

char *stringinsert(char *ptrs1, int ofs, char *ptrs2) {

	int ptrs1len = strlen(ptrs1);
	int ptrs2len = strlen(ptrs2);
	char *addstart = ptrs1 + ofs;   // the place where the the ptrs2 is put
		if (ofs > ptrs1len) addstart = ptrs1 + ptrs1len;

	// go to the end of the string (count already removed) + the added word
	char *here = ptrs1 + ptrs1len + ptrs2len;

	// figures the true end of the ptr
	char *ptrsend = ptrs1 + ptrs1len + ptrs2len;

	// create the space for ptrs2
	while (here >= addstart) *here-- = *(here - ptrs2len);

	// put the word in the space
	while (*ptrs2 != 0) *addstart++ = *ptrs2++;

	// hard sets the last char of new string to null
	*ptrsend = 0;

	return ptrs1;
}