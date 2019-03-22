///************************************************************************************************
// Neal A. Dreher         Feb. 08, 2000
// CMPSC230               Tues. 6:00
// Page 6.3               Problem 6A
//
// This program inputs a number and mirror images it, then finds the difference in the two numbers
//*************************************************************************************************

#include <stdio.h>

int main() {

    long inNumber=0, inPrint=0, revNumber=0;
    int pulledNumber=0;            // used to build the revNumber

    printf("Enter an integer: "); scanf("%ld", &inNumber);   // get number
    inPrint = inNumber;            // saves the inNumber for same output

    // makes the number positive to use and remembers if it was negative or not
    if(inNumber < 0) inNumber *= -1;

    // mirror images the inNumber to revNumber
    do (revNumber = (revNumber + (inNumber % 10)) * 10); while ((inNumber /= 10) > 10);

    // fixes the problem with the last revNumber being 0
    revNumber += inNumber;

    // makes the revNumber - if the inNumber was neg
    if(inPrint < 0) revNumber *= -1;

    // prints the data output
    printf("\n%13ld\n-%12ld\n-------------\n%13ld\n\n", inPrint, revNumber, inPrint - revNumber);
 
    return 0;
}

/*
Enter an integer: 123456

       123456
-      654321
-------------
      -530865

Enter an integer: 2000000000

   2000000000
-           2
-------------
   1999999998

Enter an integer: -2468

        -2468
-       -8642
-------------
         6174

*/