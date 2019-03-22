//***************************************************************************************
// Neal A. Dreher         Dec 6, 2000
// CMPSC232               Wednesday 6:00
// Program 13             WinNT4, VC6
//
// 13.ruler.cpp    a Distance Class IIII
//
//***************************************************************************************

#include "13.main.h"


Ruler::Ruler(): standard(Metric) { 
	SetDistance(Metric, 1);
	
	}

Ruler::Ruler(Distance::Type s, double len) {
	standard = s;
	SetDistance(s, len);
}


istream& operator>>(istream& is, Ruler& r) {
	char x;
	double y;
	bool tinput = false, linput = false;

	do {
		cout << "Enter Ruler Type (E, M): ";
		is >> x; 

		switch (x) { 
		case 'M' : case 'm' : case 'E' : case 'e' :
			tinput = true;
		}
	} while (!tinput);

	do {
		cout << "Enter Ruler Length: ";
		is >> y;

		switch (x) {
		case 'M' : case 'm' :
			r.standard = Distance::Metric;
			r.SetDistance(Distance::Metric, y);
			linput = true;
			break;
		case 'E' : case 'e' :
			r.standard = Distance::English;
			r.SetDistance(Distance::English, y);
			linput = true;
			break;
		}
	} while (!linput);

	return is;
}

ostream& operator<<(ostream& os, const Ruler& r) {
	os.setf(ios::fixed, ios::floatfield);
	os.setf(ios::showpoint);

	return os << "The Ruler is " << setprecision(2) << setw(12) << r.GetDistance(r.standard) << " units long.\n";
}


void Ruler::Paint(const ShowAs unit) const {

	switch(unit) {
	case Mm : case Meter :
		cout << "The Ruler is " << setprecision(2) << mmdistance << " millimeters\n";
		break;
	case Feet : case Miles :
		cout << "The Ruler is " << MtoE(mmdistance) << " inches\n";
		break;
	}

	return;
}

