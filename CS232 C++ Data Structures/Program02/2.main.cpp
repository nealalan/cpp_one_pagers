//***************************************************************************************
// Neal A. Dreher         Sept 6, 2000
// CMPSC232               Wednesday 6:00
// Program 2              WinME, WinNT4, VC6
//
// 2.main.cpp
//
//  This program inputs a cent amt and outputs the min amt of coins in the cent amt.
//  Example (loops at end):
//
//	Please enter the amount in cents ($1.18 = 118): 599
//
//		5 Gold Dollars equal $5.00
//		1 Half Dollar equals $0.50
//		1 Quarter equals $0.25
//		2 Dimes equal $0.20
//		4 Pennies equal $0.04
//
//	Press <Ctrl-Z> or enter 0 to exit.
//
//***************************************************************************************

#include "2.h"

void main() {

	COIN Coin[6] = {
		{100,0," Gold Dollar"," Gold Dollars"}, 
		{50,0," Half Dollar"," Half Dollars"}, 
		{25,0, " Quarter", " Quarters"}, 
		{10,0, " Dime", " Dimes"}, 
		{5,0," Nickel"," Nickels"}, 
		{1,0," Penny"," Pennies"} 
	};
	long moneyamt;

	cout << "Please enter the amount in cents ($1.18 = 118): ";

	while (cin >> moneyamt && moneyamt > 0) {  // while there is input
		cout << endl;
		// loop thru each array number until all are done
		for (int curr = 0; curr <= 5; curr++) {  
			change(moneyamt, Coin[curr]);
			print(Coin[curr]);
		}
		cout << "\nPress <Ctrl-Z> or enter 0 to exit.\n\n";
		cout << "Please enter the amount in cents ($1.18 = 118): ";
	}

	return;
}