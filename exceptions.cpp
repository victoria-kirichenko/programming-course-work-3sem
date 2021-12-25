#include "DataBase.hpp"

void Date::CheckingDay(int day) {
	try {
		if (dd > 31) {
			throw MyException("in month must be 31 or less days");
		} else if (day < 1) {
			throw MyException("in month mustn't be less then 1 day");
		}
		this->dd = day;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void Date::CheckingMonth(int month) {
	try {
		if (mm > 12) {
			throw MyException("in year must be 12 or less month");
		} else if (month < 1) {
			throw MyException("in year mustn't be less then 1 month");
		}
		this->mm = month;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void Date::CheckingYear(int year) {
	try {
		if (yy < 1) {
			throw MyException("year mustn't be less then 1");
		} else if (CheckingDate()) {
			throw MyException("date with this year aren't valid");
		}
		this->yy = year;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DataBase::CheckingDuration(int duration) {
	try {
		if (a_duration < 0) {
			throw MyException("hours mustn't be less then 0");
		}
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}
