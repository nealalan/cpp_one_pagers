//***************************************************************
// Neal A. Dreher  
// 8b.*.cpp 8b.h
//***************************************************************
#include <stdio.h>

// function to find  max days in given month
int days_in_month(int inMonth, int inYear);

// function to find max days of month 2 based on year
bool isleap(int inYear);

// function to find tomorrow's day based on inDate
void tomorrow(int inMonth, int inDay, int inYear,
			  int *ptrtomMonth, int *ptrtomDay, int *ptrtomYear);

// function to find yesterday based on inDate
void yesterday(int inMonth, int inDay, int inYear,
			   int *ptryesMonth, int *ptryesDay, int *ptryesYear);
