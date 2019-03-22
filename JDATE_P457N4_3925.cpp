/* * * * * * * * * * * * * * * * * * * * * * * * * *
	Neal A. Dreher  *  25 MARCH 1999  * P457N4
	This program converts dates to a julian date number
	subtracts two dates and tells how many days are inbetween
	the dates.
 * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream.h>
#include <math.h>

void GetDates(double&);
void OutputDates(double, double);

// * * * * * * * * * * * * * * * * * * * * 

void main () {

	double date1 = 0;
	double date2 = 0;
	double date = 0;

	while (date1 == 0) {
		cout << endl << "* FIRST DATE *" << endl << endl;
		GetDates(date);
		date1 = date;
	}
	while (date2 == 0) {
		cout << endl << endl << "* SECOND DATE *" << endl << endl;
		GetDates(date);
		date2 = date;
	}

	OutputDates(date1, date2);

}

// * * * * * * * * * * * * * * * * * * * * * *

void GetDates (double& julianDay) {

	int month; 
	int day; 
	int year;
	long double intRes1; 
	long double intRes2; 
	long double intRes3;
	
	cout << "Please input a month (1-12): ";
	cin >> month;
	cout << endl;
	cout << "Please input a day (1-31): ";
	cin >> day;
	cout << endl;
	cout << "Please input a year in 4 digit format: ";
	cin >> year;

	if (month == 1 || month == 2) {
		year--;
		month = month + 12;
	}

	if (year < 1582) {
		intRes1 = 0;
	}
	else if (year == 1582 && month < 9) {
		intRes1 = 0;
	}
	else if (year == 1582 && month == 9 && day < 16) {
		intRes1 = 0;
	}
	else {
		intRes1 = (2 - (year / 100) + (year / 400));
	}

	intRes2 = int(365.25 * year);
	intRes3 = int(30.6001 * (month + 1));
	julianDay = intRes1 + intRes2 + intRes3 + day + 1720994.5;


}

// * * * * * * * * * * * * * * * * * * * * * * * *

void OutputDates(double date1, double date2) {

	int dateDifference;

	dateDifference = int(fabs(date1 - date2));

	cout << "The amount of days between the dates entered are " << dateDifference << " days." << endl;

}