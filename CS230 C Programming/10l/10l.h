#include <stdio.h>
#include <stdlib.h>

#define LIMIT 20
#define BUFFERSIZE (4 * LIMIT)

int loaddata(int *ptrx, int limit);
void list(int *ptrbuffer, int buffersize);
void copy(int *ptry, int *ptrx, int count);
void rotate_right(int *ptrx, int count);
void rotate_left(int *ptrx, int count);
void reverse(int *ptrx, int count);