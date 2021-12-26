#include "DataBase.h"
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
	;
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
