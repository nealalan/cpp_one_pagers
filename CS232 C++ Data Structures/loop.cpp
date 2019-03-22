#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


void main(int *argc, char* argv[]) {

	FILE *out = fopen("o.bin", "wb");

	clock_t s,e;

	int dog = 0;

	cout << "Enter size of file wanted in meg: ";
	cin >> dog;
	cout << endl << endl;

	char* array;
	array = new char [1000000];

	s = clock();

		for(int at=0; at < dog; at++) fwrite(array,1000000,1,out);

	fclose(out);

	e = clock();

	cout << "File o.bin wrote " << dog << "MB in " << (e - s) / 600 << " seconds.\n\n";

	return;
}
