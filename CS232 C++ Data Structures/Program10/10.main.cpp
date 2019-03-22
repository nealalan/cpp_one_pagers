//***************************************************************************************
// Neal A. Dreher         Nov 8, 2000
// CMPSC232               Wednesday 6:00
// Program 10             WinNT4, VC6
//
// 10.main.cpp    Date Class III
//
// REVISION 1:
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
// REVISION 2:
//		1: add the new constructors 
//		2: add the member functions: Compare, Difference, Add, Subtract, Input, Output
//		3: USE THE FUNCTIONS CORRECTLY
//			A: ALWAYS USE DATE::SETDATE() TO SET A SERIALDATE
//			B: ALWAYS USE DATE::GETDATE() TO RETURN BY REF 3 INT'S
// REVISION 3:
//		1: Remove Add(), Subtract(), Difference(), Compare(), Input(), Output() functions
//		2: Add Overloaded Functions for >> << + - == != > < >= <= ++date date++ --date 
//			date-- +== -=
//		3: Add following int functions: GetMont(), GetDay(), GetYear()
//
//***************************************************************************************

#include "10.main.h"


// prefix_plus_plus
int prefix_plus_plus(const Date& one, const Date& two, ostream& os) {
	Date three(two), four(1,1,1980);
	four = ++three;
	if (four != three || three != one) {
		os << "ERROR:  Before x = ++y, y was " << two << '\n' << "        Afterwards: x is " 
			<< four <<          "; should be " << one << '\n' << "                    y is " 
			<< three <<          "; should be " << one << "\a\n\n";
		return 0;
	}
	return 1;
}

// postfix_plus_plus
int postfix_plus_plus(const Date& one, const Date& two, ostream& os) {

	Date three(two), four(1,1,1980);
	four = three++;
	if (four != two || three != one) {
		os << "ERROR:  Before x = y++, y was " << two << '\n' << "        Afterwards: x is " 
			<< four <<          "; should be " << two << '\n' << "                    y is "
			<< three <<          "; should be " << one << "\a\n\n";
		return 0;
	}
	return 1;
}

// plus_equal
int plus_equal(const Date& one, const Date& two, long delta, ostream& os ) {

	Date three(two), four(1, 1, 1980);
	four = three += delta;
	if (four != three || three != one) {
		os << "ERROR:  " << two << " += " << delta << " yields " << three << "; should be "
			<< one << "\n\trvalue is " << four << "; should be " << one << "\a\n\n";
		return 0;
	}
	return 1;
}

// minus_equal
int minus_equal(const Date& one, const Date& two, long delta, ostream& os) {

	Date three(one), four(1, 1, 1980);
	four = three -= delta;
	if (four != three || three != two) {
		os << "ERROR:  " << one << " -= " << delta << " yields " << three << "; should be "
			<< two << "\n\trvalue is " << four << "; should be " << two << "\a\n\n";
		return 0;
	}
	return 1;
}

// test_all
int test_all(const Date& one, const Date& two, long delta, ostream& os ) {

	if (plus_equal(one, two, delta, os))
		if (minus_equal(one, two, delta, os))
			if (delta == 1 && prefix_plus_plus(one, two, os))
				if (postfix_plus_plus(one, two, os))
					return 1;
				return 0;
}

// main
int main() {
	Date date_1, date_2;
	long   delta;
	const char *inname = "Pgm10B.dat", *outname = "Pgm10B.txt";
	ifstream infile(inname);
	if (!infile) { cerr << "Cannot open input file " << inname << '\n'; return 1; }
	ofstream outfile(outname);
	if (!outfile) { cerr << "Cannot open input file " << outname << '\n'; return 1; }

	outfile << " DATE 1         DATE 2       DIFFERENCE\n\n";
	while ( infile >> date_1 >> date_2 >> delta ) {
		outfile << date_1 << "     " << date_2 << setw(12) << delta << '\n';
		if (test_all(date_1, date_2, delta, outfile)) test_all(date_2, date_1, -delta, outfile);
	}

	Date A(12, 31, 1899);
	const Date B(1, 1, 2000);

	// Strange but true; all the following should work.
	// If you get compile-time errors, check your function
	// return types (should return reference to host).
	++A = B;
	(A += 1000) = B;
	(A -= 1000) = B;
	if (A != B) outfile << "\nA != B\n";
	cerr << "\nProgram output is written to disk file ASG03D.REP.\n";
	return 0;
}
