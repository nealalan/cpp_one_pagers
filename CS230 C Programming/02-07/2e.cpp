//***************************************************************
// Neal A. Dreher          Feb 01, 2000
// CMPSC230                Tues. 6:00
// Page 2.19               Problem 2E
// 
// Write a Program to input two integers then output their 
// difference and their product.
//***************************************************************

#include <stdio.h>

int main() {
	int number1, number2;  // numbers to get
 int sum, difference;   // calculated numbers

	printf("Input two integers: ");       // ask for the numbers
	scanf("%d %d", &number1, &number2);   // get the numbers and put them in memory

	difference = number1 - number2;       // figure out the difference answer
	sum = number1 * number2;              // figure out the sum answer

	printf("\n%8d%13d\n-%7d     *%7d\n", number1, number1, number2, number2);
	printf("--------     --------\n");
	printf("%8d%13d\n\n", difference, sum); 

	return 0;

}



Input two integers: -1234 2

   -1234        -1234
-      2     *      2
--------     --------
   -1236        -2468

Press any key to continue
