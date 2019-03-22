//***************************************************************************************
// Neal A. Dreher         Apr 4, 2000
// 11p.show.cpp
//***************************************************************************************

#include "11p.h"

void show(char *s, int n) {

	for (int i=0, j=128; i < n; i++, j++) {
		if (((unsigned char *)s)[i] == j) putchar(' ');
		else if (s[i]) putchar(s[i]);
		else putchar('^');	
	}
	putchar('\n');
	
}
