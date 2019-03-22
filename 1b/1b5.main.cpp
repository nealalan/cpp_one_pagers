//**************************************************************
//  Neal Dreher	 -  13 June 2000
//  CS212AA, T + Th 10:30
//  1b5.main.cpp	
//  1b5
//
//  reads input like: 123456789Anderson, Dennis K.;12.34 
//    also checks for out of sequence or duplicate name
//    even tho they wouldn't be out of sequence if you used
//    qsort() to sort them as an array of structures
//**************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>  // for exit()

#include <string>  // for strcmp()

using namespace std;

int main() {

	long num, customers = 0;
	char name[26], lname[26] = "AAAAA";
	double bal = 0, totbal = 0;

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
 
	while ( (fin >> num >> ws) && fin.get(name, 26, ';') && fin.ignore(100, ';') && (fin >> ws >> bal) ) {

		fin.ignore(100, '\n');
	    // print each line for each customer
	    fout << endl << setw(10) << num << "      " << left << setw(26) << name << right << setw(10.2) << bal;

		if (!strcmp(name, lname)) fout << "  Duplicate name";
		else if (0 > strcmp(name, lname)) fout << "  Out of sequence";
		else strcpy(lname, name);

	    customers++;
 	    totbal += bal;

	}

    if (customers != 0) {
	    fout << "\n\n" << customers << " CUSTOMERS PROCESSED\nAVERAGE ACCOUNT BALANCE " << setw(28.2) << fixed << setprecision(2) << totbal / customers<< "\n\n";

    }
    else fout << "\n\nI/O ERROR: Possible no customers in \n           file or incorrect file format!\n\n";

    return 0;

}