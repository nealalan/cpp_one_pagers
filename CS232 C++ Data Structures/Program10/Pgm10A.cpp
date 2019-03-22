// Earl Adams Tester Program For The Date Class
// reads file Pgm10A.dat
// outputs the results in file Pgm10A.txt

#include "date.h"
#include <fstream.h>
#include <iostream.h>
#include <iomanip.h>

//============================================ correct_difference
int correct_difference( const Date& one, const Date& two,
                        long delta, ostream& os )
   {
   long difference = one - two;
   if (difference != delta)
      {
      os << "ERROR: " << one << " - " << two << " yields "
         << difference << "; should be " << delta << "\a\n\n";
      return 0;
      }
   return 1;
   }

//=============================================== correct_compare
int correct_compare( const Date& one, const Date& two,
                     long delta, ostream& os )
   {
   static char* name[6] = { "==", "!=", ">", "<", ">=", "<=" };
   bool actual, key;

   for (int i = 0; i < 6; i++)
      {
      switch (i)
         {
         case 0:  actual = one == two; key = delta == 0; break;
         case 1:  actual = one != two; key = delta != 0; break;
         case 2:  actual = one >  two; key = delta >  0; break;
         case 3:  actual = one <  two; key = delta <  0; break;
         case 4:  actual = one >= two; key = delta >= 0; break;
         case 5:  actual = one <= two; key = delta <= 0; break;
         }
      if (actual != key)
         {
         os << "ERROR: " << one << ' ' << name[i]  << ' ' << two
            << " yields " << actual << "; should be " << key
            << "\a\n\n";
         return 0;
         }
      }
   return 1;
   }

//=================================================== correct_add
int correct_add( const Date& one, const Date& two, long delta,
                 ostream& os )
   {
   Date result;
   result = two + delta;
   if (result != one)
      {
      os << "ERROR: " << two << " + " << delta <<  " yields "
         << result << "; should be " << one << "\a\n\n";
      return 0;
      }
   result = delta + two;
   if (result != one)
      {
      os << "ERROR: " << delta << " + " << two <<  " yields "
         << result << "; should be " << one << "\a\n\n";
      return 0;
      }
   return 1;
   }

//============================================== correct_subtract
int correct_subtract( const Date& one, const Date& two,
                      long delta, ostream& os )
   {
   Date result;
   result = one - delta;
   if (result != two)
      {
      os << "ERROR: " << one << " - " << delta << " yields "
         << result << "; should be " << two << "\a\n\n";
      return 0;
      }
   return 1;
   }

//====================================================== test_all
int test_all( const Date& one, const Date& two, long delta,
              ostream& os )
   {
   if (correct_difference(one, two, delta, os))
      if (correct_compare(one, two, delta, os))
         if (correct_add(one, two, delta, os))
            if (correct_subtract(one, two, delta, os))
               return 1;
   return 0;
   }

//========================================================== main
main()
   {
   Date date_1, date_2;
   long   delta;
   const char *inname = "Pgm10A.dat", *outname = "Pgm10A.txt";
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
              << setw(12) << (date_1 - date_2) << '\n';
      if (test_all(date_1, date_2, delta, outfile))
         test_all(date_2, date_1, -delta, outfile);
      }

   // Testing for const functions and parameters
   const Date conDateA(12, 31, 1899), conDateB(1, 1, 2000);
   long diff;
   diff = conDateA - conDateB;
   date_1 = conDateB + diff;
   date_2 = conDateA - diff;
   if (date_1 != conDateA || conDateB != date_2)
      outfile << "\n\a** Error using const Date objects. **\n";
   outfile << "\nconDateA = " << conDateA
           << "\nconDateB = " << conDateB
           << "\ndate_1   = " << date_1
           << "\ndate_2   = " << date_2 << '\n';
   cerr << "\nProgram output is written to disk file ASG03C.REP.\n";
   return 0;
   }
