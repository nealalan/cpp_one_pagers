//***************************************************************************************
// Neal A. Dreher         Apr 25, 2000
// CMPSC230               Tues. 6:00
// Page 15.30             Problem 15B
//
// 15b.main.cpp
//
//***************************************************************************************

#include "15b.h"

void main(int argc, char *argv[]) {

        STUREC studentrecords[MAXSTUDENTS] = { 0 };
        int amtstu;
        double avgscore, standev;
		char t = ' ', r = ' ';

        amtstu = loaddata(studentrecords);   // load in the student data from file
        avgscore = avg(studentrecords, amtstu);  // finger the grade average for class
        standev = dev(studentrecords, amtstu, avgscore);  // find the class stan dev and the student dev
        stuscore(studentrecords, amtstu, avgscore, standev);  // calcuate the standard deviation
        stugrade(studentrecords, amtstu);  // figure out and apply the letter grade to the students structure

		if(argc > 1) {  
			t = toupper(argv[1][0]);  // something is there, make it uppercase to read easier
			if(argv[1][1] != 0)   // something else is there too so there must be 'r' (reverse) somewhere
				r = toupper(argv[1][1]);  // and there is no space so appears as one input
		}
		if(argc > 2) r = toupper(argv[2][0]); // something else is there but as a seperate item with a space in ptr++
		if(t == 'R') {  t = r;  r = 'R'; }  // since the r is listed first and we want it always the same, make it last
		if (t == 'I') qsort(studentrecords, amtstu, sizeof(studentrecords[0]), id_cmp);
		else if (t == 'N') qsort(studentrecords, amtstu, sizeof(studentrecords[0]), name_cmp);
		else if (t == 'S') qsort(studentrecords, amtstu, sizeof(studentrecords[0]), stanscore_cmp);
		
		printreport(studentrecords, amtstu, avgscore, standev, r);
        
		return;
}
