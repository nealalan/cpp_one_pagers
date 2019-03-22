//***************************************************************************************
// Neal A. Dreher         Sept 27, 2000
// CMPSC232               Wednesday 6:00
// Program 4              WinME, WinNT4, VC6
//
// 4.date.cpp
//
//***************************************************************************************

#include "4.main.h"

Date::Date() {
	serialdate = 0;
}

void Date::SetDate(int month, int day, int year) {

	if (year < 100) year+= 1900;
	serialdate = DateToSerial(month, day, year);

	return;
}

void Date::GetDate(int& month, int& day, int& year) {

	SerialToDate(month, day, year);

	return;
}

void Date::FormatDate(char* string, unsigned int max_string_len) {

// no need to check max_string_len because whatever number is passed to
// max_str* is where the null term is put per the syntax of ostrstream

	int month, day, year;

	GetDate(month, day, year);
	ostrstream ou(string, max_string_len);
	ou << " " << setfill('0') << setw(2) << month << '/' << setw(2) 
		<< day   << '/' << setw(4) << year << ends;
}

long Date::DateToSerial(const int month, const int day, const int year) {
	
	return day - 32075L + 1461L * (year + 4800 + (month - 14L) / 12L) / 4L
		+ 367L * (month - 2L - (month - 14L) / 12L * 12L) / 12L
        - 3L * ((year + 4900L + (month - 14L) / 12L) / 100L) / 4L;
}

void Date::SerialToDate(int& month, int& day, int& year) {

	long t1, t2, m, y;

	t1 = serialdate + 68569L;
	t2 = 4L * t1 / 146097L;
	t1 = t1 - (146097L * t2 + 3L) / 4L;
	y  = 4000L * (t1 + 1) / 1461001L;
	t1 = t1 - 1461L * y / 4L + 31;
	m  = 80L * t1 / 2447L;
	day = (int)(t1 - 2447L * m / 80L);
	t1 = m / 11L;
	month = (int)(m + 2L - 12L * t1);
	year = (int)(100L * (t2 - 49L) + y + t1);
}
