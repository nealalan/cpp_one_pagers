/*	Neal A. Dreher
	17 Feb 1999
	P319 N3
*/

#include <iostream.h>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void Title ();				// Clean up the main() a bit
int Min2Sec (int, int);		// Converts minutes into seconds
int secConverted;			// sends sec from Min2Sec to main()
bool quitMusic;				// To continue loop
int loopNumber;				// To show piece number
int inMinutes, inSeconds;	// duh
int totMinutes, totSeconds;	// duh
int totalSeconds;			// Total seconds so far till maxSec
const maxSeconds = 4200;	// 70 minutes of music - STOP!

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

main () {

	quitMusic = false;
	loopNumber = 0;
	Title ();

	while (quitMusic == false) {
		
		loopNumber = loopNumber + 1;

		cout << "Input length of piece " << loopNumber << ": "; 
		cin >> inMinutes >> inSeconds;
		
		Min2Sec (inMinutes, inSeconds);
		totSeconds = totSeconds + secConverted;

		if (inMinutes == 0 && inSeconds == 0) {
			quitMusic = true;
			cout << endl;
		}
		if (totSeconds == maxSeconds) {
			quitMusic = true;
			cout << endl << "STOP - you have reached 70 minutes!" << endl << endl;
		}
		if (totSeconds > maxSeconds) {
			quitMusic = true;
			totSeconds = totSeconds - secConverted;
			cout << endl << "Piece " << loopNumber << " is too long." << endl << endl;
		}

	}  // end while loop

	totMinutes = totSeconds / 60;
	totSeconds = totSeconds % 60; 	

	cout << "The total number of minutes and seconds for the CD is " << totMinutes << " minutes " << totSeconds << " seconds." << endl << endl;

	return 0;

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

int Min2Sec (int inMinutes, int inSeconds) {

	secConverted = (inMinutes * 60) + inSeconds;
	return secConverted;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void Title () {

	cout << endl << "THE CD-RIGHTER TRACKER FITTER" << endl << endl;
	cout << "  Tired of making all those CD's that end up not having" << endl;
	cout << "  enough space on them for every song that you want to " << endl;
	cout << "  fit.  Well... use my program to make them fit.       " << endl;
	cout << "  Note : assuming the CD is 70 minutes." << endl;
	cout << endl;
	cout << "Please input track lengths in MM SS like 06 32 (6min 32sec)." << endl;
	cout << "To quit early input 00 00" << endl << endl;
}