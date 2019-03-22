//***************************************************************************************
// Neal A. Dreher         Nov 1, 2000
// CMPSC232               Wednesday 6:00
// Program 9             WinME, WinNT4, VC6
//
// 9.emp.h
//
//***************************************************************************************

#include "9.main.h"

#ifndef emp_h
#define emp_h


class Employee {

	protected:
		char* name;
		long idnum;
		Date hired;

	public:
		Employee();

		~Employee();

		istream& Input(istream& is);
		ostream& OuputToFile(ostream& os);
		int CompareDate(const Employee& e) const;
		long GetId();
		const char* GetName();
		Date GetHireDate();


};


#endif emp_h