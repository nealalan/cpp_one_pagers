//***************************************************************************************
// Neal A. Dreher         Apr 25, 2000
// CMPSC230               Tues. 6:00
// Page 15.30             Problem 15B

#include "15b.h"

void printreport(STUREC* ptrrec, int amtstu, double avgscore, double standev, char r) {

        STUREC* ptrthisrec = ptrrec;
        STUREC* ptrlastrec = ptrrec + amtstu;

        printf("                   STUDENT TEST GRADE REPORT\n\n");
        printf("   ID                               RAW     STANDARD      LETTER\n");
        printf(" NUMBER           NAME             SCORE      SCORE        GRADE\n\n");
        if (r == ' ') {  // if 'r' is blank then no reverse statement was in the command line, so just print it how it is in the array
			while(ptrthisrec < ptrlastrec) {
                printf("%6d    %20s    %6.2f      %6.2f         %c\n",
                        ptrthisrec->id, ptrthisrec->name, ptrthisrec->rawscore, ptrthisrec->stanscore, ptrthisrec->lettergrade);
                ptrthisrec++;
			}
		}
		else {
			ptrlastrec--;  // get rid on the last student that prints nothing but 0's
			while(ptrthisrec < ptrlastrec) {
                printf("%6d    %20s    %6.2f      %6.2f         %c\n",
                        ptrlastrec->id, ptrlastrec->name, ptrlastrec->rawscore, ptrlastrec->stanscore, ptrlastrec->lettergrade);
                ptrlastrec--;
			}
		}
        printf("\n%3d STUDENTS PROCESSED\n", amtstu);
        printf(" AVERAGE SCORE = %6.2f\n", avgscore);
        printf(" STANDARD DEVIATION = %5.2f\n", standev);

        return;
}