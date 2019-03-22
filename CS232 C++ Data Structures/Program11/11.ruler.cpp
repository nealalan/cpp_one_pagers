//***************************************************************************************
// Neal A. Dreher         Nov 15, 2000
// CMPSC232               Wednesday 6:00
// Program 11             WinNT4, VC6
//
// 11.ruler.cpp    a Distance Class II
//
//***************************************************************************************

#include "11.main.h"


Ruler::Ruler(): standard(Metric) { 
	SetDistance(Metric, 1);
	
	}

Ruler::Ruler(Distance::Type s, double len) {
	standard = s;
	SetDistance(s, len);
}


istream& operator>>(istream& is, Ruler r) {
	char x;
	double y;
	bool input = false;

	do {
		cout << "Enter Ruler Type (E, M): ";
		is >> x;
		cout << "\nEnter Ruler Length: ";
		is >> y;

		switch (x) {
		case 'M' : case 'm' :
			Distance(Distance::Type::Metric, y);
			input = true;
			break;
		case 'E' : case 'e' :
			Distance(Distance::Type::English, 0, y);
			input = true;
			break;
		}
	} while (!input);

	return is;
}

ostream& operator<<(ostream& os, Ruler r) {

	return os << "The Ruler is " << Ruler::GetDistance(Distance::Type::standard) << " units long.\n";
}