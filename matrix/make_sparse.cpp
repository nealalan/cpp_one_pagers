//
// make_sparse.cpp
//
// Create random data for use with lab 6 on p.835
// NOTE: Output file will be named "matrix.txt"
//       Matrix will always be 10 x 10
//
// author: Ken Serrine
//
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip.h>

void make_sparse()
{
	int i,j;
	float value;

	ofstream outfile("matrix.txt");

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);

	// seed the random number generator with the time so that it
	// will be different every time we run the program
	srand((unsigned)time(NULL));

	// generate a matrix of 100 values, mostly zero
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((rand() % 10) == 9)
				value = float(rand() % 100) / float(rand() % 100);
			else
				value = 0.0;
			
			outfile << setw(10) << setprecision(3) << value;
		}
		outfile << endl;
	}

	outfile.close();
}

