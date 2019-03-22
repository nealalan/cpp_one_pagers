// Pgm12Va.CPP  Visual C++ Version
// Tests BigInt class constructors, assignment operator,
// insertion operator, and length() function.


#include <iostream.h>
#include <strstrea.h>
#include <string.h>
#include <stdlib.h>         // for exit()
#include <crtdbg.h>
#include "12.main.h"

// external variables used only by comparer() function
char buffer[1000];
ostrstream ostr( buffer, sizeof( buffer ) );


int comparer( int line, const BigInt& bi, const char* key )
   {
   ostr.seekp( 0 );
   ostr << bi << ends;
   if ((unsigned) bi.length() != strlen( key ) || strcmp( buffer, key ) != 0 )
      {
      cout << "\aError, called from Line #" << line << "\n"
           << "length() returned " << bi.length()
           << "; should be " << strlen( key )
           << "\nBigInt    = *" << bi << '*'
           << "\nShould be = *" << key << "*\n";
      exit( 1 );
      }
   return 1;
   }

// NOTE: Some parts of this function are commented out.
// They test for the handling of a string with leading blanks
// and/or zeros, an empty string, and a null pointer.
// Your constructor does not have to handle these situations.

ostream& string_constructor(ostream& outfile)
   {
   outfile << "Testing string constructor\n"
           "--------------------------\n";
   const char* s[] =   {
                       "1234567890",
                       "0",
                       "98765432109876543210",
                       "999999888888777777666666555555"
                       "444444333333222222111111000000" /* ,
                       "",
                       "000001234567890",
                       "00000000000",
                       "00098765432109876543210",
                       "     1234567890",
                       "           0",
                       "       00098765432109876543210",
                       "   000",
                       "     ",
                       0 */
                       };
   const char* key[] = {
                       s[0], s[1], s[2], s[3] /* s[1],
                       s[0], s[1], s[2],
                       s[0], s[1], s[2], s[1], s[1],
                       s[1], */
                       };

   BigInt bi[] = { s[0], s[1], s[2], s[3], /* s[4], s[5], s[6],
                s[7], s[8], s[9], s[10], s[11], s[12] s[13] */ };

   for ( int i = 0; i < sizeof( s ) / sizeof( *s ); i++ )
      {
      outfile << bi[i] << '\n';
      comparer( __LINE__, bi[i], key[i] );
      }
   return outfile;
   }

ostream& ulong_constructor(ostream& outfile)
   {
   outfile << "\nTesting unsigned long constructor\n"
           "---------------------------------\n";
   unsigned long ul[] = {0, 12345, 987654321UL,
                         1234567890UL, 0xffffffffUL };
   char buffer[20];
   ostrstream ostr( buffer, sizeof( buffer ) );
   for ( int i = 0; i < sizeof( ul ) / sizeof( *ul ); i++ )
      {
      ostr.seekp( 0 );
      ostr << ul[i] << ends;
      BigInt bi( ul[i] );
      outfile << bi << '\n';
      comparer( __LINE__, bi, buffer );
      }
   return outfile;
   }

ostream& default_constructor(ostream& outfile)
   {
   outfile << "\nTesting default constructor\n"
           "---------------------------\n";
   BigInt a, b, c;
   outfile << a << ' '<< b << ' '<< c << '\n';
   comparer( __LINE__, a, "0" );
   comparer( __LINE__, b, "0" );
   comparer( __LINE__, c, "0" );
   return outfile;
   }

BigInt pass_and_return_by_value( BigInt x )
   {
   BigInt y( x );
   return y;
   }

ostream& copy_constructor(ostream& outfile)
   {
   outfile << "\nTesting copy constructor\n"
           "------------------------\n";
   char s1[] = "987654321", s2[] = "0",
        s3[] = "123456789098765432101234567890";
   BigInt a( s1 ), b( s2 ), c( s3 );
   outfile << a << "  " << b << "  " << c << '\n';
   BigInt d( a ), e( b ), f( c );
   outfile << d << "  " << e << "  " << f << '\n';
   comparer( __LINE__, a, s1 );
   comparer( __LINE__, b, s2 );
   comparer( __LINE__, c, s3 );
   comparer( __LINE__, d, s1 );
   comparer( __LINE__, e, s2 );
   comparer( __LINE__, f, s3 );
   outfile << pass_and_return_by_value( d ) << "  ";
   outfile << pass_and_return_by_value( e ) << "  ";
   outfile << pass_and_return_by_value( f ) << "\n";
   comparer( __LINE__, d, s1 );
   comparer( __LINE__, e, s2 );
   comparer( __LINE__, f, s3 );
   return outfile;
   }

ostream& assignment_operator(ostream& outfile)
   {
   outfile << "\nTesting assignment operator\n"
           "---------------------------\n";
   char s1[] = "123456789", s2[] = "5",
        s3[] = "987654321012345678909876543210";
   BigInt a( s1 ), b( s2 ), c( s3 );
   BigInt d( "0" ),
          e( "11111222223333344444555556666677777888889999900000" ),
          f( "987654321" );

   outfile << a << "  " << b << "  " << c << '\n';
   d = a;
   e = b;
   f = c;
   outfile << d << "  " << e << "  " << f << '\n';
   comparer( __LINE__, a, s1 );
   comparer( __LINE__, b, s2 );
   comparer( __LINE__, c, s3 );
   comparer( __LINE__, d, s1 );
   comparer( __LINE__, e, s2 );
   comparer( __LINE__, f, s3 );
   for ( int i = 0; i < 3; i++ )
      {
      BigInt t;
      t = d; d = e; e = f; f = t;
      }
   outfile << d << "  " << e << "  " << f << '\n';
   comparer( __LINE__, d, s1 );
   comparer( __LINE__, e, s2 );
   comparer( __LINE__, f, s3 );
   // assignment to self
   BigInt *p1 = &d, *p2 = &e;
   d = *p1;  *p2 = e;
   BigInt &r1 = f, &r2 = f;
   r2 = r1;
   outfile << d << "  " << e << "  " << f << '\n';
   return outfile;
   }

main()
   {

   ofstream outfile ( "results.txt", ios::out );
   if ( ! outfile ) {
     cerr << "   Error, cannot open output data file 'results.txt' \n";
     return (2);
   }        // define and open output file - display error if failure



   int i;
   ostream&  ( *tester[] )(ostream& outfile) =
         {
         string_constructor
         , ulong_constructor
         , default_constructor
         , copy_constructor
         , assignment_operator
         };

   _CrtMemState sb1, sb2, sb3;
   _CrtMemCheckpoint (&sb1);
   for ( i = 0; i < sizeof( tester ) / sizeof( tester[0] ); i++ )
      {
      _CrtMemState s1, s2, s3;
      _CrtMemCheckpoint (&s1);
      tester[i](outfile);
      _CrtMemCheckpoint (&s2);
      if (_CrtMemDifference (&s3, &s1, &s2))
       _CrtMemDumpStatistics (&s3);
      }
   _CrtDumpMemoryLeaks ();
   _CrtMemCheckpoint (&sb2);
   if (!_CrtMemDifference (&sb3, &sb1, &sb2))
    outfile << endl << "Ok, no memory leaks" << endl;
   return 0;
   }
