//***************************************************************************************
// Neal A. Dreher         Apr 25, 2000
// CMPSC230               Tues. 6:00
// Page 15.30             Problem 15B

#include "15b.h"


void stuscore(STUREC* ptrrec, int amtstu, double avgscore, double standev) {
        
        STUREC* ptrthisrec = ptrrec;
        STUREC* ptrlastrec = ptrrec + amtstu;
        double score;

        while(ptrthisrec < ptrlastrec) {
                score  = (ptrthisrec->rawscore - avgscore) / standev;
                ptrthisrec->stanscore = score;
                ptrthisrec++;
        }
        return;
}