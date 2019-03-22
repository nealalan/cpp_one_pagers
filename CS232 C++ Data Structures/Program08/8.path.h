//***************************************************************************************
// Neal A. Dreher         Oct 25, 2000
// CMPSC232               Wednesday 6:00
// Program 8              WinNT4, VC6
//
// 8.path.h    a Distance Class II
//
//***************************************************************************************

#ifndef PATHH
#define PATHH

#include "8.main.h"

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