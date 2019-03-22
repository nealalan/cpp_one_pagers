//***************************************************************************************
// Neal A. Dreher         Oct 4, 2000
// CMPSC232               Wednesday 6:00
// Program 5              WinNT4, VC6
//
// 5.distance.h    a Distance Class
//
//***************************************************************************************

#ifndef DISTANCEH
#define DISTANCEH

#include "5.main.h"

const double meterstofeet(3.280833);
const int milestofeet(5208);

class Distance {

protected:

	long mmdistance;

public:

	Distance();
	Distance(long millimeters);
	Distance(long meters, long centimeters, long millimeters);
	Distance(int feet, int inches);
	Distance(double miles);

	double GetDistance();
	void SetDistance(double millimeters);
	double MtoE() const;
	double EtoM(int feet, int inches) const;
	double EtoM(double miles) const;
	void Paint(char unit) const;

};

#endif DISTANCEH