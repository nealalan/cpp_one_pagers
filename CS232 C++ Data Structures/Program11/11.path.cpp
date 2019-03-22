//***************************************************************************************
// Neal A. Dreher         Nov 15, 2000
// CMPSC232               Wednesday 6:00
// Program 11             WinNT4, VC6
//
// 11.path.cpp    a Distance Class II
//
//***************************************************************************************

#include "11.main.h"

Path::Path(): path(NULL), count(0) {
}
		
Path::~Path() {

	if(path) delete [] path;
}

// allocates a new array of count+1 Distance objects 
// put the old Distance objects into the new array and then delete 
// the memory for the old array - then put the passed Distance 
// object in the array
void Path::AddPath(const Distance& d) {

	Distance* temp = new Distance[count+1];

	for(int i = 0; i < count; i++) {
		temp[i] = path[i];
	}

	temp[count] = d;
	if(path) delete [] path;

	path = temp;

	count++;
	return;
}


// output the Distances stored in the Path object
void Path::ShowPath() {

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);

	cout << "Tracing the path of " << count << " segments:\n";

	for(int current = 0; current < count; current++) {

		cout << "  Segment " << current + 1 << ": " << setprecision(2) << path[current].GetDistance(Distance::Metric) << " mm\n";
	}

	return;
}
