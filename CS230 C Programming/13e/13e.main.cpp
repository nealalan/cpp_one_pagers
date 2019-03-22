//***************************************************************************************
// Neal A. Dreher         Apr 11, 2000
// CMPSC230               Tues. 6:00
// Page 13.15             Problem 13E
//
// 13e.main.cpp
//
//***************************************************************************************

#include "13e.h"


void main() {

	char word[wordlen];
	char words[1000][wordlen];
	int count = 0;

	while(getword(word, wordlen) != EOF) {

		search(words, word, count);

		

