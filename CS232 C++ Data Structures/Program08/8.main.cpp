//***************************************************************************************
// Neal A. Dreher         Oct 25, 2000
// CMPSC232               Wednesday 6:00
// Program 8              WinNT4, VC6
//
// 8.main.cpp    a Distance Class II
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

#include "8.main.h"

// these are just teacher derived test functions making sure that Distance and Path work
int main () {

 const Distance a1 (Distance::Metric, 1000.5);        // 1000.5 mm
 const Distance a2 (Distance::English, 1000.5);       // 1000.5 miles
 const Distance a3 (Distance::Metric, 100L, 8L, 6.3); // 100 m, 8 cm 6.3 mm
 const Distance a4 (Distance::English, 3L, 10.5);     // 3 ft, 10.5 in
 const Distance a5 (Distance::Metric, 10L, 1L);       // 10 m, 1 cm, 0 mm
 const Distance a6 (Distance::English, 5L);           // 5 ft, 0 inches
 Path  path1;
 path1.AddPath (a1);
 path1.AddPath (a2);
 path1.AddPath (a3);
 path1.AddPath (a4);
 path1.AddPath (a5);
 path1.AddPath (a6);
 cout << "Displaying Path1 Results:\n";
 path1.ShowPath ();

 careful (a1);

 return 0;
}

void careful (const Distance &d) {

 Distance b1, b2, b3, b4;
 b1.SetDistance (Distance::Metric, 1000.0);
 b2.SetDistance (Distance::Metric, b1.GetDistance (Distance::Metric));
 b3.SetDistance (Distance::English, b1.GetDistance (Distance::English));
 b4.SetDistance (Distance::Metric, 42.0);
 Path p;
 p.AddPath (d);
 p.AddPath (b1);
 p.AddPath (b2);
 p.AddPath (b3);
 p.AddPath (b4);
 cout << "\n\nDisplaying Path2 Results:\n";
 p.ShowPath ();

 return;
}