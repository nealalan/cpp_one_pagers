//***************************************************************************************
// Neal A. Dreher         Sept 6, 2000
// CMPSC232               Wednesday 6:00
// Program 2              WinME, WinNT4, VC6
//
// 2.change.cpp
//
//  subtract the current coin and figure a new total
//***************************************************************************************

#include "2.h"

void change(long &moneyamt, COIN& Coin) {

	// divide to find how many of that coin will fit in the moneyamt
	Coin.count =  moneyamt / Coin.denom;
	// fig how much is left w/out this coin denom
	moneyamt = moneyamt - (Coin.count * Coin.denom); 
	return;
}

