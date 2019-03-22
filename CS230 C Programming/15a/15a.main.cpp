//***************************************************************************************
// Neal A. Dreher         Apr 25, 2000
// CMPSC230               Tues. 6:00
// Page 15.30             Problem 15A
//
// 15a.main.cpp
//
//***************************************************************************************

#include "15a.h"

void main() {

	STUREC studentrecords[MAXSTUDENTS] = { 0 };
	int amtstu;
	double avgscore, standev;

	amtstu = loaddata(studentrecords);   // load in the student data from file
	avgscore = avg(studentrecords, amtstu);  // finger the grade average for class
	standev = dev(studentrecords, amtstu, avgscore);  // find the class stan dev and the student dev
	stuscore(studentrecords, amtstu, avgscore, standev);  // calcuate the standard deviation
	stugrade(studentrecords, amtstu);  // figure out and apply the letter grade to the students structure
	printreport(studentrecords, amtstu, avgscore, standev);

	return;
}
