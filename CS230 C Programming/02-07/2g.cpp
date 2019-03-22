//************************************************************
// Neal A. Dreher           Feb 01, 2000
// CMPSC230                 Tues. 6:00
// Page 2.22                Problen 2G
//
// Input the amount of money in pennies and output the equil
// in dollar bills, quarters, dimes, nickles, and pennies.
//************************************************************

#include <stdio.h>

int main() {

	int totpennies;   // the total amout of pennies the person has
	int dollar, quarter, dime, nickel, penny;
    int remainder;    // used to keep track of the 'rest' of the pennies

	printf("Enter amount of money expressed in pennies: ");
	scanf("%d", &totpennies);

	dollar = totpennies / 100;      // find the amount of dollars
	remainder = totpennies % 100;   // find the new total w/out dollars
	quarter = remainder / 25;       // find the amount of quarters
	remainder %= 25;                // find the new total w/out quarters
	dime = remainder / 10;          // find the amount of dimes
	remainder %= 10;                // find the new total w/out dimes
	nickel = remainder / 5;         // find the amount of nickels  
	remainder %= 5;                 // find the new total w/out nickels
	penny = remainder;              // make the amount of pennies

	printf("\n\n%2d dollars%(s%)", dollar);  
	printf("\n%2d quarter%(s%)", quarter);
	printf("\n%2d dime%(s%)", dime);
	printf("\n%2d nickel%(s%)", nickel);
	printf("\n%2d penny/pennies\n\n", penny);

	return 0;
}


/*
Enter amount of money expressed in pennies: 855


 8 dollars(s)
 2 quarter(s)
 0 dime(s)
 1 nickel(s)
 0 penny/pennies

Press any key to continue
*/