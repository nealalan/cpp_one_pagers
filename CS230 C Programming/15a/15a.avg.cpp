//***************************************************************************************
// Neal A. Dreher         Apr 25, 2000
// CMPSC230               Tues. 6:00
// Page 15.30             Problem 15A

#include "15a.h"

double avg(STUREC* ptrrec, int amtstu) {

	STUREC* ptrthisrec = ptrrec;
	STUREC* ptrlastrec = ptrrec + amtstu;
	double all = 0;

	while (ptrthisrec < ptrlastrec) all += ptrthisrec++->rawscore;

	return (all / (amtstu * 100)) * 100;
}
