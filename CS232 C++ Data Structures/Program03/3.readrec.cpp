//***************************************************************************************
// Neal A. Dreher         Sept 20, 2000
// CMPSC232               Wednesday 6:00
// Program 3
//
// 3.readrec.cpp
//
//  read in all the data from the passed file into temp vars then pass it to
//  init rec to have it put into the array of structures
//***************************************************************************************

#include "costrec.h"

istream& readRec(CostRec& costrecs, istream& costfile) {

	int qty = 0;
	int itemno = 0;
	double cost = 0.0;
	int type = 0;
	char desc[MAX_DESCR_LEN + 1];

	costfile >> qty >> itemno >> cost >> type >> ws;
	costfile.get(desc, MAX_DESCR_LEN + 1);

	initRec(costrecs, itemno, qty, cost, type, desc);

	return costfile;
}