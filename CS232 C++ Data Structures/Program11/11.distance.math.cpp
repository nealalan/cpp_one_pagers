//***************************************************************************************
// Neal A. Dreher         Nov 15, 2000
// CMPSC232               Wednesday 6:00
// Program 11             WinNT4, VC6
//
// 11.distance.math.cpp   a Distance Class III
//
//***************************************************************************************

#include "11.main.h"


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

