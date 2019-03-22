//***************************************************************************************
// Neal A. Dreher         Sept 6, 2000
// CMPSC232               Wednesday 6:00
// Program 2              WinME, WinNT4, VC6
//
// 2.h
//***************************************************************************************

#ifndef COINH

#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>

struct COIN {
	int denom;  // # of cents in a coin type
	long count;  //# of coins in moneyamt
	const char* single;  // ie. penny
	const char* mult;  // ie. pennies
};

// do the calculations with moneyamt and the current struct in the array 
void change(long &moneyamt, COIN& Coin);
// print the output from the current struct in the array
void print (const COIN& Coin);

#endif COINH