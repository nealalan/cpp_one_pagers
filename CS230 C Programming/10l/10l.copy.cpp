//***************************************************************************************
//  10l.copy.cpp
//  makes a copy of what is in one array to another array
//***************************************************************************************
#include "10l.h"

void copy(int *ptry, int *ptrx, int count) { for (int *ptrendx = ptrx + count; ptrx < ptrendx; *ptry++ = *ptrx++); }
