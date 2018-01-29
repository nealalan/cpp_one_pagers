//***************************************************************************************
// Neal A. Dreher         Dec 6, 2000
// CMPSC232               Wednesday 6:00
// Program 13             WinNT4, VC6
//
// 13.main.cpp    a Distance Class IIII
//
// REVISION 1:  Make the Distance class work, see REV 2
// REVISION 2:	This is a very weak and limited Distance class that inputs
//		A: Distance(Eng/Met, miles/mm);
//		B: Distance(Met, meters, cm, mm = 0);
//		C: Distance(Eng, feet, inches = 0);
//	It is also capable of storing array's of Distance objects called Path's and output 
//	these Path's in millimeter lengths
// REVISION 3:  Finish and Clean up the Distance class to be derived from
//		A: Add operator overloading for = + == != <= >= < > ++ --
//		B: Create a derived Ruler class adding a data member for Distance::Type 
//			and add support for os << is >>
//
// REVISION 4:	Using Virtual Functions
//		A: Revise the Distance class to make the Paint function virtual
//		B: Add Ruler::Paint(Distance::ShowAs) to output in only mm and inches
//		C: Do all the testing crap in main
//
//***************************************************************************************

#include "13.main.h"

// these are just teacher derived test functions making sure that Distance and Path work
int main () {

 Distance a1 (Distance::Metric, 1000.5);        // 1000.5 mm
 const Distance a2 (Distance::English, 1000.5);       // 1000.5 miles
 const Distance a3 (Distance::Metric, 100L, 8L, 6.3); // 100 m, 8 cm 6.3 mm
 const Distance a4 (Distance::English, 3L, 10.5);     // 3 ft, 10.5 in
 const Distance a5 (Distance::Metric, 10L, 1L);       // 10 m, 1 cm, 0 mm
 const Distance a6 (Distance::English, 5L);           // 5 ft, 0 inches
 const Distance a7 (Distance::English, 1.0);
 Distance a8;

 Ruler r1(Distance::Metric, 1000);
 Ruler r2(Distance::English, 1000);
 Ruler r3(Distance::English, 36.1);
 Ruler r4(Distance::Metric, 100.1);

 Distance *ptrbase;

 ptrbase = &a1;
 ptrbase->Paint(Distance::Mm);

 ptrbase = &r1;
 ptrbase->Paint(Distance::Miles);

 

 return 0;
}

