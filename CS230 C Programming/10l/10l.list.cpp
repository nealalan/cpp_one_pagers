//***************************************************************************************
// 10l.list.cpp
// print out the data with LIMIT around of data on a line only bring in the buffer
//***************************************************************************************
#include "10l.h"

void list(int *ptrbuffer, int buffersize) {

        int printed = 0;
		int *ptrbufferend = ptrbuffer + buffersize;

		while (ptrbuffer < ptrbufferend) {
			if ((ptrbufferend - ptrbuffer) % 20 == 0) printf("\n");  // wrap to next line 
			printf("%3d", *ptrbuffer++); 
        }
		printf("\n");  // put in a blank line after the buffer printout 
        return;
}