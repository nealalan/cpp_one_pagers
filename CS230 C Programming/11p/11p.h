//***************************************************************************************
// Neal A. Dreher         Apr 4, 2000
// 11p.h
//***************************************************************************************

#include <stdio.h>
#include <string.h>

void set(char *s, int n);
void show(char *s, int n);
char *stringdelete(char *ptrs, int ofs, int count);
char *stringinsert(char *ptrs1, int ofs, char *ptrs2);