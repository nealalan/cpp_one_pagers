//***************************************************************************************
// Neal A. Dreher         Apr 11, 2000
// 13a.h
//***************************************************************************************

#include <stdio.h>
#include <stdlib.h>

#define QUESTIONS 100
#define POSSIBLE_ANSWERS 6

void header();
int getanswerkey(char* ptranskey);
void getansstu(char* ptransstu, int ansamounts);
int calcstats(char* ptransstu, int* anscounts);
void prnresults(int* ans, char* ptranskey, int questions);
