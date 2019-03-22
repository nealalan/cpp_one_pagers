//***************************************************************************************
// Neal A. Dreher         Sept 27, 2000
// CMPSC232               Wednesday 6:00
// Program 4              WinME, WinNT4, VC6
//
// 4.date.h
//
//***************************************************************************************

#ifndef DATEH 
#define DATEH

class Date {

protected:

long serialdate;

public:
 
Date();
void SetDate(int month, int day, int year);
void GetDate(int& month, int& day, int& year);
void FormatDate(char* string, unsigned int max_string_len);
long DateToSerial(const int month, const int day, const int year);
void SerialToDate(int& month, int& day, int& year);
};

#endif DATEH