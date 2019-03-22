//**************************************************************
// Neal A. Dreher         Mar. 21, 2000
// CMPSC230               Tues. 6:00
// Page 10.15             Problem 10D
//
// 10d.main.cpp
// 
// Input a file with ID numbers and numberic grades and calc the
// average and the letter grades received.
//***************************************************************

#include <stdio.h>
#define limit 200

int main() {

	unsigned long id[limit] = {0};
	unsigned int gradetotal = 0, average = 0, grade[limit] = {0};
	int scount = 0, pcount = 0;

	for (; scanf("%lu %u", &id[scount], &grade[scount]) == 2; gradetotal += grade[scount], scount++);

	average =  gradetotal / scount;  // findthe average

	printf("\nAVERAGE SCORE: %u", average);
	printf("\n\nSTUDENT ID      SCORE      GRADE\n");
		
	while (pcount < scount) {
		printf("\n%9lu        %3u        ", id[pcount], grade[pcount]); 
		if (grade[pcount] >= average + 20) putchar('A');
		else if (grade[pcount] < average + 20 && grade[pcount] >= average + 10) putchar('B');
		else if (grade[pcount] < average + 10 && grade[pcount] > average - 10) putchar('C');
		else if (grade[pcount] <= average - 10 && grade[pcount] > average - 20) putchar('D');
		else if (grade[pcount] <= average - 20) putchar('F');
		pcount++;
	}

	printf("\n\n");
	return 0;
}


