// Pgm12Vc.CPP  Tests BigInt class compare function

#include <iostream.h>
#include <stdlib.h>      // for exit()
#include <fstream.h>
#include <crtdbg.h>
#include "12.main.h"


//================================================ compare_symbol
const char* compare_symbol( int n )
   {
   return n < 0 ? "<" : n > 0 ? ">" : "==";
   }

//======================================================== tester
int tester( const BigInt& a, const BigInt& b,
           int key, ostream& outfile,int print = 0 )
   {
   int result = a.compare( b );
   int error = result != key;
   if ( error || print )
      {
      outfile << a << ' ' << compare_symbol( result )
              << ' ' << b << '\n';
      if ( error )
        outfile << "\a***Error***  Should be "
               << compare_symbol( key ) << '\n';
      outfile << '\n';
      }
   return error;
   }

//======================================================= process
ostream& process(ostream& outfile)
   {
   ifstream is ("Pgm12c.txt");
   if (!is) {
    cout << "Error: cannot find file Pgm12c.txt" << endl;
    return outfile;
   }

   BigInt a, b;
   int key;

   while ( is >> a >> b >> key )
      if ( tester( a, b, key, outfile, 1 ) == 0 )
         tester( b, a, -key, outfile);
   return outfile;
   }

//========================================================== main
main()
{
   ofstream outfile ( "results.txt", ios::out );
   if ( ! outfile ) {
     cerr << "   Error, cannot open output data file 'results.txt' \n";
     return (2);
   }        // define and open output file - display error if failure

 
   _CrtMemState sb1, sb2, sb3;
   _CrtMemCheckpoint (&sb1);
   _CrtMemState s1, s2, s3;
   _CrtMemCheckpoint (&s1);
   process(outfile);
   _CrtMemCheckpoint (&s2);
   if (_CrtMemDifference (&s3, &s1, &s2))
     _CrtMemDumpStatistics (&s3);
   _CrtDumpMemoryLeaks ();
   _CrtMemCheckpoint (&sb2);
   if (!_CrtMemDifference (&sb3, &sb1, &sb2))
     outfile << endl << "Ok, no memory leaks" << endl;
   return 0;
}
