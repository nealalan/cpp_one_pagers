//***************************************************************************************
// Neal A. Dreher         Apr 25, 2000
// CMPSC230               Tues. 6:00
// Page 15.30             Problem 15A

#include "15a.h"

void printreport(STUREC* ptrrec, int amtstu, double avgscore, double standev) {

	STUREC* ptrthisrec = ptrrec;

	printf("                   STUDENT TEST GRADE REPORT\n\n");
	printf("   ID                               RAW     STANDARD      LETTER\n");
	printf(" NUMBER           NAME             SCORE      SCORE        GRADE\n\n");
	while(ptrthisrec->id != 0) {
		printf("%6d    %20s    %6.2f      %6.2f         %c\n",
			ptrthisrec->id, ptrthisrec->name, ptrthisrec->rawscore, ptrthisrec->stanscore, ptrthisrec->lettergrade);
		ptrthisrec++;
	}
	printf("\n%3d STUDENTS PROCESSED\n", amtstu);
	printf(" AVERAGE SCORE = %6.2f\n", avgscore);
	printf(" STANDARD DEVIATION = %5.2f\n", standev);

	return;
}