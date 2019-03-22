//***************************************************************************************
// Neal A. Dreher         Apr 4, 2000
// 1lp.stringdelete.cpp
//***************************************************************************************

#include "11p.h"

char *stringdelete(char *ptrs, int ofs, int count) {

	// error check for idiots that would put in 90 for the count and cause the else to bring in core 
	// garbage and give the wrong, bad looking output
	if (count > (int)strlen(ptrs)) {
		count = 0;
		*(ptrs + ofs) = 0;
	}
	else for(char *ptreditbegin = ptrs + ofs, *ptrhere = ptrs + ofs; 
			ptrhere < ptrs + strlen(ptrs) && ptrhere + count - 1 != 0; *ptrhere++ = *(ptrhere + count));

return ptrs;

}
