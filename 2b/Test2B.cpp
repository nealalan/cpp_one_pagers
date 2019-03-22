// Test2B.cpp -- tests enhanced Employee class

#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

int main()
    {
    cout << "Test2B\n" << endl;
    const Employee w, 
        x( 123456789, "Smith, Mary Lou", 12.34 ),
        y( 45678, "SMITH, MARY LOU", 17.50 ),
        z( 987, "Smite, William Robert Alexander Clarence Jonathon James", 7.89 );

    w.print( cout << "w = " ) << endl;
    x.print( cout << "x = " ) << endl;
    y.print( cout << "y = " ) << endl;
    z.print( cout << "z = " ) << endl;

    cout << fixed << setprecision(2) << boolalpha;
    cout << "w wage rate    = " << w.getWageRate() << endl;
    cout << "x wage rate    = " << x.getWageRate() << endl;
    cout << "y wage rate    = " << y.getWageRate() << endl;
    cout << "z wage rate    = " << z.getWageRate() << endl;
    cout << "w earnings(40) = " << w.earnings( 40 ) << endl;
    cout << "x earnings(40) = " << x.earnings( 40 ) << endl;
    cout << "y earnings(30) = " << y.earnings( 30 ) << endl;
    cout << "z earnings(50) = " << z.earnings( 50 ) << endl;
    cout << "w compare x    = " << w.nameCompare( x ) << endl;
    cout << "x compare w    = " << x.nameCompare( w ) << endl;
    cout << "x compare y    = " << x.nameCompare( y ) << endl;
    cout << "y compare x    = " << y.nameCompare( x ) << endl;
    cout << "x compare z    = " << x.nameCompare( z ) << endl;
    cout << "z compare x    = " << z.nameCompare( x ) << endl;
    cout << "y compare z    = " << y.nameCompare( z ) << endl;
    cout << "z compare y    = " << z.nameCompare( y ) << endl;

    return 0;
    }
