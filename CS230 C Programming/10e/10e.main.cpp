//***************************************************************************************
// Neal A. Dreher         Mar. 21, 2000
// CMPSC230               Tues. 6:00
// Page 10.15             Problem 10E
//
// 10e.main.cpp
// 
// Input a file with id numbers and test scores, first line answer key, 
// and figure out the percentage grade and the class percentage.
//***************************************************************************************

#include <stdio.h>
#define MAXQUESTIONS 100

int main() {
	unsigned long id = 0, garbage = 0;
	int key[MAXQUESTIONS] = {0}, keyanswer = 0, input = 0, allanswers = 0, allanswerscorrect = 0;

	scanf("%lu", &garbage);                                      // get rid of the 0s that indicate key

	while((key[keyanswer] = getchar()) != '\n' ) keyanswer++;    // read in the answer key line

	printf(" STUDENT      PERCENT\n   ID         CORRECT\n\n");  // print the col headings
	
	// while still input in file and get id number
	while(scanf("%9lu", &id) != EOF) { 
		int correct = 0, answer = 0;

		while ((input = getchar()) != '\n') {       // while input on the same id
			if (input == key[answer]) correct++;			          
			allanswers++;
			answer++;	         //  keeps track of all the answers to find average
		}
		correct--;
		allanswers--;
		answer--;
		printf("%9lu     %6.2f\n", id, ((float)(correct) / (float)(answer)) * 100);
		allanswerscorrect += correct;
	}
	// prints the student average	
	printf("\nAVERAGE:      %6.2f\n", ((float)(allanswerscorrect) / (float)(allanswers)) * 100);

	return 0;
}
