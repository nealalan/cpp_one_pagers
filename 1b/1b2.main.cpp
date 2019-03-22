//**************************************************************
//  Neal Dreher	 -  13 June 2000
//  CS212AA, T + Th 10:30
//  1b2.main.cpp	
//  1b2
//
//  reads input like this: 123456789  "Anderson, Denis K." 12.34
//**************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>  // for exit()

using namespace std;

int main() {

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


   long num, customers = 0;
   char name[26];
   double bal = 0, totbal = 0;

   fout << "Unit 1, Assign B Ver 1 using data file " << inputFilename << "\nProgrammed by Neal Dreher\n\n";
   fout << "  ACCOUNT                                    ACCOUNT\n  NUMBER                NAME                 BALANCE\n";
 


   while ( (fin >> num) && fin.ignore(100, '"') && fin.get(name, 26, '"')) {

	   fin.ignore(100, '"');
	   fin >> ws >> bal;
 	   fin.ignore(100, '\n');
	   totbal += bal;
	   customers++;

	   fout << endl;
	   fout << setw(10) << num;
	   fout << "      " << left << setw(26) << name;
	   fout << right << setw(10.2) << bal;

   }


   if (customers != 0) fout << "\n\n" << customers << " CUSTOMERS PROCESSED\nAVERAGE ACcOUNT BALANCE " << setw(28.2) << fixed << setprecision(2) << totbal / customers<< "\n";
   else fout << "\n\n ERROR: No customers in file or incorrect format!";

   return 0;

}