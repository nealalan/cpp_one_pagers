//***************************************************************************************
// Neal A. Dreher         Nov 15, 2000
// CMPSC232               Wednesday 6:00
// Program 11             WinNT4, VC6
//
// 11.path.h    a Distance Class III
//
//***************************************************************************************

#ifndef PATHH
#define PATHH

#include "11.main.h"

class Path {

protected:

	Distance *path;
	int count;

public:

	Path();
	~Path();
	void AddPath(const Distance& d);
	void ShowPath();

};

#endif PATHH