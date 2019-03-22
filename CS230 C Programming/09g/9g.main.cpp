//**************************************************************
// Neal A. Dreher         Feb. 29, 2000
// CMPSC230               Tues. 6:00
// Page 9.19              Problem 9G
//
// 9g.*.cpp 9g.h
//
// This program performs a Caesar cipher.
//***************************************************************
#include "9g.h"

int main() {

	int inchar,                        // takes one char at a time
		innumber;                      // the amount to offset

	scanf("%d", &innumber);            // gets amount to offset
	printf("%d", (innumber * (-1)));   // puts recip in output
	
	// converts any negative offsets to pos to make usable
	if(innumber < 0) while(innumber < 26) innumber += 26;

	// gets inchar from file and converts or reprints
	while((inchar = getchar()) != EOF) {
		if (isalpha(inchar)) {                   // is an alpha
			convert_number(innumber, &inchar);   // funtion to convert
			printf("%c", inchar);
		} else putchar(inchar);                  // not an alpha
	}
	return 0;
}