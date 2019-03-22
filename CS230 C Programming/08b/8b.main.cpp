///**************************************************************
// Neal A. Dreher         Feb. 22, 2000
// CMPSC230               Tues. 6:00
// Page 8.22              Problem 8B
//
// 8b.*.cpp 8b.h
// This program inputs a file of dates and gives the next and 
// previous date * ASSUMES ALL INPUT DATES ARE VALID *
//***************************************************************
#include "8b.h"

int main() {

	int inMonth = 0, inDay = 0, inYear = 0,
		yesMonth = 0, yesDay = 0, yesYear = 0,
		tomMonth = 0, tomDay = 0, tomYear = 0;
	printf("YESTERDAY       TODAY           TOMORROW\n\n");

	// are 3 pieces of data are being inputed?
	while(scanf("%d/%d/%d", &inMonth, &inDay, &inYear) == 3) {
		// calculate yesterday
		yesterday(inMonth, inDay, inYear, &yesMonth, &yesDay, &yesYear);
		// calculate tomorrow
		tomorrow(inMonth, inDay, inYear, &tomMonth, &tomDay, &tomYear);
		// print outputs
		printf("%02d/%02d/%4d      ", yesMonth, yesDay, yesYear);
		printf("%02d/%02d/%4d      ", inMonth, inDay, inYear);
		printf("%02d/%02d/%4d\n", tomMonth, tomDay, tomYear);
	}
	return 0;
}