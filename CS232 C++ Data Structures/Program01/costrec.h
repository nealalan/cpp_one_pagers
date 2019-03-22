//***************************************************************************************
// Neal A. Dreher         Sept 11, 2000
// CMPSC232               Wednesday 6:00
// Program 1              
//
// costrec.h
//
//***************************************************************************************

#ifndef COSTRECH

#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>  // for exit()
//include the null char and the leading ' '
#define DESCRIPTION_LEN 31

enum ItemType{Magazine, NonFood, Food, Invalid};

struct COSTREC {
	int itemno;
	int qty;
	double cost;
	ItemType itemtype;
	char desc[DESCRIPTION_LEN];
};

istream& readRec(COSTREC& CostRec, istream& costfile, int& itemamt);
double calcRec(const COSTREC& CostRec);
void printRec(const COSTREC& CostRec, ofstream& outfile, double totcost);

#endif COSTRECH