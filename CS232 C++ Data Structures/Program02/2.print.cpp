//***************************************************************************************
// Neal A. Dreher         Sept 6, 2000
// CMPSC232               Wednesday 6:00
// Program 2              WinME, WinNT4, VC6
//
// 2.print.cpp
//
//***************************************************************************************

#include "2.h"

void print(const COIN& Coin) {

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout << setprecision(2);
	
	if (Coin.count) {  // dont do unless there is at least 1
		if (Coin.count == 1) {  // if there's only 1
			cout << setw(5) << Coin.count << Coin.single << " equals $" << double(Coin.denom) / 100 << endl;
			return;
		}
		// else not needed because else will always return
		cout << setw(5) << Coin.count << Coin.mult << " equal $" << double(Coin.denom * Coin.count) / 100 << endl;
	}
	return;
}