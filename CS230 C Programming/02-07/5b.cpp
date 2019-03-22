///************************************************************************************************
// Neal A. Dreher         Feb. 08, 2000
// CMPSC230               Tues. 6:00
// Page 5.4               Problem 5B
//
// Write a program to input and display a sales file; at the end of file, print the high sales and 
// second high sales amount and the number of people who sold that amount.  Each line in the file 
// contains a 4 digit ID number and a sales amount (!-).  Print the results.  Test w/ 5A.*.
//*************************************************************************************************

#include <stdio.h>

int main() {

        double sales = 0;                         //used to prn the sales from file
        int id;                                   //used to prn the id from file 
        bool hsp = false, hsp2 = false;           //used to determine if counter needs ++
        double highSales = 0, highSales2 = 0;     //user to remember high sales figs
        int highSalesPpl = 0, highSalesPpl2 = 0;  //keeps counter per high sales
        
        printf("\n ID         SALES\n");

        while(scanf("%d %lf", &id, &sales) == 2) {  // continue to get data for checking
                printf("\n%d     $%8.2lf", id, sales);  // print the col headers
                
                if (sales > highSales) {                // found a new high sales figure
                        highSales2 = highSales;             // drop the high to 2nd high
                        highSales = sales;                  // create the new high found
                        highSalesPpl2 = highSalesPpl;       // xfer the amount of 2nd sales
                        highSalesPpl = 0;                   // reset the high sales times
                        hsp = true;
                }
                if (sales == highSales || hsp) {        // if the new fig is same as high one
                        highSalesPpl++;                     //  increase the count
                        hsp = false;
                }
                if (sales > highSales2 && sales < highSales) {
                        highSales2 = sales;                 // if found a new 2nd but wasn't high
                        highSalesPpl2 = 0;                  // reset the 2nd high and define it
                        hsp2 = true;
                }
                if (sales == highSales2 || hsp2) {      // found a new 2nd high so count it!
                        highSalesPpl2++; 
                        hsp2 = false;
                }
        }

        // print the high/2nd high sales figures
        printf("\n\nHigh sales amount is $%.2lf sold by %d person/people.", highSales, highSalesPpl);
        printf("\nSecond high sales amount is $%.2lf sold by %d person/people.", highSales2, highSalesPpl2);

        return 0;
}

/*  using 5b < 5b.1

 ID         SALES

1000     $ 1000.00
1111     $  500.00
1500     $ 1000.00
2000     $  900.00
2222     $ 2000.00
2500     $ 2000.00
3000     $ 1500.00
3333     $ 2000.00
3500     $ 2000.00
4000     $  600.00
4444     $ 2500.00
4500     $ 2000.00
5000     $ 2500.00
5500     $ 2222.00
5555     $ 2000.00
6000     $ 1999.00
6500     $ 2222.00
6666     $ 2500.00
7000     $  100.00
7500     $ 2100.00
7777     $ 2150.00

High sales amount is $2500.00 sold by 3 person/people.
Second high sales amount is $2222.00 sold by 2 person/people.

  using 5b < 5b.2

 ID         SALES

1000     $ 1000.00
1111     $  500.00
1500     $ 1000.00
2000     $  900.00
2222     $ 2000.00
2500     $ 2000.00
3000     $ 1500.00
3333     $ 2000.00
3500     $ 2000.00
4000     $  600.00
4444     $ 2500.00
4500     $ 2000.00
5000     $ 2500.00
5500     $ 2222.00
5555     $ 2000.00
6000     $ 1999.00
6500     $ 2222.00
6666     $ 2500.00
7000     $  100.00
7500     $ 3000.00
7777     $ 2150.00

High sales amount is $3000.00 sold by 1 person/people.
Second high sales amount is $2500.00 sold by 3 person/people.

   using 5b < 5b.3

 ID         SALES

1000     $ 1000.00
1111     $ 1000.00
1500     $ 1000.00
2000     $ 1200.00
2222     $ 1200.00
2500     $ 1500.00
3000     $ 1500.00
3333     $ 1500.00
3500     $ 1000.00
4000     $ 1500.00
4444     $ 1500.00
4500     $ 2000.00
5000     $ 4000.00
5500     $ 2000.00
5555     $ 4000.00
6000     $ 2000.00
6500     $ 2000.00
6666     $ 2000.00
7000     $  100.00
7500     $ 3000.00
7777     $ 4000.00

High sales amount is $4000.00 sold by 3 person/people.
Second high sales amount is $3000.00 sold by 1 person/people.

*/