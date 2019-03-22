//***************************************************************************************
//  10l.rotate_right.cpp
//  rotates all numbers in the array that contains count right one and wraps end around 
//  to begining
//***************************************************************************************
void rotate_right(int *ptrx, int count) {

	int *ptrxbegin = ptrx;
	int *ptrxhere = ptrx + (count - 1);
	int temp = *(ptrx + (count - 1));

	while (ptrxhere > ptrxbegin) *ptrxhere-- = *(ptrxhere - 1);

	*ptrxhere = temp;


}