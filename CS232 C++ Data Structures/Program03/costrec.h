//***************************************************************************************
// Neal A. Dreher         Sept 20, 2000
// CMPSC232               Wednesday 6:00
// Program 3              
//
// costrec.h
//
//***************************************************************************************

#ifndef COSTRECH

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>

#include <stdlib.h>  // for exit()
#include <string.h>  // for strlen(), strcpy()
#include <crtdbg.h>  // for _CrtDumpMemoryLeaks()

#define MAX_DESCR_LEN 30
#define ARRAY_SIZE 100


enum ItemType{Magazine, NonFood, Food, Invalid};

struct CostRec {
	int itemno;
	int qty;
	double cost;
	ItemType itemtype;
	char* desc;
};

void initRec(CostRec& costrecs, int itemno=0, int qty=0, double cost=0, int type=0, char* descr=0);

istream& readRec(CostRec& costrecs, istream& costfile);

double calcRec(const CostRec& costrecs);

void printRec(const CostRec& costrecs, ofstream& outfile, double totcost);

void delRec(CostRec& costrecs);

#endif COSTRECH