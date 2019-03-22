//***************************************************************************************
// Neal A. Dreher         Sept 20, 2000
// CMPSC232               Wednesday 6:00
// Program 3
//
// 3.delrec.cpp
//
//  this file deallocates all the descriptions in the array of structures that were
//  dynamically allocated and then deletes all of the structures that were dynamic
//***************************************************************************************

#include "costrec.h"

void delRec(CostRec& costrecs) {

	if(costrecs.desc) delete []costrecs.desc;
	delete &costrecs;
	
	return;						
}
