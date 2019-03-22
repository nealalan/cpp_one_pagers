// Earl Adams Tester Program For The Date Class
// reads file Pgm10B.dat
// outputs the results in file Pgm10B.txt

#include "date.h"
#include <fstream.h>
#include <iostream.h>
#include <iomanip.h>

//============================================== prefix_plus_plus
int prefix_plus_plus( const Date& one, const Date& two,
                      ostream& os )
   {
   Date three(two), four(1,1,1980);
   four = ++three;
   if (four != three || three != one)
      {
      os << "ERROR:  Before x = ++y, y was " << two << '\n'
         << "        Afterwards: x is " << four
         <<          "; should be " << one << '\n'
         << "                    y is " << three
         <<          "; should be " << one << "\a\n\n";
      return 0;
      }
   return 1;
   }

//============================================= postfix_plus_plus
int postfix_plus_plus( const Date& one, const Date& two,
                      ostream& os )
   {
   Date three(two), four(1,1,1980);
   four = three++;
   if (four != two || three != one)
      {
      os << "ERROR:  Before x = y++, y was " << two << '\n'
         << "        Afterwards: x is " << four
         <<          "; should be " << two << '\n'
         << "                    y is " << three
         <<          "; should be " << one << "\a\n\n";
      return 0;
      }
   return 1;
   }

//==================================================== plus_equal
int plus_equal( const Date& one, const Date& two,
                long delta, ostream& os )
   {
   Date three(two), four(1, 1, 1980);
   four = three += delta;
   if (four != three || three != one)
      {
      os << "ERROR:  " << two << " += " << delta << " yields "
         << three << "; should be " << one << "\n\trvalue is "
         << four << "; should be " << one << "\a\n\n";
      return 0;
      }
   return 1;
   }

//=================================================== minus_equal
int minus_equal( const Date& one, const Date& two,
                 long delta, ostream& os )
   {
   Date three(one), four(1, 1, 1980);
   four = three -= delta;
   if (four != three || three != two)
      {
      os << "ERROR:  " << one << " -= " << delta << " yields "
         << three << "; should be " << two << "\n\trvalue is "
         << four << "; should be " << two << "\a\n\n";
      return 0;
      }
   return 1;
   }

//====================================================== test_all
int test_all( const Date& one, const Date& two, long delta,
              ostream& os )
   {
   if (plus_equal(one, two, delta, os))
      if (minus_equal(one, two, delta, os))
         if (delta == 1 && prefix_plus_plus(one, two, os))
            if (postfix_plus_plus(one, two, os))
               return 1;
   return 0;
   }

//========================================================== main
main()
   {
   Date date_1, date_2;
   long   delta;
   const char *inname = "Pgm10B.dat", *outname = "Pgm10B.txt";
   ifstream infile(inname);
   if (!infile)
      {
      cerr << "Cannot open input file " << inname << '\n';
      return 1;
      }
   ofstream outfile(outname);
   if (!outfile)
      {
      cerr << "Cannot open input file " << outname << '\n';
      return 1;
      }

   outfile << " DATE 1         DATE 2       DIFFERENCE\n\n";
   while ( infile >> date_1 >> date_2 >> delta )
      {
      outfile << date_1 << "     " << date_2
              << setw(12) << delta << '\n';
      if (test_all(date_1, date_2, delta, outfile))
         test_all(date_2, date_1, -delta, outfile);
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
