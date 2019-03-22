//***************************************************************************************
// Neal A. Dreher         Sept 20, 2000
// CMPSC232               Wednesday 6:00
// Program 3
//
// 3.printrec.cpp
//
//  print all the stuff in the current structure out
//  also realize is there is no valid tax type, the final price can not be found
//***************************************************************************************

#include "costrec.h"

void printRec(const CostRec& costrecs, ofstream& outfile, double totcost) {

	outfile.setf(ios::fixed, ios::floatfield);
	outfile.setf(ios::showpoint);
	outfile << setprecision(2) << setw(6) << costrecs.itemno;
	outfile << setw(5) << costrecs.qty << setw(10);
	if (costrecs.itemtype == Food) outfile << "Food     ";
	else if (costrecs.itemtype == NonFood) outfile << "Non-Food ";
	else if (costrecs.itemtype == Magazine) outfile << "Magazine ";
	else {
		outfile << "Invalid  ";
		outfile.setf(ios::left, ios::adjustfield);
		outfile << setw(31) << costrecs.desc;
		outfile.setf(ios::right, ios::adjustfield);
		outfile << setw(7) << costrecs.cost << setw(8)<< "Tax Err" << endl;
		return;
	}
	outfile.setf(ios::left, ios::adjustfield);
	outfile << setw(31) << costrecs.desc;
	outfile.setf(ios::right, ios::adjustfield);
	outfile << setw(7) << costrecs.cost << setw(8)<< totcost << endl;

	return;
}