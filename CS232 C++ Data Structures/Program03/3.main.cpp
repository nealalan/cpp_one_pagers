//***************************************************************************************
// Neal A. Dreher         Sept 20, 2000
// CMPSC232               Wednesday 6:00
// Program 3              WinME, WinNT4, VC6
//
// 3.main.cpp
//
// (revision for program 1)
// this program inputs a file in the following format:
//     qty itemno unit_price itemtype 30char_descr
// and outputs it as:
//     itemno qty itemtype 30char_descr unit_price tot_price+tax
//
// (revision for program 3)
// use dynamically allocated memory to store the file into an array and then process
// and print it out
//***************************************************************************************

#include "costrec.h"

void main() {

	CostRec* costrecs[ARRAY_SIZE];
	int numrecs = 0;

	//  open up the input for test data (to be passed to readRed()
	//  then verify existance and err and exit if !exist
	ifstream costfile ("3a.input.txt", ios::in | ios::nocreate);
	ofstream outfile ("3a.output.txt");
	if (!costfile) { cerr << "There is no input file!\n"; exit(1); }
	//  allocate + initalize new CostRec
	costrecs[numrecs] = new CostRec;  
	initRec(*costrecs[numrecs]); 
	//  while the input file is still in a good state readRec(), inc
	//  current place in array, allocate + initalize new CostRec
	while (readRec(*costrecs[numrecs], costfile)) {
		numrecs++;  
		costrecs[numrecs] = new CostRec;
		initRec(*costrecs[numrecs]); 
	}
	//  forget last numrec because it is empty!
	numrecs--;
	//  print and calc the structure members for each item
	outfile << "ITEM # QTY ITEM TYPE ITEM DESCRIPTION               UNIT $ TOTAL $\n";
	outfile << "-------------------------------------------------------------------\n";
	for (int at = 0; at <= numrecs; at++) printRec(*costrecs[at], outfile, calcRec(*costrecs[at]));

	// deallocate all memory used for costrecs.desc, entire array of costrecs
	for (int here = 0; here <= numrecs + 1; here++) delRec(*costrecs[here]);

	//  check for memory leaks
	if ( _CrtDumpMemoryLeaks() ) cout << "Memory Leaks\n";
	else cout << "No Memory Leaks\n";

	return;
}

