//***************************************************************
// Neal A. Dreher  
// 8b.*.cpp 8b.h
//
// This file contains the functions that determins tomorrow
//***************************************************************
#include "8b.h"

void tomorrow(int inMonth, int inDay, int inYear,
			  int *ptrtomMonth, int *ptrtomDay, int *ptrtomYear) {
	
	if (inDay == days_in_month(inMonth, inYear)) { // is last day of month
		if (inMonth == 12) {             // if 12/31/#### make 01/01/####
			*ptrtomMonth = 1;
			*ptrtomDay = 1;
			*ptrtomYear = inYear + 1;
		} else {                         // other month than 12
			*ptrtomMonth = inMonth + 1;
			*ptrtomDay = 1;
			*ptrtomYear = inYear;
		}
	} else {                             // month and year same find tom  
		*ptrtomMonth = inMonth;
		*ptrtomDay = inDay + 1;
		*ptrtomYear = inYear;
	}
	return;
}
