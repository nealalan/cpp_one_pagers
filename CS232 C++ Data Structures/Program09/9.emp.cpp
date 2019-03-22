//***************************************************************************************
// Neal A. Dreher         Nov 1, 2000
// CMPSC232               Wednesday 6:00
// Program 9              Win 2000, VC 6
// 
// 9.emp.cpp
//***************************************************************************************

#include "9.main.h"


Employee::Employee(): idnum(0), hired("01/01/2400") { 

	name = new char[1];
	name[1] = '\n';

}


Employee::~Employee() {}

// syntax: emp.Input(infile);
istream& Employee::Input(istream& is) {
	is >> idnum;
	is.get(name, 20, '"');
	is >> hired;
	return is;
}

// syntax: emp.OutputToFile(outfile);
ostream& Employee::OuputToFile(ostream& os) {
	os.setf(ios::fixed, ios::floatfield);
	os.setf(ios::showpoint);

	os << setfill(0) << setprecision(9) << GetId() << "  " 
		<< "\"" << setprecision(20) << GetName() << "\"" << "  "
		<< GetHireDate() << "     " 
		<< (GetHireDate() - ReportDate()) / 365.25 << "\n";

	return os;
}

// syntax: if (emp.CompareDate(other_emp)) {}
int Employee::CompareDate(const Employee& e) const {
	if (hired == e.hired) return 0;
	return hired > e.hired ? 1 : -1;
}

// syntax: long id = emp.GetId();
long Employee::GetId() {
	return idnum;
}

// syntax: const char* name = emp.GetName();
const char* Employee::GetName() {
	return name;
}

// syntax: Date hiredate = emp.GetHireDate();
Date Employee::GetHireDate() {
	return hired;
}
