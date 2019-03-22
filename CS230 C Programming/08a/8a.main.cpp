///**************************************************************
// Neal A. Dreher         Feb. 22, 2000
// CMPSC230               Tues. 6:00
// Page 8.9               Problem 8A
//
// Using global vars, show the prevous and next day of days 
// inputed from a test file.
//***************************************************************
#include "8a.h"

int yesMonth, yesDay, yesYear, tomMonth, tomDay, tomYear;      // declare for extern use

int main() {

	int inMonth = 0, inDay = 0, inYear = 0;
    // print the col headers
	printf("YESTERDAY       TODAY           TOMORROW\n\n");

	while(scanf("%d/%d/%d", &inMonth, &inDay, &inYear) == 3) {  // check for 3 int inputs 
		yesterday(inMonth, inDay, inYear);                      // determine yesterdays date
		tomorrow(inMonth, inDay, inYear);					    // determine tomorrows date
		printf("%02d/%02d/%4d      ", yesMonth, yesDay, yesYear);
		printf("%02d/%02d/%4d      ", inMonth, inDay, inYear);
		printf("%02d/%02d/%4d\n", tomMonth, tomDay, tomYear);
	}
	return 0;
}