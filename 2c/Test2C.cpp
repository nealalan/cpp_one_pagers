// Test2C.cpp -- tests Employee class operators

#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

int main()
    {
    cout << "Test2C\n" << endl;
    const Employee w, 
        x( 123456789, "Smith, Mary Lou", 12.34 ),
        y( 45678, "SMITH, MARY LOU", 17.50 ),
        z( 987, "Smite, William Robert Alexander Clarence Jonathon James", 7.89 );

    cout << "w = " << w << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    cout << fixed << setprecision(2) << boolalpha;
    cout << "w * 40 = " << (w * 40 ) << endl;
    cout << "40 * x = " << (40 * x ) << endl;
    cout << "y * 30 = " << (y * 30 ) << endl;
    cout << "z * 50 = " << (z * 50 ) << endl;
    cout << "x <  y    = " << (x < y) << endl;
    cout << "x == y    = " << (x == y) << endl;
    cout << "y <  x    = " << (y < x) << endl;
    cout << "x <  z    = " << (x < z) << endl;
    cout << "x == z    = " << (x == z) << endl;
    cout << "z <  x    = " << (z < x) << endl;
    cout << "y <  z    = " << (y < z) << endl;
    cout << "y == z    = " << (y == z) << endl;
    cout << "z <  y    = " << (z < y) << endl;

    return 0;
    }
