//***************************************************************************************
// Neal A. Dreher         Nov 15, 2000
// CMPSC232               Wednesday 6:00
// Program 11              WinNT4, VC6
//
// 11.distance.type.cpp    a Distance Class III
//
//***************************************************************************************

#include "11.main.h"

// friend functions

// this takes a double millimeterdistance and returns the amount of inches 
double MtoE(const double mmd) { return ((mmd / 1000) * meterstofeet * 12); }

// this takes a reference to a Distance object and returns double inches
double MtoE(const Distance& d) { return ((d.mmdistance / 1000) * meterstofeet * 12); }

// this takes double inches and returns double millimeters
double EtoM(const double inches) { return ((inches / 12) / meterstofeet) * 1000; }

// this is passed a reference to a Distance object and double inches
// it returns double millimeters and sets the d.mmdistance to the same double mm
double EtoM(Distance& d, const double inches) { return d.mmdistance = EtoM(inches); }
