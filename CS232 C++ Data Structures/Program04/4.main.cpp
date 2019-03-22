//***************************************************************************************
// Neal A. Dreher         Sept 27, 2000
// CMPSC232               Wednesday 6:00
// Program 4              WinNT4, VC6
//
// 4.main.cpp    A Begining Date Class
//
// This program was to be written so it could be a royal pain in the butt for me
// to figure out.  Pretty much here's what happens:
//		1: create the in and out files and test for existance
//		2: do a loop to output a bunch of date conversions that are
//			stored in the class Date
//		3: Date stores in a protected variable called serialdate and the majority of the
//			world (date1) works all around the serialdate stored
//			A: first off SetDate is called so that SerialToDate can create the protected 
//				serialdate for the rest of the world to work with
//			B: FormatDate gives a string output, derived from serialdate,
//				which is converted with GetDate to an actual human date (mo/da/year)
//		4: main.h calls date.h so that date.cpp will work (51 errors otherwise)
//		
//***************************************************************************************

#include "4.main.h"

void main() {

	int mo, da, yr;
	char string[11];
	
	Date date1;

	ifstream infile("4.dates1.dat");
	ofstream outfile("4.output.txt");

	if (!infile) { 
		cerr << "Cannot open input file.\n"; 
		exit(0); 
	}
	if (!outfile) { 
		cerr << "Cannot open output file.\n"; 
		exit(0); 
	}

	outfile.setf(ios::fixed, ios::floatfield);
	outfile.setf(ios::showpoint);

	// to catch the jist of what's inside the while loop, it's printing
	// each collumn

	outfile << "date          date from     date from     date to    date from\n";
	outfile << "input         GetDate       FormatDate    serial     serial\n\n";

	infile >> dec;
	while (infile >> mo >> da >> yr) {

		date1.SetDate(mo, da, yr);
		outfile << setw(2) << mo << ' ' << setw(2) << da << setw(5) << yr;
		date1.GetDate(mo, da, yr);
		outfile << "    " << setfill('0') << setw(2) << mo << '/' << setw(2) << da << '/' << setw(4) << yr;
		date1.FormatDate(string, strlen(string));
		outfile << "   " << string << "    " << date1.DateToSerial(mo, da, yr);
		date1.SerialToDate(mo, da, yr);
		outfile << "    " << setfill('0') << setw(2) << mo << '/' << setw(2) << da << '/' << setw(4) << yr << endl;
		outfile << setfill(0);
	}

	return;
}