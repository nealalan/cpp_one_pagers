//***************************************************************************************
// Neal A. Dreher         Sept 11, 2000
// CMPSC232               Wednesday 6:00
// Program 1
//
// 1.printrec.cpp
//
//***************************************************************************************

#include "costrec.h"

void printRec(const COSTREC& CostRec, ofstream& outfile, double totcost) {

	outfile.setf(ios::fixed, ios::floatfield);
	outfile.setf(ios::showpoint);
	outfile << setprecision(2) << setw(6) << CostRec.itemno;
	outfile << setw(5) << CostRec.qty << setw(10);
	if (CostRec.itemtype == Food) outfile << "Food     ";
	else if (CostRec.itemtype == NonFood) outfile << "Non-Food ";
	else if (CostRec.itemtype == Magazine) outfile << "Magazine ";
	else {
		outfile << "Invalid  ";
		outfile.setf(ios::left, ios::adjustfield);
		outfile << setw(31) << CostRec.desc;
		outfile.setf(ios::right, ios::adjustfield);
		outfile << setw(7) << CostRec.cost << setw(8)<< "Tax Err" << endl;
		return;
	}
	outfile.setf(ios::left, ios::adjustfield);
	outfile << setw(31) << CostRec.desc;
	outfile.setf(ios::right, ios::adjustfield);
	outfile << setw(7) << CostRec.cost << setw(8)<< totcost << endl;

	return;
}