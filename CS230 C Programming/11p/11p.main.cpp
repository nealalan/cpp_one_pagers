//***************************************************************************************
// Neal A. Dreher         Apr 4, 2000
// CMPSC230               Tues. 6:00
// Page 11.45             Problem 11P
//
// 1lp.main.cpp
//
// This program reads an input file and by the given offset and count of the to-be-removed
// word, edits the word out and inputs the new word.
//***************************************************************************************

#include "11p.h"

void main(void) {

	char s[80], *s1=s+5, *s2=s+55;
	int count, ofs, n;

	set(s, sizeof(s));
	while ((n = scanf("%s%d%d%s", s1, &ofs, &count, s2)) == 4) {

		printf ("offset=%d  count=%d\n", ofs, count);
		show(s, 79);
		if (s1 != stringdelete(s1, ofs, count)) printf("delete return error\n");
		show(s, 79);
		if (s1 != stringinsert(s1, ofs, s2)) printf("insert return error\n");
		show(s, 79);
		printf("\n");
		set(s, sizeof(s));
	}

	if (n != EOF) printf ("\n\n***** Format error in input *****\n");
}


