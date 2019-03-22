//***************************************************************************************
// Neal A. Dreher         Sept 20, 2000
// CMPSC232               Wednesday 6:00
// Program 3              
//
// 3.initrec.h
//
//  this passes the values brought in, over to dynamic memory or if the memory dosen't
//  exist yet (desc is FALSE) then make the memory all equal to 0
//
//  if a desc is not passed, then it defaults to 0 as defined in costrec.h
//***************************************************************************************

#include "costrec.h"

void initRec(CostRec& costrecs, int itemno, int qty , double cost, int type, char* desc) {

	if(desc) {

		costrecs.itemno = itemno;
		costrecs.qty = qty;
		costrecs.cost = cost;
		// define the size of the char away as the len of descr + 1
		costrecs.desc = new char[strlen(desc) + 1]; 
		strcpy(costrecs.desc, desc);

		switch(type) {
		case 0 :
			costrecs.itemtype = Magazine;
			break;
		case 1 :
			costrecs.itemtype = NonFood;
			break;
		case 2 :
			costrecs.itemtype = Food;
			break;
		default :
			costrecs.itemtype = Invalid;
			break;
		}


	}
	else {
		itemno = 0;
		qty = 0;
		cost = 0;
		type = Invalid;
		desc = 0;
	}







	return;
}



