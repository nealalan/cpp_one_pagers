//**************************************************************
//  Neal Dreher	 -  08 June 2000
//  CS212AA, T + Th 10:30
//  1a.main.cpp	
//  1a
//
//  This assignment reads an input file from a prompt and asks
//  for the output file (con = console).  It processes the data
//  by reading id number and balance and figuring the amount 
//  due, the high balance, low balance and average balance and
//  and amount due.
//**************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>  // for exit()

#include <stdio.h>

using namespace std;

//===============================================================
int main() {

   int actamt = 0;
   
   // open the disk input file.
   char inputFilename[50];

   cout << "\nEnter name of sales input file: ";
   cin >> inputFilename;
   ifstream fin( inputFilename );
   if( !fin ) {
      cout << "Could not open sales input file "
           << inputFilename << '\n';
      exit( 1 );
   }

   // open the sales report disk output file.
   char outputFilename[50];
   ofstream fout;
   cout << "\nEnter name of report output file: ";
   cin >> outputFilename;
   fout.open( outputFilename );
   if( !fout ) {
       cout << "Could not open report output file "
            << outputFilename << '\n';
       exit( 1 );
   }

   cout << "\nReading from " << inputFilename << endl;
   cout << "\nWriting to " << outputFilename << endl << endl;
   
   // Read the sales input file and create the sales report.

   int actnum = 0, lactnum = 0, hactnum = 0;
   double bal = 0.0, due = 0.0, avgbal = 0.0, avgdue = 0.0, hbal = 0.0, lbal = 10000000;

   fout << fixed << setprecision(2);

   fout << "  ACCOUNT               AMOUNT\n";
   fout << "  NUMBER     BALANCE     DUE\n\n";

   while ( fin >> actnum >> bal) {

	   if (bal > .00 && bal <= 10.00) due = bal;
	   else if (bal > 10.00 && bal <= 100.00) due = 10.00;
	   else if (bal > 100.00 && bal <= 1000.00) due = bal * .1;
	   else if (bal > 1000.00) due = bal * .2;

	   avgbal += bal;
	   avgdue += due;
	   if (bal > hbal) {
		   hbal = bal;
		   hactnum = actnum;
	   }
	   if (bal < lbal) {
		   lbal = bal;
		   lactnum = actnum;
	   }

	   fout << setw(10) << actnum << setw(10) << bal << setw(10) << due << endl;
	   due = 0.0;
	   actamt++;

   }

   fout << endl << " AVERAGES " << setw(10) << avgbal / actamt << setw(10) << avgdue / actamt << endl << endl;

   fout << " HIGHEST BALANCE = " << hbal << " FOR ACCOUNT #" << hactnum << endl;
   fout << " LOWEST BALANCE = " << lbal << " FOR ACCOUNT #" << lactnum << endl;



   // est for successful completion
   if( !fin.eof() || actamt == 0) {
      fout << "\nInvalid input data; program aborted" << endl;
      cout << "\nInvalid input data; program aborted" << endl;
   }

   // close files (done automatically when program ends)
   fin.close();
   fout.close();
   return 0;
}
