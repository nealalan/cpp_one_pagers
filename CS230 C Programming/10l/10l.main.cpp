//***************************************************************************************
// Neal A. Dreher         Mar. 28, 2000
// CMPSC230               Tues. 6:00
// Page 10.43             Problem 10L
//
// 10l.main.cpp
// 
//***************************************************************************************

#include "10l.h"

int main() {

        int buffer[BUFFERSIZE] = {0}, *ptrx, *ptry, count;

        ptrx = buffer + LIMIT;
        ptry = ptrx + LIMIT;
        
        count = loaddata(ptrx, LIMIT);
        list(buffer, BUFFERSIZE);
        copy(ptry, ptrx, count);
        list(buffer, BUFFERSIZE);
        rotate_right(ptrx, count);
        list(buffer, BUFFERSIZE);
        rotate_left(ptrx, count);
        list(buffer, BUFFERSIZE);
        reverse(ptrx, count);
        list(buffer, BUFFERSIZE);

        return 0;
}
