///************************************************************************************************
// Neal A. Dreher         Feb. 01, 2000
// CMPSC230               Tues. 6:00
// Page 3.13              Problem 3H
//                                         -n
//  Use the formula P = Ar / 1 - [( 1 + r )   ] to find monthly payments where P = monthly payment,
//  A = loan amount, n = is the number of monthly payment and r = monthly interest rate.
//*************************************************************************************************

#include <stdio.h>
#include <math.h>

int main() {

	long loanamount;
	int loanyears;
	float interestrate, monthlypayment;

	// input the variables

	printf("\nEnter loan amount: ");
	scanf("%ld", &loanamount);
	printf("Enter annual interest rate (in decimal form): ");
	scanf("%f", &interestrate);
	printf("Enter length of loan in years: ");
	scanf("%d", &loanyears);

	// do the math to figure out the monthlypayment
	// interestrate / 12 to make it monthly instead of yearly; loanyears * 12 to make it into the loan months

	monthlypayment = (loanamount * (interestrate /12)) / (1 - pow((1 + (interestrate / 12)), -(loanyears * 12)));
	printf("\nMonthly payment is $%.2f\n\n", monthlypayment);

	return 0;
}

/*
Enter loan amount: 1000000
Enter annual interest rate (in decimal form): .05
Enter length of loan in years: 30

Monthly payment is $5368.22

Press any key to continue
*/
