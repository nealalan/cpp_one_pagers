// Pgfm12Vb.CPP  Tests BigInt class >> ( extraction ) operator

#include <iostream.h>
#include <strstrea.h>
#include <string.h>
#include <stdlib.h>         // for exit()
#include <crtdbg.h>
#include "12.main.h"

// external variables used only by comparer() function
char oBuffer1[500], oBuffer2[500];
ostrstream ostr1( oBuffer1, sizeof( oBuffer1 ) );
ostrstream ostr2( oBuffer2, sizeof( oBuffer2 ) );

// external variables used only by extraction_operator() function
char iBuffer[1000];
istrstream istr( iBuffer, sizeof( iBuffer ) );

int comparer( const BigInt& bi1, char op, const BigInt& bi2,
             const char* sbi1, const char* sop, const char *sbi2,
             const char* inStr, ostream& outfile)
   {

   ostr1.seekp( 0 );
   ostr1 << bi1 << ends;
   ostr2.seekp( 0 );
   ostr2 << bi2 << ends;
   if ( bi1.length() !=(int) strlen( sbi1 ) ||
       bi2.length() != (int) strlen( sbi2 ) ||
       strcmp( oBuffer1, sbi1 ) != 0 ||
       strcmp( oBuffer2, sbi2 ) != 0 ||
       op != sop[0] )
      {
      outfile << "\a\n*** ERROR***\n\n"
              << "INPUT WAS\n---------\n" << inStr << "\n"
              << "FIRST BigInt\n------------\n"
              << "length() returned " << bi1.length()
              << "; should be " << strlen( sbi1 ) << "\n"
              << "Contents:  *" << bi1 << "*\n"
              << "Should be: *" << sbi1 << "*\n\n"
              << "SECOND BigInt\n------------\n"
              << "length() returned " << bi2.length()
              << "; should be " << strlen( sbi2 ) << "\n"
              << "Contents:  *" << bi2 << "*\n"
              << "Should be: *" << sbi2 << "*\n\n"
              << "OPERATOR\n--------\nContents: " << op
              << "  Should be: " << sop << '\n';
      exit( 1 );
      }
   return 1;
   }

ostream& extraction_operator(ostream& outfile)
   {
   outfile << "Testing extraction operator\n"
           << "---------------------------\n";

   char *num[] = { "12345", "6", "0",
                   "34567890987654321012345678909876543210" };
   int nNum = sizeof( num ) / sizeof( *num );
   char *numPad[] = { "", "   ", "  \n", /* "   00000" */ };
   int nNumPad = sizeof( numPad ) / sizeof( *numPad );
   char *opPad[] = { "     ", "", "\n"};
   int nOpPad = sizeof( opPad ) / sizeof( *opPad );
   char *op[] = { "@", "#", "$" };
   int i, j, k, l, m, n = 0, nOp = sizeof( op ) / sizeof( *op );

   BigInt x, y;
   char c;

   for ( i = 0; i < nNumPad; i++ )
    for ( j = 0; j < nNum; j++ )
     for ( k = 0; k < nOpPad; k++ )
      for ( l = 0; l < nNumPad; l++ )
       for ( m = 0; m < nNum; m++ )
          {
          strcpy( iBuffer, numPad[i] );
          strcat( iBuffer, num[j] );
          strcat( iBuffer, opPad[k] );
          strcat( iBuffer, op[n] );
          strcat( iBuffer, numPad[l] );
          strcat( iBuffer, num[m] );
          strcat( iBuffer, "\n" );
          istr.seekg( 0 );
          istr >> x >> c >> y;
          comparer( x, c, y, num[j], op[n], num[m], iBuffer, outfile);
          if ( i == 0 && k == 1 && l == 0 )
             outfile << x << ' ' << c << ' ' << y << '\n';
          if ( ++n >= nOp ) n = 0;
          }
   return outfile;
   }

ostream& test_eof(ostream& outfile)
   {
   BigInt x("999");
   istrstream is("  \n");
   outfile << "\nTesting extraction operator recognition of eof\n"
           << "----------------------------------------------\n";
   is >> x;
   if ( is )
      {
      outfile << "\aError: operator>> did not recognize end of file\n";
      outfile << "x = " << x << endl;
      outfile << "is.eof() = " << is.eof()
              << "  is.fail() = " << is.fail()
              << "  is.good() = " << is.good() << endl;
      exit( 1 );
      }
   else
      outfile << "Ok\n";
   return outfile;
   }


main()
   {

   ofstream outfile ( "results.txt", ios::out );
   if ( ! outfile ) {
     cerr << "   Error, cannot open output data file 'results.txt' \n";
     return (2);
   }        // define and open output file - display error if failure

   outfile << "      Larry Buchanan   CMPSC 232   Section Q   Program 12b\n"
           << "            VC6  Win98  console app   BigInt Class I\n\n";

   int i;
   _CrtMemState sb1, sb2, sb3;
   _CrtMemCheckpoint (&sb1);

   ostream& ( *tester[] )(ostream& outfile) =
         {
         extraction_operator,
         test_eof
         };

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
