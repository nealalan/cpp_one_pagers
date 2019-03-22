// Pgm12Vc.CPP  Tests BigInt class compare function

#include <iostream.h>
#include <stdlib.h>      // for exit()
#include <fstream.h>
#include <crtdbg.h>
#include "bigint.h"


//================================================ compare_symbol
const char* compare_symbol( int n )
   {
   return n < 0 ? "<" : n > 0 ? ">" : "==";
   }

//======================================================== tester
int tester( const BigInt& a, const BigInt& b,
           int key, int print = 0 )
   {
   int result = a.compare( b );
   int error = result != key;
   if ( error || print )
      {
      cout << a << ' ' << compare_symbol( result )
           << ' ' << b << '\n';
      if ( error )
         cout << "\a***Error***  Should be "
              << compare_symbol( key ) << '\n';
      cout << '\n';
      }
   return error;
   }

//======================================================= process
void process()
   {
   ifstream is ("Pgm12c.txt");
   if (!is) {
    cout << "Error: cannot find file Pgm12c.txt" << endl;
    return;
   }

   BigInt a, b;
   int key;

   while ( is >> a >> b >> key )
      if ( tester( a, b, key, 1 ) == 0 )
         tester( b, a, -key );
   }

//========================================================== main
main()
   {
   _CrtMemState sb1, sb2, sb3;
   _CrtMemCheckpoint (&sb1);
   _CrtMemState s1, s2, s3;
   _CrtMemCheckpoint (&s1);
   process();
   _CrtMemCheckpoint (&s2);
   if (_CrtMemDifference (&s3, &s1, &s2))
     _CrtMemDumpStatistics (&s3);
   _CrtDumpMemoryLeaks ();
   _CrtMemCheckpoint (&sb2);
   if (!_CrtMemDifference (&sb3, &sb1, &sb2))
    cout << endl << "Ok, no memory leaks" << endl;
   return 0;
   }

