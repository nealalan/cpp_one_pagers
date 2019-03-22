// Pgm12Vf.CPP  Tests operator + and operator -
// Depends on all other functions.

#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>      // for exit()
#include <crtdbg.h>
#include "12.main.h"

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


//======================================================== tester
int tester( const BigInt& a, char op, const BigInt& b,
           const BigInt& key, int print = 0 )
   {
   BigInt c;
   if ( op == '+' ) c = a + b;
   else           c = a - b;

   int error = key.compare( c ) != 0;

   if ( error || print )
      {
      int aLen = a.length(), bLen = b.length();
      int cLen = c.length(), keyLen = key.length();
      int max = aLen > bLen ? aLen : bLen;
      if ( cLen > max ) max = cLen;
      if ( keyLen > max ) max = keyLen;
      max += 2;
      cout << '\n' << setw( max - a.length() ) << "" << a << '\n'
           << op << setw( max - b.length() - 1 ) << ""  << b << '\n'
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

   BigInt x, y, key;
   char op;
   ifstream is ("Pgm12f.txt");
   if (!is) {
    cout << "Error: cannot find file Pgm12f.txt\n";
    return;
   }

   while ( is >> x >> op >> y >> key )
      {
      switch ( op )
         {
         case '+' : if ( !tester( x, '+', y, key, 1 ) )
                       if ( !tester( y, '+', x, key ) )
                          if ( !tester( key, '-', x, y ) )
                             if ( !tester( x, '-', key, y ) )
                                if ( !tester( key, '-', y, x ) )
                                   tester( y, '-', key, x );
                    break;
         case '-' : if ( !tester( x, '-', y, key, 1 ) )
                       if ( !tester( y, '-', x, key ) )
                          if ( !tester( x, '-', key, y ) )
                             if ( !tester( key, '-', x, y ) )
                                if ( !tester( key, '+', y, x ) )
                                   tester( y, '+', key, x );
                    break;
         default  : cout << "\a\nInvalid op code: " << op << '\n';
                    break;
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

