//***************************************************************************************
//  rotates all numbers left one and wraps begining around to end

#include "10l.h"

void rotate_left(int *ptrx, int count) {

	int *ptrxend = ptrx + (count -1);
	int temp = *ptrx;

	while (ptrx < ptrxend) *ptrx++ = *(ptrx + 1);  // move array down one and dec for next loop                                         
	*ptrx = temp;                                 // put the first number, in temp as last 
}