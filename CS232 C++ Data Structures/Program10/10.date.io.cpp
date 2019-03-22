//***************************************************************************************
// Neal A. Dreher         Nov 8, 2000
// CMPSC232               Wednesday 6:00
// Program 10             WinME, WinNT4, VC6
//
// 10.date.io.cpp
//
// this file is for the I/O side of the class 
//***************************************************************************************

#include "10.main.h"

// this function takes a reference to an istream and inputs a date of the 
// form mm/dd/yy of mm/dd/yyyy.  It should ret a reference to a passed istream

istream& operator>>(istream& is, Date& d) {

	char c;
	int mo, da, yr;

	is >> mo >> c >> da >> c >> yr;
	d.SetDate(mo, da, yr);

	return is;
}


// this function takes a reference to an ostream and outputs the formatted
// date: 01/01/1997 for example.  It should ret a ref to the passed ostream
// always print 2 digits for the month and day
ostream& operator<<(ostream& os, const Date& d) {

	char datestring[DATE_STR_LEN];

	d.FormatDate(datestring, DATE_STR_LEN);
	
	return os << datestring;
}

