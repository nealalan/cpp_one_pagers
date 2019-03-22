//***************************************************************************************
// Neal A. Dreher         Oct 25, 2000
// CMPSC232               Wednesday 6:00
// Program 8              WinNT4, VC6
//
// 8.distance.cpp    a Distance Class II
//
//***************************************************************************************
//  NOTE: MtoE() returnes inches.. just so you know

#include "8.main.h"

//*********************
//   Constructors
//*********************

Distance::Distance():
	mmdistance(0) {	
}

// use if passed Distance a(long) for miles or mm (depends on unit)
Distance::Distance(Type standard, double mil) {
	if (standard == English) mmdistance = milestometers * 1000 * mil;
	else mmdistance = mil;
}

// use if passed Distance a(long, long, long);
Distance::Distance(Type standard, long meters, long centimeters, double millimeters):
	mmdistance((meters * 1000) + (centimeters * 100) + millimeters) {
}

// use if passed Distance a(int, double);
Distance::Distance(Type standard, long feet, double inches):
	mmdistance(EtoM((feet*12) + inches)) {
}


//*********************
//  Member Functions
//*********************

// returns what is stored base on the Type
//   English returns inches, Metric returns double millimeters
double Distance::GetDistance(const Type standard) const {
	
	if (standard == English) return (MtoE(mmdistance));
	else return mmdistance;
}

// use this to change the Distance in millimeters
void Distance::SetDistance(const Type standard, double measure) {

	if (standard == English) mmdistance = EtoM(measure);
	else mmdistance = measure;
	return;
}

// called from main() - output the desires unit of measurement 
// converted from other member functions or from stored class distance

void Distance::Paint(const ShowAs unit) const {

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);

	switch(unit) {
	case Mm : cout << "Distance is = " << setprecision(2) << mmdistance << " millimeters\n";
		break;
	case Feet : cout << "Distance is = " << MtoE(mmdistance) / 12<< " feet\n";
		break;
	case Meter : cout << "Distance is = " << MtoE(mmdistance) * meterstofeet << " meters\n";
		break;
	case Miles : cout << "Distance is = " << MtoE(mmdistance) * milestofeet << " miles\n";
		break;
	default : cout << "Error: Unit of measure invalid!\n";
		break;
	}
	return;
}
