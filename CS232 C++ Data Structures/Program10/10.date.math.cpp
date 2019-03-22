//***************************************************************************************
// Neal A. Dreher         Nov 8, 2000
// CMPSC232               Wednesday 6:00
// Program 10             WinME, WinNT4, VC6
//
// 10.date.io.cpp
//
// this file is for basic math operation +/-/++/--
//***************************************************************************************

#include "10.main.h"

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

