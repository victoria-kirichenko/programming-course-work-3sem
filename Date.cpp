#include "DataBase.hpp"
#include <windows.h>

Date::Date()
{
	dd = 0;
	mm = 0;
	yy = 0;
}

Date::Date(const int& day, const int& month, const int& year)
{
	dd = day;
	mm = month;
	yy = year;
}

void Date::SetDate(const int& day, const int& month, const int& year)
{
	dd = day;
	mm = month;
	yy = year;
}

void Date::SetDay(int valueDay) {
	dd = valueDay;
}

void Date::SetMonth(int valueMonth) {
	mm = valueMonth;
}

void Date::SetYear(int valueYear) {
	yy = valueYear;
}

void Date::SetDateNow()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	dd = st.wDay;
	mm = st.wMonth;
	yy = st.wYear;
}

Date::~Date() {
	//delete[] data;
}

bool Date::isEmpty()
{
	if (dd == 0 && mm == 0 && yy == 0) return true;
	return false;
}


std::ostream& operator<< (std::ostream& out, const Date& t)
{
	out.write((char*)&t.dd, sizeof(int));
	out.write((char*)&t.mm, sizeof(int));
	out.write((char*)&t.yy, sizeof(int));
	return out;
}

std::istream& operator>> (std::istream& in, Date& t)
{
	in.read((char*)&t.dd, sizeof(int));
	in.read((char*)&t.mm, sizeof(int));
	in.read((char*)&t.yy, sizeof(int));
	return in;
}

bool Date::operator==(const Date& t)
{
	if (dd == t.dd && mm == t.mm && yy == t.yy) return true;
	return false;
}


bool Date::operator>(const Date& t)
{
	if (yy > t.yy) return true;
	else
	{
		if (yy == t.yy)
			if (mm > t.mm) return true;
			else
			{
				if (mm == t.mm && dd > t.dd) return true;
			}
	}
	return false;
}

bool Date::CheckingDate() { // валидность даты (1 - false, 0 - true)
	if (dd <= 0 || mm <= 0 || yy <= 0) return 1;
	else if (mm > 12) return 1;
	else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && (dd <= 30)) return 0;
	else if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && dd <= 31) return 0;
	else if (mm == 2) {
		if ((yy % 400 == 0 || yy % 100 != 0) && (yy % 4 == 0) && (dd<= 29)) return 0;
		else if ((yy % 4 != 0) && (dd <= 28)) return 0;
		else return 1;
	}
	else return 1;
}

//char* Date::ToString() {
//	return GetDDate();
//}

//char* Date::GetDDate() {
//	char* tmp;
//	if (tmp) {
//		delete[] tmp;
//	}
//	sprintf(data, "%02d.%02d.%04d", dd, mm, yy);
//	tmp = new char[11];
//	strcpy(tmp, data);
//	return data;
//}