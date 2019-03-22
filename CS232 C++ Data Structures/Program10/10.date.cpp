//***************************************************************************************
// Neal A. Dreher         Nov 8, 2000
// CMPSC232               Wednesday 6:00
// Program 10             WinME, WinNT4, VC6
//
// 10.date.cpp
//
// these are the member functions that access and change the Date internally
//***************************************************************************************

#include "10.main.h"

//***********************************************************
// These are the CONSTRUCTOR AND DESTRUCTOR FUNCTIONS
//***********************************************************

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

//***********************************************************
// this and only this sets the internal serialdate
//***********************************************************
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
}

// gets the month for the user
int Date::GetMonth() {
	int mo, da ,yr;

	GetDate(mo,da,yr);
	return mo;
}

// gets the day for the user
int Date::GetDay() {
	int mo, da ,yr;

	GetDate(mo,da,yr);
	return da;
}

// gets the year for the user
int Date::GetYear() {
	int mo, da ,yr;

	GetDate(mo,da,yr);
	return yr;

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


//***********************************************************
// I/O OVERLOADED FUNCTION
// These functions take a reference to an istream and inputs 
// a date of the form mm/dd/yy of mm/dd/yyyy.  It should ret 
// a reference to a passed istream
//***********************************************************

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


//***********************************************************
// COMPARE FUNCTIONS
// These functions compare dates with operator overloading 
//***********************************************************

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
	if (serialdate <= d.serialdate) return true;
	else return false;
}


//***********************************************************
// MATH OVERLOADED FUNCTIONS
//***********************************************************

// this function allows for Date = Date + long
// but dosen't allow the change of Date_2
Date Date::operator+(const long add) const {
	Date temp;
	temp.serialdate = serialdate + add;
	
	return temp;
}

// this function allows for Date = long + Date2
// but dosen't allow the change of Date2
// had to make a friend - there is no long class to add a Date to
Date operator+(const long toadd, const Date &d) {
	Date temp;
	temp.serialdate = d.serialdate + toadd;

	return temp;
}

// this function allows for Date = Date2 - long
// but dosen't allow the change of Date2
Date Date::operator-(const long minus) const {
	Date temp;
	temp.serialdate = serialdate - minus;

	return temp;
}

// this function allows long = date - date2 in order
// to find the difference between days
// it does not allow date or date2 to be altered
long Date::operator-(const Date& d) const { 
	return serialdate - d.serialdate; 
}

// this function allows for date++ to go to the next day
Date& Date::operator++() {
	serialdate++;

	return *this;
}

// this function allows for ++date to return the current day
// but after it's returned it's inc'd
Date Date::operator++(int) {
	Date d = *this;

	serialdate++;
	return d;
}

// this function allows for date-- to go to the prev day
Date& Date::operator--() {

	serialdate--;
	return *this;
}

// this function allows for --date to return the current day
// but after it's returned it's dec'd
Date Date::operator--(int) {
	Date d = *this;

	serialdate--;
	return d;
}

// this function allows for date1 += 42
Date& Date::operator+=(const int plus) {
	serialdate += plus;
	return *this;
}

Date& Date::operator-=(const int minus) {
	serialdate -= minus;
	return *this;
}