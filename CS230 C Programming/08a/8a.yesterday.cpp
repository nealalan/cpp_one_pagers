//***************************************************************
// Neal A. Dreher  
// 8a.*.cpp 8a.h
//
// This file contains the functions that determins what 
// yesterday's date was according to the inDate
// Calls days_in_month() to determine whether to change months
//***************************************************************
#include "8a.h"

extern int yesMonth, yesDay, yesYear;

void yesterday(int inMonth, int inDay, int inYear) {
	if (inDay == 1) {
		if (inMonth == 1) {
			yesMonth = 12;
			yesDay = 31;
			yesYear = inYear - 1;
		} else {
			yesMonth = inMonth - 1;
			yesDay = days_in_month(inMonth - 1, inYear);
			yesYear = inYear;
		}
	} else {
		yesMonth = inMonth;
		yesDay = inDay - 1;
		yesYear = inYear;
	}
	return;
}
