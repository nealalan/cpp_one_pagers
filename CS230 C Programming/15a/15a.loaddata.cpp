//***************************************************************************************
// Neal A. Dreher         Apr 25, 2000
// CMPSC230               Tues. 6:00
// Page 15.30             Problem 15A

#include "15a.h"

int loaddata(STUREC* ptrrec) {

	STUREC* ptrthisrec = ptrrec;
	STUREC* ptrlastrec = ptrrec + MAXSTUDENTS;
	
	while (ptrthisrec < ptrlastrec && scanf("%d %20c %lf", 
		&ptrthisrec -> id, 
		ptrthisrec -> name,
		&ptrthisrec -> rawscore) == 3) {

		ptrthisrec -> name[STUNAMELEN - 1] = 0;
		ptrthisrec++;
	}

	return ptrthisrec - ptrrec;
}
