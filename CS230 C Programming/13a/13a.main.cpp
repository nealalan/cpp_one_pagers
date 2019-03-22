//***************************************************************************************
// Neal A. Dreher         Apr 11, 2000
// CMPSC230               Tues. 6:00
// Page 13.15             Problem 13A
//
// 13a.main.cpp
//
//***************************************************************************************

#include "13a.h"

void main() {

	char anskey[QUESTIONS] = { 0 };
	char ansstu[QUESTIONS] = { 0 };
	int anscounts[QUESTIONS][POSSIBLE_ANSWERS] = { { 0 } };
	int ansamounts, questions;

	header();
	// reads in the answer key and returns how many questions
	ansamounts = getanswerkey(anskey);
	// reads in the answers and sent the student ID to crap
	while(scanf (" ") != EOF) {
		getansstu(ansstu, ansamounts);
		// keeps a tally on the class
		questions = calcstats(ansstu, anscounts[0]);
	}
	prnresults(anscounts[0], anskey, questions);
}