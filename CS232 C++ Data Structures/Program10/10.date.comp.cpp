//***************************************************************************************
// Neal A. Dreher         Nov 8, 2000
// CMPSC232               Wednesday 6:00
// Program 10             WinME, WinNT4, VC6
//
// 10.date.comp.cpp
//
// this file is for comparison of dates with operator overloading 
//***************************************************************************************

#include "10.main.h"


// allow for (date == d) 
bool Date::operator==(const Date& d) const {

	if(d.serialdate == serialdate) return true;
	else return false;
}

// allow for (date != d)
bool Date::operator!=(const Date& d) const {

	if(d.serialdate != serialdate) return true;
	else return false;
}

// allow for (date > d)
bool Date::operator>(const Date& d) const {

	if(serialdate > d.serialdate) return true;
	else return false;
}

// allow for (date >= d)
bool Date::operator>=(const Date& d) const {

	if(serialdate >= d.serialdate) return true;
	else return false;
}

// allow for (date < d)
bool Date::operator<(const Date& d) const {

	if(serialdate < d.serialdate) return true;
	else return false;
}

// allow for (date <= d)
bool Date::operator<=(const Date& d) const {

	if (serialdate < d.serialdate) return true;
	else return false;
}


