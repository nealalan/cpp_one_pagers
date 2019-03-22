//***************************************************************************************
//  10l.loaddata.cpp
//  input the data making sure that you are not bring in more than is allowed
//  error check for bad data and error check for too many numbers brought in
//***************************************************************************************
#include "10l.h"

int loaddata(int *ptrx, int limit) {

	int *ptrhere = ptrx;
	int *ptrlast = ptrx + limit;
	int retcd = 0, crap = 0;

    while( (ptrhere < ptrlast) && (retcd = scanf(" %d", ptrhere)) == 1 ) ptrhere++;

        if (retcd == 0) {
                printf("Bad data after grade number %d\n", (ptrlast - ptrhere) / 4);
                exit(1);
        }
        if ((ptrhere - limit) == ptrx && scanf(" %d", &crap) != EOF) {
                printf("Too many numbers read in - max is: %d\n", limit);
                exit(2);
        }
        return ptrhere - ptrx;
}