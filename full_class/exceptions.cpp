#include "DateTime.hpp"

void DateTime::CheckingDay(int day) {
	try {
		if (day > 31) {
			throw MyException("in month must be 31 or less days");
		} else if (day < 1) {
			throw MyException("in month mustn't be less then 1 day");
		}
		this->day = day;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DateTime::CheckingMonth(int month) {
	try {
		if (month > 12) {
			throw MyException("in year must be 12 or less month");
		} else if (month < 1) {
			throw MyException("in year mustn't be less then 1 month");
		}
		this->month = month;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DateTime::CheckingYear(int year) {
	try {
		if (year < 1) {
			throw MyException("year mustn't be less then 1");
		} else if (CheckingDate()) {
			throw MyException("date with this year aren't valid");
		}
		this->year = year;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DateTime::CheckingHours(int hours) {
	try {
		if (hours < 0) {
			throw MyException("hours mustn't be less then 0");
		} else if (hours > 23) {
			throw MyException("24th hour must be 0");
		}
		this->hours = hours;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DateTime::CheckingMinutes(int minutes) {
	try {
		if (minutes < 0) {
			throw MyException("minutes mustn't be less then 0");
		} else if (minutes > 59) {
			throw MyException("60th must be 0");
		}
		this->minutes = minutes;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}

void DateTime::CheckingSeconds(int seconds) {
	try {
		if (seconds < 0) {
			throw MyException("seconds mustn't be less then 0");
		} else if (seconds > 59) {
			throw MyException("60th seconds must be 0");
		}
		this->seconds = seconds;
	}
	catch (MyException &ex) {
		cerr << ex.what() << "\n";
	}
}
