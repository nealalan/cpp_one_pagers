//***************************************************************************************
// Neal A. Dreher         Oct 18, 2000
// CMPSC232               Wednesday 6:00
// Program 7              WinME, WinNT4, VC6
//
// 7.date.h
//
//***************************************************************************************

#ifndef DATEH 
#define DATEH

#define DATE_STR_LEN 11

class Date {

protected:

long serialdate;

public:
 
Date();
Date(int month, int day, int year);
Date(const char* string);

int Compare(const Date& in) const;
long Difference(const Date& in) const;
Date Add(long add) const;
Date Subtract(long minus) const;

istream& Input(istream& is);
ostream& Output(ostream& os) const;

void SetDate(int month, int day, int year);
void GetDate(int& month, int& day, int& year) const;
void FormatDate(char* string, unsigned int max_string_len) const;
long DateToSerial(const int month, const int day, const int year);
void SerialToDate(int& month, int& day, int& year) const;
};

#endif DATEH