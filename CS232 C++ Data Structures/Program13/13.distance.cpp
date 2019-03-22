//***************************************************************************************
// Neal A. Dreher         Dec 6, 2000
// CMPSC232               Wednesday 6:00
// Program 13             WinNT4, VC6
//
// 13.distance.cpp    a Distance Class IIII
//
//***************************************************************************************
//  NOTE: MtoE() returnes inches.. just so you know

#include "13.main.h"

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

// use this to change the Distance in millimeters, inches
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

//*********************
//  Friend M-E Functions
//*********************
// this takes a double millimeterdistance and returns the amount of inches 
double MtoE(const double mmd) { return ((mmd / 1000) * meterstofeet * 12); }

// this takes a reference to a Distance object and returns double inches
double MtoE(const Distance& d) { return ((d.mmdistance / 1000) * meterstofeet * 12); }

// this takes double inches and returns double millimeters
double EtoM(const double inches) { return ((inches / 12) / meterstofeet) * 1000; }

// this is passed a reference to a Distance object and double inches
// it returns double millimeters and sets the d.mmdistance to the same double mm
double EtoM(Distance& d, const double inches) { return d.mmdistance = EtoM(inches); }


//*********************
// Oper Overloads
//*********************


istream& operator>>(istream& is, Distance& d) {
	double dist;

	cout << "Enter a distance in millimeters: ";

	is >> dist;
	d.SetDistance(Distance::Metric, dist);
	return is;
}

ostream& operator<<(ostream& os, const Distance &d) {

	os.setf(ios::fixed, ios::floatfield);
	os.setf(ios::showpoint);

	os << "Distance is " << setprecision(2) << setw(9) << d.GetDistance(Distance::Metric) << " millimeters\n";

	return os;
}

Distance Distance::operator+(const Distance &d) const {
	Distance temp;

	temp.mmdistance = mmdistance + d.mmdistance;

	return temp;
}

Distance Distance::operator+(const double add) const {
	Distance temp;

	temp.mmdistance = mmdistance + add;

	return temp;
}

Distance operator+(const double add, const Distance &d) {
	Distance temp;
	temp.mmdistance = d.mmdistance + add;

	return temp;
}

Distance& Distance::operator=(const Distance &d) {
	if (*this == d) return *this;
	mmdistance = d.mmdistance;

	return *this;
}

bool Distance::operator==(const Distance& d) const {
	if(d.mmdistance == mmdistance) return true;
	else return false;
}

bool Distance::operator!=(const Distance& d) const {
	if(d.mmdistance != mmdistance) return true;
	else return false;
}

bool Distance::operator<(const Distance& d) const {
	if(mmdistance < d.mmdistance) return true;
	else return false;
}

bool Distance::operator<=(const Distance& d) const {
	if(mmdistance <= d.mmdistance) return true;
	else return false;
}

bool Distance::operator>(const Distance& d) const {
	if(mmdistance > d.mmdistance) return true;
	else return false;
}

bool Distance::operator>=(const Distance& d) const {
	if(mmdistance >= d.mmdistance) return true;
	else return false;
}

Distance& Distance::operator++() {
	mmdistance++;

	return *this;
}

Distance Distance::operator++(int) {
	Distance d = *this;

	mmdistance++;
	return d;
}

Distance& Distance::operator--() {

	mmdistance--;
	return *this;
}

Distance Distance::operator--(int) {
	Distance d = *this;

	mmdistance--;
	return d;
}


