//***************************************************************************************
// Neal A. Dreher         Oct 11, 2000
// CMPSC232               Wednesday 6:00
// Program 6              WinNT4, VC6
//
// 6.c++time.cpp    a Fast File Copy Program
//
//  Syntax: Program6 [infile] [outfile]
//
//  Output: infile -> outfile  Time to copy file #.### seconds!
//***************************************************************************************

#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>  // for strcmp()
#include <time.h>    // for clock_t and clock()

void main(int argc, char* argv[]) {

	// set the time var's
	clock_t ts, te;

	// check for people that can't follow syntax
	if(argc != 3) {
		cerr << "syntax: Program6 [file1] [file2]\n";
		return;
	}
	// check for people that want to copy a file to itself, thus
	// creating a 0 byte file and losing the input file
	if(!strcmp(argv[1], argv[2])) {
		cerr << "ERROR! Can not copy one file onto itself!\n";
		return;
	}

	ts = clock();
	// captures the size of the file
	long filesize;
	// size of the buffer to use in the program
	const unsigned long buffersize(8000000);

	// create the memory to put the file chunks in
	//	static char buffer[buffersize];
	char *buffer;
	buffer = new char [buffersize];

	// create the input and output files and check for them to be there
	ifstream is(argv[1], ios::in | ios::nocreate | ios::binary);
	if(!is) { cerr << "Error!  No Input File!" << endl; return; }
	ofstream os(argv[2], ios::out | ios::binary);
	if(!os) { cerr << "Error creating output file!" << endl; return; }

	// get the size of the is
	is.seekg (0, ios::end );
	filesize = is.tellg();
	is.seekg (0, ios::beg);

	// grab chunks of the file in the size of the buffer while
	// there is chunks bigger than the buffer and put them in the
	// new file the dec the filesize the size of the piece you 
	// copied over, to know whow much is left to copy
	while(filesize > buffersize) {
		is.read(buffer, buffersize);
		os.write(buffer, buffersize);
		filesize -= buffersize;
	}

	// copy over the last of what's left in the file to copy over
	// to the new file
	is.read  (buffer,filesize );
	os.write (buffer,filesize );
 
	// close the newly created files
	os.close();
	is.close();

	// do a pretty little line of text that tells what is being copied
	// to what
	cout << argv[1] << " -> " << argv[2];

	// to figure time of run
	te = clock();  
	cout << "  Time to copy file " << ((double)(te-ts))/CLOCKS_PER_SEC << " seconds! " << endl;

	return;
}