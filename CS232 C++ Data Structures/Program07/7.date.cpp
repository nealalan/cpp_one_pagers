//***************************************************************************************
// Neal A. Dreher         Oct 18, 2000
// CMPSC232               Wednesday 6:00
// Program 7              WinME, WinNT4, VC6
//
// 7.date.cpp
//
//***************************************************************************************

#include "7.main.h"

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

// this function takes another Date object and compared it to this date.
// It returns a pos int when your date is greater than the passed date, 0 if
// the same and a neg int if less.  Neither date is altered
int Date::Compare(const Date& in) const {


	if(in.serialdate == serialdate) return 0;
	if(in.serialdate < serialdate) return 1;
	if(in.serialdate > serialdate) return -1;
	// would never do this but gets rid of compile warning
	return 0;
}

// this function returns the long number of days from this date to the 
// passed date.  It is neg when this date is before the passed date.  Neither
// this date not the passed date are altered
long Date::Difference (const Date& in) const {

	return serialdate - in.serialdate;
}

// this function allows one to add a long number of days onto this date,
// returning the new date.  It does not alter the date object itself
Date Date::Add(long add) const {

	Date x;
	x.serialdate = serialdate + add;
	
	return x;
}

// this funtion allows one to subtract a long number of days from this
// date, returning the new date.  It does not alter the date object itself
Date Date::Subtract(long minus) const {

	Date x;
	x.serialdate = serialdate - minus;

	return x;
}

// this function takes a reference to an istream and inputs a date of the 
// form mm/dd/yy of mm/dd/yyyy.  It should ret a reference to a passed istream
istream& Date::Input(istream& is) {

	char c;
	int mo, da, yr;

	is >> mo >> c >> da >> c >> yr;

	SetDate(mo, da, yr);

	return is;
}

// this function takes a reference to an ostream and outputs the formatted
// date: 01/01/1997 for example.  It should ret a ref to the passed ostream
// always print 2 digits for the month and day
ostream& Date::Output(ostream& os) const {

	char datestring[DATE_STR_LEN];

	FormatDate(datestring, DATE_STR_LEN);
	
	return os << datestring;
}

// this and only this sets the internal serialdate
// *WHENEVER YOU INPUT A DATE YOU MUST SET IT HERE*

void Date::SetDate(int month, int day, int year) {

	if (year < 100) year+= 1900;
	serialdate = DateToSerial(month, day, year);

	return;
}

// this gets the internal serial date and changes it to 3 ints
// *WHENEVER YOU WANT TO GET (int,int,int) FROM SERIALDATE USE THIS
void Date::GetDate(int& month, int& day, int& year) const {

	SerialToDate(month, day, year);

	return;
}

// this puts the date into the memory address of a char string that is 
// referenced to
// *this function likes strings of 11
void Date::FormatDate(char* string, unsigned int max_string_len) const {

	// no need to check max_string_len because whatever number is passed to
	// max_str* is where the null term is put per the syntax of ostrstream

	int month, day, year;

	GetDate(month, day, year);
	ostrstream ou(string, max_string_len);
	ou << setfill('0') << setw(2) << month << '/' << setw(2) 
		<< day   << '/' << setw(4) << year << ends;
}

// this converts a 3 int's date to a long 
long Date::DateToSerial(const int month, const int day, const int year) {
	
	return day - 32075L + 1461L * (year + 4800 + (month - 14L) / 12L) / 4L
		+ 367L * (month - 2L - (month - 14L) / 12L * 12L) / 12L
        - 3L * ((year + 4900L + (month - 14L) / 12L) / 100L) / 4L;
}

// this converts a long date to 3 int's
void Date::SerialToDate(int& month, int& day, int& year) const {

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
