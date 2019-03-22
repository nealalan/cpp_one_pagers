//**************************************************************
//  Neal Dreher	 -  13 June 2000
//  CS212AA, T + Th 10:30
//  1b4.main.cpp	
//  1b4
//
//  reads input like:  123456789 12.34 Anderson, Dennis K.
//    also picks the first and last name in alpha order
//**************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>  // for exit()

#include <string>  // for strcmp()

using namespace std;

int main() {

	long num, fnum, lnum, customers = 0;
	char name[26], fname[26] = "ZZZZZ", lname[26] = "AAAAA";
	double bal = 0, fbal = 0, lbal = 0, totbal = 0;

	// open the disk input file.
	char inputFilename[50];

	cout << "\nEnter name of sales input file: ";
	cin >> inputFilename;
	ifstream fin( inputFilename );
	if( !fin ) {
		cout << "Could not open sales input file " << inputFilename << '\n';
		exit( 1 );
	}

   
    // open the sales report disk output file.
    char outputFilename[50];
    ofstream fout;
    cout << "\nEnter name of report output file: ";
    cin >> outputFilename;
    fout.open( outputFilename );
    if( !fout ) {
        cout << "Could not open report output file " << outputFilename << '\n';
        exit( 1 );
    }

    fout << "Unit 1, Assign B Ver 1 using data file " << inputFilename << "\nProgrammed by Neal Dreher\n\n";
    fout << "  ACCOUNT                                    ACCOUNT\n  NUMBER                NAME                 BALANCE\n";
 
	while ( (fin >> num >> ws >> bal >> ws) && fin.get(name, 26, '\n') ) {

		fin.ignore(100, '\n');
 	    totbal += bal;
	    //test for first of last alpha name
	    if (0 > strcmp(name, fname)) {
	 	    strcpy(fname, name);
 		    fbal = bal; 
		    fnum = num;
		}
   	    if (0 < strcmp(name, lname)) {
	 	    strcpy(lname, name);
		    lbal = bal;
		    lnum = num;
		}

	    customers++;
	    // print each line for each customer
	    fout << endl << setw(10) << num << "      " << left << setw(26) << name << right << setw(10.2) << bal;
    }

    if (customers != 0) {
	    fout << "\n\n" << customers << " CUSTOMERS PROCESSED\nAVERAGE ACCOUNT BALANCE " << setw(28.2) << fixed << setprecision(2) << totbal / customers<< "\n\n";
	    fout << "FIRST IN ALPHABETICAL ORDER\n" << setw(10) << fnum << "      " << left << setw(26) << fname << right << setw(10.2) << fbal << "\n\n";
	    fout << "LAST IN ALPHABETICAL ORDER\n" << setw(10) << lnum << "      " << left << setw(26) << lname << right << setw(10.2) << lbal << "\n";

    }
    else fout << "\n\nI/O ERROR: Possible no customers in \n           file or incorrect file format!\n\n";

    return 0;

}