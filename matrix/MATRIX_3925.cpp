//
//  Neal A, Dreher
//  08 May 1999
//  p835 n 6
//
//  http://nad.sta.sh/class_stuff/CS125/MATRIX/MATRIX_3925.cpp

#include <iostream.h>
#include <fstream.h>
#include "make_sparse.h"
#include <iomanip.h>
#include <stdio.h>

const arraySize = 50;
ifstream inFile;

IntIntFloat matrix[arraySize];

void CompressMatrix();
void PrintCompression();


void main() {

	//	make_sparse();
	CompressMatrix();
	PrintCompression();


}

void CompressMatrix() {

	int x = 1;
	int get;
	int row = 1;
	int col = 1;

	do {
	do {

		inFile >> get;
		get = matrix[x].element;
		col = matrix[x].col;
		row = matrix[x].row;
		col++;
		x++;

	} while(col <= 10);
	} while(row <= 10);

}

void PrintCompression() {




}
