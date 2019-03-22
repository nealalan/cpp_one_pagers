//***************************************************************************************
// Neal A. Dreher         Nov 15, 2000
// CMPSC232               Wednesday 6:00
// Program 11              WinNT4, VC6
//
// 11.ruler.h      a Distance Class III
//
//***************************************************************************************

#include "11.main.h"


#ifndef RULERH
#define RULERH

class Ruler : public Distance {

protected:

	Distance::Type standard;

public:

	Ruler();
	Ruler(Distance::Type standard, double len);

	friend istream& operator>>(istream& is, Ruler r);
	friend ostream& operator<<(ostream& os, Ruler r);
};

#endif RULERH