//***************************************************************************************
// Neal A. Dreher         Oct 4, 2000
// CMPSC232               Wednesday 6:00
// Program 5              WinNT4, VC6
//
// 5.main.cpp    a Distance Class
//
//***************************************************************************************

#include "5.main.h"

void main() {

	// the following is test data to play around and make sure 
	// that the class Distance is working correctly

	Distance a, b(1000.), c(100L, 50L, 8L), d(10, 11), f(1.23);

	a.SetDistance(1234.);

	cout << "1234 mm equals " << a.MtoE() << " feet\n";
	cout << "Testing GetDistance for object a - 1234 mm = " << a.GetDistance() << " mm\n";

	a = b;
	cout << "a sould now be the same as b:\n";
	cout << "a: ";
	a.Paint('M');
	cout << "b: ";
	b.Paint('M');

	a = fun(c);
	cout << "a should now be the same as c:\n";
	a.Paint('M');
	c.Paint('M');

	return;
}

// even more ways to play around and test!
Distance fun(const Distance &x) {

	Distance y, z;
	cout << "fun: passed value: ";
	x.Paint('M');
	y = z = x;
	y.SetDistance(1234.);
	cout << "fun: altered value: ";
	y.Paint('M');

	return z;
}
