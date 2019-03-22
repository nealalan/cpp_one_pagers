/*  Neal A. Dreher
	17 Feb 1999
	p250 n5
	PURPOSE: find the AREA, DIAMETER or CIRCUMFERENCE of a circle with given radius.
	*/

#include <iostream.h>
#include <iomanip.h>

char circFunction;
float circRadius;
double circArea, circCircum, circDiameter;
const double pi = 3.14159;
bool progExit = false;

void main () {
	
	cout << "I can calculate circles for you!";

	cout.setf(ios::fixed, ios::floatfield);  // Floating Point
	cout.setf(ios::showpoint);				 // output form
	
	while (progExit == false) {

		cout << endl << endl << "Here is what I can do" << endl << "     A : Find the area" << endl << "     C : Find the circumference" << endl << "     D : Find the diameter" << endl << "     X 0 : To exit" << endl << endl << "Please indicate in the following format: A 6.25" << endl << endl << "     ";

		cin >> circFunction >> circRadius;

		if (circFunction == 'A' || circFunction == 'a') {
			circArea = pi * (circRadius * circRadius);
			cout << "The area of a circle with a radius of " << circRadius << " is " << setprecision(2) << circArea << endl;
			progExit = true;
		}
		else if (circFunction == 'C' || circFunction == 'c') {
			circCircum = 2 * (pi * circRadius);
			cout << "The circumference of a circle with a radius of " << circRadius << " is " << setprecision(2) << circCircum << endl;
			progExit = true;
		}
		else if (circFunction == 'D' || circFunction == 'd') {
			circDiameter = 2 * circRadius;
			cout << "The diameter of a circle with a radius of " << circRadius << " is " << setprecision(2) << circDiameter << endl;
			progExit = true;
		}
		else if (circFunction == 'X' || circFunction == 'x') {
			progExit = true;
		}
		else {
			cout << "Please input a valid letter" << endl;
			progExit = false;
			circFunction = 0;
			circRadius = 0;
		}  // end circFunction

	}  // end while to quit program

}