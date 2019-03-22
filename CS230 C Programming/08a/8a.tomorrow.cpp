//***************************************************************
// Neal A. Dreher  
// 8a.*.cpp 8a.h
//
// This file contains the functions that determins tomorrow
//***************************************************************
#include "8a.h"

extern int tomMonth, tomDay, tomYear;

void tomorrow(int inMonth, int inDay, int inYear) {
	
	if (inDay == days_in_month(inMonth, inYear)) {	
		if (inMonth == 12) {
			tomMonth = 1;
			tomDay = 1;
			tomYear = inYear + 1;
		} else {
			tomMonth = inMonth + 1;
			tomDay = 1;
			tomYear = inYear;
		}
	} else {
		tomMonth = inMonth;
		tomDay = inDay + 1;
		tomYear = inYear;
	}
	return;
}
