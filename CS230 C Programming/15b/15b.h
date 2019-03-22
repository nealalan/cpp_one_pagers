
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXSTUDENTS 50
#define STUNAMELEN 21

struct STUREC {
        int id;
        char name[STUNAMELEN];
        double rawscore;
        double stanscore;
        char lettergrade;
};

int loaddata(STUREC* ptrrec);
double avg(STUREC* ptrrec, int amtstu);
double dev(STUREC* ptrrec, int amtstu, double avgscore);
void stuscore(STUREC* ptrrec, int amtstu, double avgscore, double standev);
void stugrade(STUREC* ptrrec, int amtstu);
void printreport(STUREC* ptrrec, int amtstu, double avgscore, double standev, char r);


int id_cmp(const void *p, const void *q);
int name_cmp(const void *p, const void *q);
int stanscore_cmp(const void *p, const void *q);