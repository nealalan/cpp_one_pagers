//***************************************************************************************
// Neal A. Dreher         Sept 20, 2000
// CMPSC232               Wednesday 6:00
// Program 3
//
// 3.calcrec.cpp
//
//***************************************************************************************

#include "costrec.h"

double calcRec(const CostRec& costrecs) {
	if (costrecs.itemtype == Food) 
		return costrecs.qty * costrecs.cost + (costrecs.qty * costrecs.cost * 0.02);
	if (costrecs.itemtype == NonFood) 
		return costrecs.qty * costrecs.cost + (costrecs.qty * costrecs.cost * 0.07);
	return costrecs.qty * costrecs.cost;

}
