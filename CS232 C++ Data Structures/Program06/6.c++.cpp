//***************************************************************************************
// Neal A. Dreher         Oct 11, 2000
// CMPSC232               Wednesday 6:00
// Program 6              WinNT4, VC6
//
// 6.c++.cpp    a Fast File Copy Program
//
//***************************************************************************************

#include <iostream.h>
#include <fstream.h>
#include <stdio.h>

void main(int argc, char* argv[]) {

	if(argc != 3) {
		cerr << "syntax: Program6 [file1] [file2]\n";
		return;
	}

	// captures the size of the file
	long filesize;
	// size of the buffer to use in the program
	const unsigned long buffersize(4000000);

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

	return;
}