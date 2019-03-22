//***************************************************************************************
// Neal A. Dreher         Dec 6, 2000
// CMPSC232               Wednesday 6:00
// Program 13             WinNT4, VC6
//
// 13.ruler.h      a Distance Class IIII
//
//***************************************************************************************

#include "13.main.h"


#ifndef RULERH
#define RULERH

class Ruler : public Distance {

protected:

	Distance::Type standard;

public:

	Ruler();
	Ruler(Distance::Type standard, double len);

	friend istream& operator>>(istream& is, Ruler& r);
	friend ostream& operator<<(ostream& os, const Ruler& r);

	void Paint(const ShowAs unit) const;

};

#endif RULERH