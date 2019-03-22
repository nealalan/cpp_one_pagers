///**************************************************************
// Neal A. Dreher         Feb. 29, 2000
// CMPSC230               Tues. 6:00
// Page 9.16              Problem 9F
//
//***************************************************************

#include <stdio.h>


void main() {

	int here = 0, there = 0;

	while ((here = getchar()) != EOF) {  // creates the entire loop while input

		if (here == '*' && there == '/') {

			printf("/*");
			do {
				there = getchar();
				putchar(there);
				here = getchar();
				putchar(here);
			} while (there != '*' && here != '/');
		}
		else if (here == '"') {
			do {
				here = getchar();
				if (here == '\\') {
					getchar();
//					continue;
				}
			} while (here != '"');
		}
		else if (here == '\'') {

			do {
				here = getchar();
				if (here == '\\') {
					getchar();
//					continue;
				}
			} while (here != '\'');
		}
		there = here;

		}
	return;
}