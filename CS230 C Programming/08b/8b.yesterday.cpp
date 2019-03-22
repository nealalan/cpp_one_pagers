//***************************************************************
// Neal A. Dreher  
// 8b.*.cpp 8b.h
//
// This file contains the functions that determins what 
// yesterday's date was according to the inDate
// Calls days_in_month() to determine whether to change months
//***************************************************************
#include "8b.h"

void yesterday(int inMonth, int inDay, int inYear,
			   int *ptryesMonth, int *ptryesDay, int *ptryesYear) {

	if (inDay == 1) {           // is first of month need to change months
		if (inMonth == 1) {     // is 01/01/#### and needs to change year
			*ptryesMonth = 12;
			*ptryesDay = 31;
			*ptryesYear = inYear - 1;
		} else {                // year stays the same, month change
			*ptryesMonth = inMonth - 1;
			*ptryesDay = days_in_month(inMonth - 1, inYear);
			*ptryesYear = inYear;
		}
	} else {                    // month, year same, get yesterday
		*ptryesMonth = inMonth;
		*ptryesDay = inDay - 1;
		*ptryesYear = inYear;
	}
	return;
}
