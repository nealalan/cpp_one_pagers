//***************************************************************************************
// Neal A. Dreher         Nov 8, 2000
// CMPSC232               Wednesday 6:00
// Program 10             WinME, WinNT4, VC6
//
// 10.date.h
//
//***************************************************************************************

#include "9.main.h"

#ifndef DATEH 
#define DATEH

#define DATE_STR_LEN 11

class Date {

protected:

long serialdate;

public:

// constructors/destructors
Date();
Date(int month, int day, int year);
Date(const char* string);
~Date() {}

void SetDate(int month, int day, int year);
void GetDate(int& month, int& day, int& year) const;
void FormatDate(char* string, unsigned int max_string_len) const;
long DateToSerial(const int month, const int day, const int year);
void SerialToDate(int& month, int& day, int& year) const;
int GetMonth();
int GetDay();
int GetYear();

// i/o operators overload
friend istream& operator>>(istream& is, Date& d);        // istream >> date
friend ostream& operator<<(ostream& os, const Date& d);  // ostream << date

// math operators overload
Date operator+(const long add) const;                    // date1 = date - long
friend Date operator+(const long toadd, const Date &d);  // date1 = long - date
Date operator-(const long minus) const;                  // date1 = date - long
long operator-(const Date& d) const;                     // long = date - date1
Date& operator++();         // date++
Date operator++(int);      // ++date
Date& operator--();         // date--
Date operator--(int);      // --date
Date& operator+=(const int plus);   // date1 += 42
Date& operator-=(const int minus);  // date1 -= 42


// compart operators overload
bool operator==(const Date& d) const;     // (date == d) ?
bool operator!=(const Date& d) const;     // (date != d) ?
bool operator>(const Date& d) const;      // (date > d) ?
bool operator>=(const Date& d) const;     // (date >= d) ?
bool operator<(const Date& d) const;      // (date < d) ?
bool operator<=(const Date& d) const;     // (date <= d) ?



};

#endif DATEH