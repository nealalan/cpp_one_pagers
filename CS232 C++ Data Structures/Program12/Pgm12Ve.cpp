// Pgm12Ve.CPP  Test BigInt class by computing factorials

#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>       // for exit() and atoi()
#include <time.h>         // for time_t and time( 0 )
#include <crtdbg.h>
#include "12.main.h"


// local prototypes
BigInt factorial( int n );
void process( int, char*[] );
void print_time( char* s1, long t, char* s2 );

main( int argc, char* argv[] )
   {
   if ( argc == 1 )
      {
      cerr << "Usage: fact n1 [n2  n3 ...]\n";
      return 1;
      }
   _CrtMemState sb1, sb2, sb3;
   _CrtMemCheckpoint (&sb1);
   _CrtMemState s1, s2, s3;
   _CrtMemCheckpoint (&s1);
   process( argc, argv );
   _CrtMemCheckpoint (&s2);
   if (_CrtMemDifference (&s3, &s1, &s2))
     _CrtMemDumpStatistics (&s3);
   _CrtDumpMemoryLeaks ();
   _CrtMemCheckpoint (&sb2);
   if (!_CrtMemDifference (&sb3, &sb1, &sb2))
    cout << endl << "Ok, no memory leaks" << endl;
   return 0;
   }


void process( int argc, char* argv[] )
   {
   BigInt f;
   int n;
   time_t start, finish;
   for ( int i = 1; i < argc; i++ )
      {
      n = atoi( argv[i] );
      cout << n << "! = ";
      start = time( 0 );
      f = factorial( n );
      finish = time( 0 );
      cout << f << "\n\n";
      print_time( "Elapsed time (HH:MM:SS) = ", finish - start, "\n\n" );
      }
   }



BigInt factorial( int n )
   {
   BigInt f( 1 ), temp;
   int multiplications, additions;
   for ( multiplications = 2; multiplications <= n; multiplications++ )
      {
      temp = f;
      for ( additions = 2; additions <= multiplications; additions++ )
         f = f + temp;
      }
   return f;
   }


void print_time( char* s1, long t, char* s2 )
   {
   int hr = int( t / 3600 );
   int min = int( t % 3600 / 60 );
   int sec = int( t % 60 );
   char old_fill = cout.fill( '0' );
   cout << s1
        << setw( 2 ) << hr << ':'
        << setw( 2 ) << min << ':'
        << setw( 2 ) << sec
        << s2;
   cout.fill( old_fill );
   }

