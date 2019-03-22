//***************************************************************************************
// Neal A. Dreher         Apr 25, 2000
// CMPSC230               Tues. 6:00
// Page 15.30             Problem 15A

#include "15a.h"

void stugrade(STUREC* ptrrec, int amtstu) {

	STUREC* ptrthisrec = ptrrec;
	STUREC* ptrlastrec = ptrrec + amtstu;

	while(ptrthisrec < ptrlastrec) {
		char letgrade;

		if (ptrthisrec->stanscore < -1.0) ptrthisrec->lettergrade = 'F';
		else if (ptrthisrec->stanscore >= -1.0 && ptrthisrec->stanscore < -0.5) ptrthisrec->lettergrade = 'D';
		else if (ptrthisrec->stanscore >= -0.5 && ptrthisrec->stanscore <= .5) ptrthisrec->lettergrade = 'C';
		else if (ptrthisrec->stanscore > 0.5 && ptrthisrec->stanscore <= 1) ptrthisrec->lettergrade = 'B';
		else if (ptrthisrec->stanscore > 1) ptrthisrec->lettergrade = 'A';


		ptrthisrec++;
	}
	return;
}