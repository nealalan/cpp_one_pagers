//***************************************************************************************
// Neal A. Dreher         Mar. 28, 2000
// CMPSC230               Tues. 6:00
// Page 10.42             Problem 10K
//
// 10k.main.cpp
// 
//***************************************************************************************

#include <stdio.h>
#include <stdlib.h>

#define LIMIT 20
#define BUFFERSIZE (4 * LIMIT)

int loaddata(int x[], int limit);
void list(int buffer[], int buffersize);
void copy(int y[], int x[], int count);
void rotate_right(int x[], int count);
void rotate_left(int x[], int count);
void reverse(int x[], int count);

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
//***************************************************************************************
//  input the data making sure that you are not bring in more than is allowed
//  error check for bad data and error check for too many numbers brought in
int loaddata(int x[], int limit) {

        int retcd = 0, index = 0, crap = 0;

        while( (index < limit) && (retcd = scanf ("%d", &x[index])) == 1 ) index++;

        if (retcd == 0) {
                printf("Bad data after grade number %d\n", index);
                exit(1);
        }
        if (index == limit && scanf(" %d", &crap) != EOF) {
                printf("Too many numbers read in - max is: %d\n", limit);
                exit(2);
        }
        return index;
}
//***************************************************************************************
// print out the data with LIMIT around of data on a line only bring in the buffer
void list(int buffer[], int buffersize) {

        int printed = 0;

		while (printed < buffersize) {
			if (printed % LIMIT == 0) printf("\n");  // wrap to next line 
			printf("%3d", buffer[printed++]); 
        }
		printf("\n");  // put in a blank line after the buffer printout 
        return;
}
//***************************************************************************************
//  makes a copy of what is in one array to another array
void copy(int y[], int x[], int count) { for (int at = 0; at < count; y[at] = x[at], at++);}

//***************************************************************************************
//  rotates all numbers right one and wraps end around to begining
void rotate_right(int x[], int count) {
	count--;                                      // minus count one to account for [0]
	int temp = x[count];                          // save the last number for wrap around
	while (count > 0) x[count--] = x[count - 1];  // move array down by one and dec for next loop
	x[count] = temp;                              // wrap end of array around to begining by 1  
}
//***************************************************************************************
//  rotates all numbers left one and wraps begining around to end
void rotate_left(int x[], int count) {
	int at = 0, temp = x[at];
	while (at < count) x[at++] = x[at + 1];       // move array down one and dec for next loop
	x[at - 1] = temp;                             // put the first number, in temp as last 
}
//***************************************************************************************
// reverses the whole array to a mirror image
void reverse(int x[], int count) {
	int at = 0, temp = 0, move = (int)(count-- * .5);
	while (move >= at) {                      
		temp = x[count - at];                     // saves the left mirror in temp
		x[count - at] = x[at];                    // move what's in the right side to left
		x[at++] = temp;                           // moves what was in left to the right side
	}
}
