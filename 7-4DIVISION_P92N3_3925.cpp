// 7 and 4 should be named constants
// example: const int NUM1 = 7;

/*  Neal A. Dreher
	Jan 28 1999
	p92 #3
	*/
#include <iostream.h>
#include <math.h>

main ()
{
	int intNumbers;
	float flpNumbers;
	float modNumbers;
	intNumbers = 7/4;
	flpNumbers = 7.0 / 4.0;
	modNumbers = 7 % 4;
	cout << "7/4 using integer division equals " << intNumbers << "." << endl;
	cout << "7/4 using floating point division equals " << flpNumbers << "." << endl;
	cout << "7 modulo 4 equals " << modNumbers << "." << endl;
	return 0;
}
/* made vars for each number needed and did the problem 

*/