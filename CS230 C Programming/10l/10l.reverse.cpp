//***************************************************************************************
// reverses the whole array to a mirror image

#include "10l.h"

void reverse(int *ptrx, int count) {
	int temp;
 //	if (count % 2 != 0) count--;
	int *ptrxthere = (ptrx + count - 1);




	while (ptrx < ptrxthere) {
		temp = *ptrx;            //  store here
		*ptrx = *ptrxthere;  //  put what's there in here
		*ptrxthere = temp;   //  put what's in temp there because it's here 
		ptrx++;
		ptrxthere--;
	
	}

}
