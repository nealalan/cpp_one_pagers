// Neal A. Dreher
// Apr 22, 1999
// final_exam_3925.cpp

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>      
#include "make_final_exam.h"

const questions = 30;

void main() {

	make_final_exam();

	ifstream inFile;
	char key[questions],  // answer key array
	char ch;   // gets char from file and redeclares it
	int n;     // number of takers of exam
	
	inFile.open("exam.txt");
	if (!inFile) { 
		cout << "ERROR READING FILE!"; 
	}
	// defines key to grade
	for (int x=0; x < questions; x++) {
		inFile.get(ch);
		key[x] = ch;
	}

	inFile >> n;
	inFile.ignore(100);

	for (int x; x < questions; x++) {
		inFile.get(ch);
		if (ch == key [x]) {
			correct++;
		}
	}




}