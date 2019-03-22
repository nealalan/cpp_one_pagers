//***************************************************************
// Neal A. Dreher  
// 8a.*.cpp 8a.h
//
// This file contains the functions that determine how many days
// are in each month to know yesterday if inDay == 1 or to find
// out if tomorrows date exists in the inMonth or in inMonth++;
//***************************************************************
#include "8a.h"

//***************************************************************
//  check to see if this is a leap year to know exactly the days
//  in feb according to the year
bool isleap(int inYear) {
        if (((0 == inYear % 4) && (0 != inYear % 100)) || 
                (0 == inYear % 400)) return true;
        else return false;
}

//***************************************************************
int days_in_month(int inMonth, int inYear) {

        int days;
        switch(inMonth) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        days=31;
                        break;
                case 4: case 6: case 9: case 11:
                        days=30;
                        break;
                case 2:
                        if (isleap(inYear)) days=29;
                        else days=28;
                        break;
        }
        return days;
        
}

