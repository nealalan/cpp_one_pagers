//***************************************************************************************
// Neal A. Dreher         Oct 4, 2000
// CMPSC232               Wednesday 6:00
// Program 5              WinNT4, VC6
//
// 5.distance.cpp    a Distance Class
//
//***************************************************************************************

#include "5.main.h"


Distance::Distance():
	mmdistance(0) {	
}

// use if passed Distance a(long);
Distance::Distance(long millimeters):
	mmdistance(millimeters) {
}

// use if passed Distance a(long, long, long);
Distance::Distance(long meters, long centimeters, long millimeters):
	mmdistance((meters * 1000) + (centimeters * 100) + millimeters) {
}

// use if passed Distance a(int, int);
Distance::Distance(int feet, int inches):
	mmdistance((long)EtoM(feet, inches)) {
}

// use if passed Distance a(double);
Distance::Distance(double miles): 
	mmdistance((long)EtoM(miles)) {
}

// returns what is stored in the class for the distance
double Distance::GetDistance() {
	
	return mmdistance;
}

// use this to change the Distance in mm's
void Distance::SetDistance(double millimeters) {

	mmdistance = (long)millimeters;
	return;
}

// get the class's stored distance, return feet
double Distance::MtoE() const {

	return (mmdistance * 1000) / meterstofeet;
}

// when given feet and inches, return millimeters
double Distance::EtoM(int feet, int inches) const {

	return (((feet * 12) + inches / 12) / meterstofeet) * 1000;
}

// when give miles, return millimeters
double Distance::EtoM(double miles) const {

	return EtoM(int(miles * milestofeet), 0);
}

// called from main() - output the desires unit of measurement 
// converted from other member functions or from stored class distance
void Distance::Paint(char unit) const {

	switch(unit) {
	case 'M': case 'm':
		cout << "Distance is = " << mmdistance << " millimeters\n";
		break;
	case 'F': case 'f':
		cout << "Distance is = " << MtoE() << " feet\n";
		break;
	case 'I': case 'i':
		cout << "Distance is = " << int(mmdistance / 1000) << " meters and " 
			<< int(mmdistance % 1000) << " millimeters\n";
		break;
	case 'L': case 'l':
		cout << "Distance is = " << (MtoE() * milestofeet) << " miles\n";
		break;
	default:
		cout << "Error: Unit of measure invalid!\n";
		break;
	}

	return;
}
