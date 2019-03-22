/*	Neal A. Dreher
	18 Feb 1998
	P319 N2
*/

#include <iostream.h>

int inNumber;		// User input number 
int loopNumber;		// Counts the numbers up to inNumber and cont's process
int numberSum;		// Keeps track of sum till loop finish and output

main () {

	numberSum = 0;
	loopNumber = 0;
	
	cout << endl << "Please input a number that is larger than 1: ";
	cin >> inNumber;
	cout << endl << "** Input ** Sums **" << endl;

	while (inNumber > loopNumber) {

		loopNumber = loopNumber + 1;
		numberSum = numberSum + (loopNumber * loopNumber);

		cout << loopNumber << " " << numberSum << endl;

	}

	cout << endl << "The sum of all the numbers from 1 to " << inNumber << " squared is " << numberSum << endl;
	
	return 0;

}