//***************************************************************************************
// Neal A. Dreher         Nov 15, 2000
// CMPSC232               Wednesday 6:00
// Program 11             WinNT4, VC6
//
// 11.main.cpp    a Distance Class III
//
// REVISION 1:  Make the Distance class work, see REV 2
// REVISION 2:	This is a very weak and limited Distance class that inputs
//		A: Distance(Eng/Met, miles/mm);
//		B: Distance(Met, meters, cm, mm = 0);
//		C: Distance(Eng, feet, inches = 0);
//	It is also capable of storing array's of Distance objects called Path's and output 
//	these Path's in millimeter lengths
//
//***************************************************************************************

#include "11.main.h"

// these are just teacher derived test functions making sure that Distance and Path work
int main () {

 const Distance a1 (Distance::Metric, 1000.5);        // 1000.5 mm
 const Distance a2 (Distance::English, 1000.5);       // 1000.5 miles
 const Distance a3 (Distance::Metric, 100L, 8L, 6.3); // 100 m, 8 cm 6.3 mm
 const Distance a4 (Distance::English, 3L, 10.5);     // 3 ft, 10.5 in
 const Distance a5 (Distance::Metric, 10L, 1L);       // 10 m, 1 cm, 0 mm
 const Distance a6 (Distance::English, 5L);           // 5 ft, 0 inches

 cout << endl << "cout << a1 << a2 ";
 cout << a1 << a2;

 const Distance a7 (Distance::English, 1.0);
 Distance a8;

 cout << "cout << a7      " << a7;
 cout << "cout << 10 + a7 " << 10 + a7;
 cout << "cout << a7 + 10 " << a7 + 10;
 cout << "cout << a7 + a7 " << a7 + a7;

 a8 = a7 + 10;
 cout << "a8 = a7 + 10    " << a8;
 a8 = 10 + a7;
 cout << "a8 = 10 + a7    " << a8;
 a8 = a7 + a7;
 cout << "a8 = a7 + a7    " << a8;

 cout << "  if (a7 == a7)   ";
 if (a7 == a7) cout << "True";

 cout << "  if (a7 != a8)   ";
 if (a7 != a8) cout << "True";

 cout << "  if (a7 < a8)    ";
 if (a7 < a8) cout << "True\n";

 cout << "  if (a7 <= a8)   ";
 if (a7 <= a8) cout << "True";

 cout << "  if (a8 > a7)    ";
 if (a8 > a7) cout << "True";

 cout << "  if (a8 >= a7)   ";
 if (a8 >= a7) cout << "True\n";



 return 0;
}

