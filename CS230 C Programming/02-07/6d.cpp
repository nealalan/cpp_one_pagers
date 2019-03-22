///**************************************************************
// Neal A. Dreher         Feb. 15, 2000
// CMPSC230               Tues. 6:00
// Page 6.9               Problem 6D
//
// This program inputs a positive integer and outputs the 
// factorial of that integer.
// LIMITS: CAN NOT USE IF STATEMENT
//***************************************************************

#include <stdio.h>

int main() {

	int inNumber;      // gets the number that is going to be factorialized
	long factorial=1;  // the factorial starting with 1 to make 0!=1

	printf("\nEnter a positive number: ");  // get the number
	scanf("%d", &inNumber);

	// do the math to figure out that factorial
	for(int mult=1; mult<=inNumber; factorial*=mult, mult++);

	// show the output of the factorial in #! = # form
	printf("%d! = %ld\n\n", inNumber, factorial);

	return 0;
}

/*

Enter a positive number: 7
7! = 5040

Press any key to continue


Enter a positive number: 1
1! = 1

Press any key to continue

Enter a positive number: 10
10! = 3628800

Press any key to continue

Enter a positive number: 0
0! = 1

Press any key to continue

*/