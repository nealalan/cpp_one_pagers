/*	Neal A. Dreher
	25 Feb 1999
	P385 N4
*/

#include <iostream.h>
#include <iomanip.h>

void Check ();
void Deposit ();
void AccountBalance ();
void Warn50 ();
void Space (int);
void Check500();
void EndProgram();
void ServiceChg(float);

float totBalance;
float serviceChg;
bool fiveFine = true;


main () {

	cout.setf(ios::fixed, ios::floatfield);	//float point
	cout.setf(ios::showpoint);

	Space (1);
	cout << "Please enter the begining balance: ";
	cin >> totBalance;

	bool go = true;  // cont program loop
	char transType;

	while (go) {
		Space(1);
		Warn50();
		Check500();

		cout << "Transaction type (A,C,D,E): ";
		cin >> transType;
		switch (transType) {
			case 'A': AccountBalance (); break;
			case 'a': AccountBalance (); break;
			case 'C': Check (); break;
			case 'c': Check (); break;
			case 'D': Deposit (); break;
			case 'd': Deposit (); break;
			case 'E': go = false; EndProgram(); break;
			case 'e': go = false; EndProgram(); break;
		}

	}

	return 0;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void Check () {
	float checkAmount;

	cout << "Please enter amount of check: ";
	cin >> checkAmount;

	totBalance = totBalance - checkAmount;
	if (totBalance < 0) {
		cout << "WARNING: YOU ARE IN THE RED" << endl;
		ServiceChg(10);
	}
	ServiceChg(0.15);
	AccountBalance();
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void Deposit () {
	float depositAmount;

	cout << "Please enter amount of Deposit: ";
	cin >> depositAmount;

	totBalance = totBalance + depositAmount;
	ServiceChg(0.10);	
	AccountBalance();
}
	
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	
void AccountBalance () {
	Space(1);
	cout << setprecision(2) << "You current Account Balance is: $" << totBalance << "." << endl;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void Warn50 () {
	if (totBalance < 50.01) {
		cout << "Warning you have only " << totBalance << " left in your account.";
		Space(1);
	}
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void Space (int x) {
	int y;
	for (y=0; y<x; y++) {
		cout << endl;
	}
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void ServiceChg(float x) {
	serviceChg = serviceChg + x;
	cout << setprecision(2) << "Service Fee: $" << x << "." << endl;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void Check500() {
	if (totBalance < 500 && fiveFine) {
		fiveFine = false;
		cout << "Account balance below $500.00." << endl;
		ServiceChg(5.00);
	}
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void EndProgram() {
	Space(1);
	AccountBalance();
	cout << "Total Service Fees: " << serviceChg << endl;
	totBalance = totBalance - serviceChg;
	AccountBalance();
}