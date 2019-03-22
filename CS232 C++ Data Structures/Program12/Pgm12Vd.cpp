// Pgm12Vd.CPP  Tests BigInt addition operator

#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>      // for exit()
#include <crtdbg.h>
#include "12.main.h"

const char* string( int n, char c );

//======================================================== tester
int tester( const BigInt& a, const BigInt& b,
            const BigInt& key, int print = 0 )
   {
   BigInt c = a + b;

   int error = c.compare( key ) != 0;

   if ( error || print )
      {
      int cLen = c.length(), keyLen = key.length();
      int max = 2 + ( keyLen > cLen ? keyLen : cLen );
      cout << '\n' << setw( max - a.length() ) << "" << a << '\n'
           << '+'  << setw( max - b.length() - 1 ) << ""  << b << '\n'
           << string( max, '-' ) << '\n'
           << setw( max - cLen ) << "" << c;
     if ( error )
        cout << "\a <-----ERROR\n" << setw( max - keyLen )
             << "" << key << " <-----SHOULD BE";
     cout << "\n\n";
     }
   return error;
   }

//======================================================= process
void process()
   {

   const BigInt zero( "0" );
   BigInt a, b, key;
   ifstream is ("Pgm12d.txt");
   if (!is) {
    cout << "Error: could not open the Pgm12d.txt file\n";
    return;
   }
   while ( is >> a >> b >> key )
      {
      if ( tester( a, b, key, 1 ) == 0 )
         {
         tester( b, a, key );
         tester( a, zero, a );
         tester( zero, b, b );
         }
      }
   string( -1, 0 );
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

//======================================================== string
const char* string( int n, char c )
   {
   static char *p = 0;
   delete [] p;
   if ( n < 0 ) return 0;
   p = new char[n + 1];
   memset( p, c, n );
   p[n] = 0;
   return p;
   }

