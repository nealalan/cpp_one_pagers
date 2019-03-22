//***************************************************************************************
// Neal A. Dreher         Oct 18, 2000
// CMPSC232               Wednesday 6:00
// Program 7              WinNT4, VC6
//
// 7.main.cpp    A Begining Date Class
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
//
//***************************************************************************************

#include "7.main.h"

#include <fstream.h>
#include <iostream.h>
#include <iomanip.h>

// correct_difference
int correct_difference(const Date& one, const Date& two,long delta, ostream& os ) {
	long difference = one.Difference(two);
	if (difference != delta) {
		os << "ERROR: difference(";
		one.Output(os) << ", ";
		two.Output(os) << ") = " << difference << "; should be " << delta << "\a\n\n";
		return 0;
	}
	return 1;
}

// sign
int sign(long n) {
	return n < 0 ? -1 : n > 0;
}

// correct_compare
int correct_compare( const Date& one, const Date& two, long delta, ostream& os ) {

	static char *sign_array[] = {"negative", "zero", "positive" };
	static char **sign_string = &sign_array[1];
	int compare;

	compare = one.Compare(two);
	if (sign(compare) != sign(delta)) {
		os << "ERROR: compare(";
		one.Output(os) << ", ";
		two.Output(os) << ") = " << compare << "; should be " << sign_string[sign(delta)] << "\a\n\n";
		return 0; 
	} 
	return 1;
  }

//=================================================== correct_add
int correct_add( const Date& one, const Date& two, long delta, ostream& os ) {

	Date result;
	result= two.Add(delta);
	if (result.Compare(one) != 0) {
		os << "ERROR: add(";
		two.Output(os) << ", " << delta << ") = ";
		result.Output(os) << "; should be ";
		one.Output(os) << "\a\n\n";
		return 0;
	}
	return 1;
}

// correct_subtract
int correct_subtract( const Date& one, const Date& two, long delta, ostream& os ) {

	Date result;
	result= one.Subtract(delta);
   
	if (result.Compare(two) != 0) {
		os << "ERROR: subtract(";
		one.Output(os) << ", " << delta << ") = ";
		result.Output(os) << "; should be ";
		two.Output(os) << "\a\n\n";
		return 0;
	}
	return 1;
   }

// test_all
int test_all( const Date& one, const Date& two, long delta, ostream& os ) {
	if (correct_difference(one, two, delta, os))
		if (correct_compare(one, two, delta, os))
			if (correct_add(one, two, delta, os))
				if (correct_subtract(one, two, delta, os))
					return 1;
				return 0;
}

// main
void main() {
   
	Date date_1, date_2;
	long delta;
	const char *inname = "pgm7.dat", *outname = "pgm7.txt";

	ifstream infile(inname);
	if (!infile) {
		cerr << "Cannot open input file " << inname << '\n';
		return;
	}

	ofstream outfile(outname);
	if (!outfile) {
		cerr << "Cannot open input file " << outname << '\n';
		return;
	}

	outfile << " DATE 1         DATE 2       DIFFERENCE\n\n";
	while ( date_2.Input(date_1.Input(infile)) >> delta ) {
		date_1.Output( outfile ) << "     ";
		date_2.Output( outfile );
		outfile << setw(12) << date_1.Difference(date_2) << '\n';
		if (test_all(date_1, date_2, delta, outfile))
			test_all(date_2, date_1, -delta, outfile);
	}

	// Testing for const functions and parameters
	const Date conDateA(12, 31, 1899), conDateB(1, 1, 2000);
	long diff;
	diff = conDateA.Difference(conDateB);
	date_1 = conDateB.Add(diff);
	date_2 = conDateA.Subtract(diff);

	if (date_1.Compare(conDateA) || conDateB.Compare(date_2)) {
		outfile << "\n\a** Error using const Date objects. **\n";
	}

	conDateA.Output(outfile << "\nconDateA = ");
	conDateB.Output(outfile << "\nconDateB = ");
	date_1.Output(outfile << "\ndate_1   = ");
	date_2.Output(outfile << "\ndate_2   = ") << '\n';

	cerr << "\nProgram output is written to disk file " << outname << '\n';

	return;
}

