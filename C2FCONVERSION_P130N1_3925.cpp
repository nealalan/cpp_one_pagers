// formula wrong

/*  Neal A. Dreher
	Jan 28 1999
	p92 #3
	*/
#include <iostream.h>
#include <math.h>

main ()
{
	float inTemp;
	// int intInTemp;
	float calcTemp;
	cout << "Please enter a temperature in degrees C: ";
	cin >> inTemp;
	calcTemp = inTemp*5/9;
	calcTemp = calcTemp + 32;
	// intInTmp = inTemp; // convert the inTemp to a whole temp if not entered that way
	cout;
	cout << inTemp << " degrees C is equal to " << calcTemp << " degrees F." << endl;
	
	return 0;
}
/* made vars for each number needed and did the problem 

*/
