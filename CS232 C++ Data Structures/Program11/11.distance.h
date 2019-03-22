//***************************************************************************************
// Neal A. Dreher         Nov 15, 2000
// CMPSC232               Wednesday 6:00
// Program 11             WinNT4, VC6
//
// 11.distance.h    a Distance Class III
//
//***************************************************************************************

#ifndef DISTANCEH
#define DISTANCEH

#include "11.main.h"

const double meterstofeet(3.280833);
const double milestofeet(5208);
//const double milestoinches(milestofeet * 12);  // less accurate than meters
const double milestometers(1609);

class Distance {

protected:

	double mmdistance;

public:

	// used when setting all Distance() objects
	enum Type{Metric, English};
	// used to express how to Paint()
	enum ShowAs{Mm, Feet, Meter, Miles};

	// constructors & destructors
	Distance();
	Distance(Type standard, double mil);
	Distance(Type standard, long meters, long centimeters, double millimeters = 0);
	Distance(Type standard, long feet, double inches = 0);
	~Distance() {}

	// friends functions that do Metric <-> English conversions
	// really pointless unless doing object stuff 
	// easier to do w/ a table of conv * distance given
	friend double MtoE(const double mmdistance);
	friend double MtoE(const Distance& d);
	friend double EtoM(const double inches);
	friend double EtoM(Distance& d, const double inches);

	// used member functions
	double GetDistance(const Type standard) const;
	void SetDistance(const Type standard, double measure);
	void Paint(const ShowAs unit) const;

	friend istream& operator>>(istream& is, Distance& d);
	friend ostream& operator<<(ostream& os, const Distance &d);

	Distance operator+(const Distance &d) const;
	Distance operator+(const double add) const;
	friend Distance operator+(const double add, const Distance &d);
	Distance& operator=(const Distance &d);

	bool operator==(const Distance& d) const;
	bool operator!=(const Distance& d) const;
	bool operator<(const Distance& d) const;
	bool operator<=(const Distance& d) const;
	bool operator>(const Distance& d) const;
	bool operator>=(const Distance& d) const;

	Distance& operator++();
	Distance operator++(int);
	Distance& operator--();
	Distance operator--(int);



};

#endif DISTANCEH