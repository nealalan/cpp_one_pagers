//***************************************************************************************
// Neal A. Dreher         Sept 11, 2000
// CMPSC232               Wednesday 6:00
// Program 1
//
// 1.readrec.cpp
//
//***************************************************************************************

#include "costrec.h"

istream& readRec(COSTREC& CostRec, istream& costfile, int& itemamt) {

	int type;

	if (costfile >> CostRec.qty >> CostRec.itemno >> CostRec.cost >> type >> ws && costfile.get(CostRec.desc, DESCRIPTION_LEN)) {
		//determine what the itemtype is and assign it
		switch(type) {
		case 0 :
			CostRec.itemtype = Magazine;
			break;
		case 1 :
			CostRec.itemtype = NonFood;
			break;
		case 2 :
			CostRec.itemtype = Food;
			break;
		default :
			cerr << "Line " << itemamt + 1<< ": Invalid itemtype detected!\n";
			CostRec.itemtype = Invalid;
			break;
		}
	}
	return costfile;
}