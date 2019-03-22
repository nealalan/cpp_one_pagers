//***************************************************************************************
// Neal A. Dreher         Sept 11, 2000
// CMPSC232               Wednesday 6:00
// Program 1
//
// 1.calcrec.cpp
//
//***************************************************************************************

#include "costrec.h"

double calcRec(const COSTREC& CostRec) {
	if (CostRec.itemtype == Food) return CostRec.qty * CostRec.cost + (CostRec.qty * CostRec.cost * 0.02);
	if (CostRec.itemtype == NonFood) return CostRec.qty * CostRec.cost + (CostRec.qty * CostRec.cost * 0.07);
	return CostRec.qty * CostRec.cost;

}
