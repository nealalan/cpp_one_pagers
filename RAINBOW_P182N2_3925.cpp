/*  Neal A. Dreher
	Feb 04 1999
	p183 #2
	*/
#include <iostream.h>
#include <math.h>

main ()
{
	double distanceToRainbow;
	double radians, height;
	const double pi = 3.14159265;
	const double degrees = 42.3333333;

	cout << endl;	
	cout << "How far are you from the rainbow? ";
	cin >> distanceToRainbow;

	radians = degrees * (pi/180.0);				// convert degrees of eyes to rainbow to radians
	height = tan(radians) * distanceToRainbow;	// figure the height w/ the given distance

	cout << endl;								// add space to screen
	cout << "Given that the distance to the rainbow is " << endl;
	cout <<	distanceToRainbow << " the height of the rainbow is " << height << '.';
	cout << endl;

	return 0;
}
/*

*/
