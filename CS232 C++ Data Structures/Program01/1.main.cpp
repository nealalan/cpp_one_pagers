//***************************************************************************************
// Neal A. Dreher         Sept 11, 2000
// CMPSC232               Wednesday 6:00
// Program 1              WinME, WinNT4, VC6
//
// 1.main.cpp
//
// this program inputs a file in the following format:
//     qty itemno unit_price itemtype 30char_descr
// and outputs it as:
//     itemno qty itemtype 30char_descr unit_price tot_price+tax
//***************************************************************************************

#include "costrec.h"

void main() {

	ifstream costfile ("1a.input.txt", ios::in | ios::nocreate);
	ofstream outfile ("1a.output.txt");

	COSTREC CostRec;
	int itemamt = 0;

	// check to see if there is a data file to read from
	if (!costfile) { 
		cerr << "There is no input file!\n";
		exit(1);
	}

	// print outfile heading
	outfile << "ITEM # QTY ITEM TYPE ITEM DESCRIPTION               UNIT $ TOTAL $\n";
	outfile << "-------------------------------------------------------------------\n";

	while (readRec(CostRec, costfile, itemamt)) {
		itemamt++;  // for err check to calc line #
		printRec(CostRec, outfile, calcRec(CostRec));
	}

}

