// Neal A. Dreher
// p457n3	
// Mar 25, 1999
//
// Input GetInfo() vars and guess how close you can get to a target
//
// http://nad.sta.sh/class_stuff/CS125/TARGET_P457N3_3925.cpp


#include <iostream.h>
#include <math.h>
#include <iomanip.h>

// - - - - - - - - - - - - - - - - - - - - - - - - - 

void GetInfo(float&, float&, float&);
void Deg2Rad(float, float&);
void Check(float, float, bool&);

// - - - - - - - - - - - - - - - - - - - - - - - - - 

void main() {

	int tries = 0;
	float targetDistance, launchAngleDeg, launchAngleRad, objectVelocity, landing;
	bool result = false;

	while (result == false) {
		tries++;
		GetInfo(targetDistance, launchAngleDeg, objectVelocity);
		// make user deg input into radians
		Deg2Rad(launchAngleDeg, launchAngleRad); 
		// calc landing point of projectile
		landing = ((objectVelocity * objectVelocity) * sin(2.00 * launchAngleRad) / 32.20);
		// calc difference in target and landing
		Check(landing, targetDistance, result);		
		// figure tries and if not guessed end
		// if guessed on 5th try on not to 5th try, skip
		if (result != true && tries == 5) { 
			result = true;
			cout << "You are out of tries.  Sorry!" << endl;
		}

	}

}

// - - - - - - - - - - - - - - - - - - - - - - - - - 

void GetInfo(float& targetDistance, float& launchAngle, float& objectVelocity) {

	cout << endl << "Please input the distance to the target in feet. ";
	cin >> targetDistance;
	cout << endl << "Please input the angle you want to launch the projectile. ";
	cin >> launchAngle;
	cout << endl << "Please input the velocity of the object launched. ";
	cin >> objectVelocity;
	cout << endl;

}

// - - - - - - - - - - - - - - - - - - - - - - - - - 

void Deg2Rad(float deg, float& rad) {

	rad = (deg * 3.14159265) / 180.00;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - 

void Check(float landing, float targetDistance, bool& result) {		

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);

	float difference;

	difference = fabs(targetDistance - landing);
	if (difference <= .0001) {
		cout << "You were off by " << setprecision(4) << ((180 * difference) / 3.14159265) << " degrees." << endl;
		cout << "HIT!!!  GREAT JOB!" << endl;
		result = true;
	}
	else {
		cout << "You were off by " << setprecision(40) << ((180 * difference) / 3.14159265) << " degrees." << endl;
		cout << "Try Again!" << endl;
	}

}