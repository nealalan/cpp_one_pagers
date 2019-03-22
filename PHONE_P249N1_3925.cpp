/*  Neal A. Dreher
	11 Feb 1999
	p249 n1
	Purpose: Input letter for phone number and tell what number it is.
	Note: MUST USE CAPS
	*/

#include <iostream.h>

char letterIn;
int numberOut;

main ()	{
	cout << endl;
	cout << "NOTE: PLEASE USE CAPITAL LETTERS" << endl;
	cout << endl;
	cout << "Enter a letter and I will tell you the number it is on the telephone. ";
	cin >> letterIn;
	cout << endl;

	switch (letterIn) { 
		case 'A' :
		case 'B' :
		case 'C' : numberOut = 2; break;
		case 'D' :
		case 'E' : 
		case 'F' : numberOut = 3; break;
		case 'G' :
		case 'H' :
		case 'I' : numberOut = 4; break;
		case 'J' :
		case 'K' :
		case 'L' : numberOut = 5; break;
		case 'M' :
		case 'N' :
		case 'O' : numberOut = 6; break;
		case 'P' :
		case 'R' :
		case 'S' : numberOut = 7; break;
		case 'T' :
		case 'U' :
		case 'V' : numberOut = 8; break;
		case 'W' :
		case 'X' :
		case 'Y' : numberOut = 9; break;
		case 'Q' :
		case 'Z' : numberOut = 0; break;
	}

	if (numberOut == 0) {
		cout << "The letter " << letterIn << " is not on the telephone." << endl; 
	}
	else {
		cout << "The letter " << letterIn << " is " << numberOut << " on the telephone." << endl;
	}

	cout << endl;
	return 0;
}

