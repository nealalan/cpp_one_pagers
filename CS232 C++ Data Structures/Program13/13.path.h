//***************************************************************************************
// Neal A. Dreher         Dec 6, 2000
// CMPSC232               Wednesday 6:00
// Program 13             WinNT4, VC6
//
// 13.path.h    a Distance Class IIII
//
//***************************************************************************************

#ifndef PATHH
#define PATHH

#include "13.main.h"

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