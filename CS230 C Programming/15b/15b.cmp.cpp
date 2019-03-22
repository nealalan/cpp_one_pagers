//***************************************************************************************
// Neal A. Dreher         Apr 25, 2000
// CMPSC230               Tues. 6:00
// Page 15.30             Problem 15B

//  these are the functions that pass wierd stuff onto the qsort() function
//   example:  qsort(studentrecords, amtstu, sizeof(studentrecords[0]), id_cmp);
//   syntax:   qsort(array void *, # items in array, size of array, compare function);

#include "15b.h"

// sorts id numbers (acts as doubles)
int id_cmp(const void *p, const void *q) {

	const STUREC *a = (STUREC*)p;
	const STUREC *b = (STUREC*)q;
	if (a->id > b->id) return 1;
	if (a->id < b->id) return -1;
	return 0; // if =
}

int name_cmp(const void *p, const void *q) {

	const STUREC *a = (STUREC*)p, *b = (STUREC*)q;
	return stricmp(a->name, b->name);
}

int stanscore_cmp(const void *p, const void *q) {

	const STUREC *a = (STUREC*)p;
	const STUREC *b = (STUREC*)q;
	if (a->stanscore > b->stanscore) return 1;
	if (a->stanscore < b->stanscore) return -1;
	return 0; // if =
}