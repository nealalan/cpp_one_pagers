///**************************************************************
// Neal A. Dreher         Feb. 15, 2000
// CMPSC230               Tues. 6:00
// Page 7.17              Problem 7E
//
// a program that checks to see if the date input is valid by 
// leap year and month length between 1600 and 2400AD
//***************************************************************

#include <stdio.h>

bool isleap(int inYear); // leap year or not if inMonth==2
int days_in_month(int inMonth, int inYear); // valid month length?
bool isdate(int inMonth, int inDay, int inYear);  // date valid?

int main() {
	int inMonth=0, inYear=0, inDay=0; // the data to input

	// are 3 pieces of data are being inputed?
	while(scanf("%d %d %d", &inMonth, &inDay, &inYear) == 3) {

		// put dates in 00-00-0000 form
		printf("%02d-%02d-%4d", inMonth, inDay, inYear);

		// is date T or F
		if (isdate(inMonth, inDay, inYear)) printf("\n");
		else printf(" INVALID DATE\n");

	}
	return 0;
}

//***************************************************************
//  check to see if this is a leap year to know exactly the days
//  in feb according to the year
bool isleap(int inYear) {

	if (((0 == inYear % 4) && (0 != inYear % 400)) || 
		(0 == inYear % 400)) return true;
	else return false;
}

//***************************************************************
// tells isdat() if the day is valid according to the month it is
int days_in_month(int inMonth, int inYear) {

	int days;

	switch(inMonth) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		days=31;
		break;
	case 4: case 6: case 9: case 11:
		days=30;
		break;
	case 2:
		if (isleap(inYear)) days=29;
		else days=28;
		break;
	}
	return days;
	
}

//***************************************************************
// checks to see if the date if valid or not
bool isdate(int inMonth, int inDay, int inYear) {

	if ((inYear >= 1600 && inYear <= 2400) &&
		(inDay <= (days_in_month(inMonth, inYear)) && (inDay >= 1)) &&
		(inMonth <= 12) && (inMonth >= 1 )) return true; 
	else return false;
}

