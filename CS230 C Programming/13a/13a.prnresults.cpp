//***************************************************************************************
// Neal A. Dreher         Apr 11, 2000
// 13a.prmresults.cpp
//
// prints the header and
// prints the lines by question and letter choice
//***************************************************************************************
#include "13a.h"

void header() {
	// print out the top of the chart
	printf("                        ANALYSIS OF ANSWERS\n\n");
	printf("            ---------- NUMBER CHOOSING ANSWER ----------  PERCENT\n");
	printf("QUESTION     A       B      C       D      E     OMITTED  CORRECT\n\n");

}
// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  
void prnresults(int* ptrans, char* ptranskey, int questions) {

	int question = 0;
	float percentage = 0;
	
	while (question < questions) {
		// puts a * in for right answer, reset after each question
		char ast[6] = { ' ', ' ', ' ', ' ', ' ', ' ' };
		ast[*(ptranskey + question) - 65] = '*';
		// divide the value of the pointer in the anskey (sub 65 to convert from letter to proper 
		//  subscript) by all the answers given and mult by float to get a decimal to float format
		percentage = 100.00 * ptrans[*(ptranskey + question) - 65] / 
			(ptrans[0] + ptrans[1] + ptrans[2] + ptrans[3] + ptrans[4] + ptrans[5]);
		// print out all the info for that question
		printf("%5d%10d%c%7d%c%6d%c%7d%c%6d%c%8d%10.1lf%%\n",
			question++ + 1, ptrans[0], ast[0], ptrans[1], ast[1], ptrans[2], ast[2], 
			ptrans[3], ast[3], ptrans[4], ast[4], ptrans[5], percentage);
		// move to the next row of the 2d array
		ptrans += POSSIBLE_ANSWERS;
	}
	return;
}
