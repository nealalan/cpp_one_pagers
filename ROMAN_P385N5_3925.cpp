/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *	
	Neal A. Dreher	*  11 March 1999  *  P385 N5
	NOTE: this program is designed to input two Roman Numerals and 
		do the operation indicated and then output the answer
		(numbers are entered and printed as MMMMDDDDCCCCVVVVIIII and so on
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

#include <iostream.h>

int numberOne = 0;
int numberTwo = 0;
int numberTotal;
char inputMath;	// global to carry sign thru functions

void GetNumbers();	// get the romans & convert to human
void DoMath();		// do the + - * /
void Human2Roman(int); // convert human numbers to romans
void Finish();

// * * * * * * * * 

int main () {

	while (numberOne == 0 || numberTwo == 0) { GetNumbers(); }
	DoMath();
	Finish();

	return 0;
}

// * * * * * * * * 

void GetNumbers() {
	int number = 0;
	char inputChar;
	char lastChar = 'A';
	char redoChar = 'a';  // Determine if invalid inputChar needs restart
	// bool maxChar;

	cout << "Enter a Roman Number: ";
		cin.get(inputChar);
		cout << endl;

	while (inputChar != '\n') {

		switch (inputChar) {
			case 'I' : 
				number = number + 1; 
				break;
			case 'V' : 
				number = number + 5; 
				break;
			case 'X' : 
				number = number + 10; 
				break;
			case 'L' : 
				number = number + 50; 
				break;
			case 'C' : 
				number = number + 100; 
				break;
			case 'D' : 
				number = number + 500; 
				break;
			case 'M' : 
				number = number + 1000; 
				break;
			case 'Z' :
				number = 0;
				inputChar = '\n';
				break;
		}	// end switch

		lastChar = inputChar;

		if (inputChar != '\n') {
			cin.get(inputChar);
		}
	}

	if (numberOne == 0) {
		numberOne = number;
		cout << "The first number is " << numberOne << endl;
		cout << endl;
	}
	else {
		numberTwo = number;
		cout << "The second number is " << numberTwo << endl;
		cout << endl;
	}

}	// end GetNumbers()

// * * * * * * * * 

void DoMath() {

	cout << "Enter desired Math (+, -, *, /): ";
		cin >> inputMath;
		cout << endl;

	switch (inputMath) {
		case '+' : 
			numberTotal = numberOne + numberTwo; 
			break;
		case '-' : 
			numberTotal = numberOne - numberTwo;
			break;
		case '*' :
			numberTotal = numberOne * numberTwo;
			break;
		case '/' :
			numberTotal = numberOne / numberTwo;
			break;
	} // end switch

} // end DoMath()

// * * * * * * * * 

void Human2Roman(int x) { // watch for - numbers

	if (x < 0) {
		x = x * -1; // make - numbers pos for conversion
		cout << "-";// output '-' to simulate negative roman number
	}
	while (x >= 1000) {
		cout << 'M';
		x = x - 1000;
	}
	while (x >= 500) {
		cout << 'D';
		x = x - 500;
	}
	while (x >= 100) {
		cout << 'C';
		x = x - 100;
	}
	while (x >= 50) {
		cout << 'L';
		x = x - 50;
	}
	while (x >= 10) {
		cout << 'X';
		x = x - 10;
	}
	while (x >= 5) {
		cout << 'V';
		x = x - 5;
	}
	while (x >= 1) {
		cout << 'I';
		x = x - 1;
	}

	x = 0;
}

// * * * * * * * * 

void Finish() {
	cout << "The answer to ";
	Human2Roman(numberOne);
	cout << ' ' << inputMath << ' ';
	Human2Roman(numberTwo);
	cout << " is "; 
	Human2Roman(numberTotal);
	cout << " (" << numberTotal << ")" << endl << endl;
}