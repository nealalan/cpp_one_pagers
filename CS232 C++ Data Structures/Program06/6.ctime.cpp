//***************************************************************************************
// Neal A. Dreher         Oct 11, 2000
// CMPSC232               Wednesday 6:00
// Program 6              WinNT4, VC6
//
// 6.ctime.cpp    a Fast File Copy Program
//
//***************************************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>  // for strcmp()
#include <time.h>  // for clock_t and clock()

void main(int argc, char* argv[]) {

	// set the time var's
	clock_t ts, te;

	// check for people that can't follow syntax
	if(argc != 3) {
		printf("syntax: Program6 [file1] [file2]\n");
		return;
	}

	// check for people that want to copy a file to itself, thus
	// creating a 0 byte file and losing the input file
	if(!strcmp(argv[1], argv[2])) {
		printf("ERROR! Can not copy one file onto itself!\n");
		return;
	}

	ts = clock();
	// create the input and output files and check for them to be there
	FILE *in = fopen( argv[1], "rb");
	if(!in) { printf("Error!  No Input File!"); return; }
	FILE *out = fopen( argv[2], "wb");	
	if(!out) { printf("Error creating output file!"); return; }

	// captures the size of the file
	long filesize;
	// size of the buffer to use in the program
	const unsigned long buffersize(4000000);

	// create the memory to put the file chunks in
	static char buffer[buffersize];

	// get the size of the is
	fseek(in, 0, SEEK_END);
	filesize = ftell(in);
	fseek(in, 0, SEEK_SET);

	// grab chunks of the file in the size of the buffer while
	// there is chunks bigger than the buffer and put them in the
	// new file the dec the filesize the size of the piece you 
	// copied over, to know whow much is left to copy
	while (filesize > buffersize) { 
		fread(buffer, buffersize,  1, in);
		fwrite(buffer, buffersize,  1, out);
		filesize -= buffersize;
	}

	// copy over the last of what's left in the file to copy over
	// to the new file
	fread(buffer, filesize,  1, in);
	fwrite(buffer, filesize,  1, out);

	// close the newly created files
	fclose(in);
	fclose(out);

	// do a pretty little line of text that tells what is being copied
	// to what
	printf("%s -> %s", argv[1], argv[2]);

	// to figure time of run
	te = clock();  
	printf("  Time to copy file: %7.3lf seconds\n", ((double)(te-ts))/CLOCKS_PER_SEC);

	return;
}