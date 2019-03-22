//***************************************************************************************
// Neal A. Dreher         Nov 8, 2000
// CMPSC232               Wednesday 6:00
// Program 10             WinME, WinNT4, VC6
//
// 10.date.const.cpp
//
// this cpp file is for the Date class constructors
//***************************************************************************************

#include "10.main.h"

// set the date to the current date
Date::Date() {

	time_t now;
	tm *ptrtime;
	now = time(NULL);
	ptrtime = localtime(&now);
	int month = ptrtime->tm_mon + 1;
	int day = ptrtime->tm_mday;
	int year = ptrtime->tm_year + 1900;
	SetDate(month, day, year); 
}

// set the date to the passed month day and year
Date::Date(int month, int day, int year) {

	SetDate(month, day, year);
}

// read in a string and put it in the date
Date::Date(const char* string) {

	int month, day, year;
	char c;
	istrstream is((char*) string);

	is >> month >> c >> day >> c >> year;
	SetDate(month, day, year);
}


