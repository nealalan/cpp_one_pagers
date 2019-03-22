//***************************************************************************************
// Neal A. Dreher         Apr 25, 2000
// CMPSC230               Tues. 6:00
// Page 15.30             Problem 15B

#include "15b.h"

double dev(STUREC* ptrrec, int amtstu, double avgscore) {

        STUREC* ptrthisrec = ptrrec;
        STUREC* ptrlastrec = ptrrec + amtstu;
        double all = 0, difference;

        while (ptrthisrec < ptrlastrec) {
                // get the difference
                if (ptrthisrec->rawscore > avgscore) difference = sqrt(ptrthisrec->rawscore - avgscore);
                else difference = pow(ptrthisrec->rawscore - avgscore, 2);
                all += difference;
                ptrthisrec++;
        }

        return sqrt(all / amtstu);
}