#include "DateTime.hpp"

DateTime::DateTime() {
    day = 0, month = 0, year = 0, hours = -1, minutes = -1, seconds = -1;
}

DateTime::DateTime(int day_1, int month_1, int year_1, int hours_1, int minutes_1, int seconds_1) {
	day = day_1;
	month = month_1;
	year = year_1;
	hours = hours_1;
	minutes = minutes_1;
	seconds = seconds_1;
}

DateTime::DateTime(int day_1, int month_1, int year_1) {
	day = day_1;
	month = month_1;
	year = year_1;
}

// DateTime::DateTime(int hours_1, int minutes_1, int seconds_1) {
// 	hours = hours_1;
// 	minutes = minutes_1;
// 	seconds = seconds_1;
// }

DateTime::~DateTime() {
	delete[] date_time;
	delete[] data;
	delete[] time;
}

void DateTime::SetDate(const int& day_1, const int& month_1, const int& year_1) {
	day = day_1;
	month = month_1;
	year = year_1;
}

void DateTime::SetTime(const int& hours_1, const int& minutes_1, const int& seconds_1) {
	hours = hours_1;
	minutes = minutes_1;
	seconds = seconds_1;
}

void DateTime::SetDateNow() {
	SYSTEMTIME st;
	GetSystemTime(&st);
	day = st.wDay;
	month = st.wMonth;
	year = st.wYear;
}

void DateTime::SetTimeNow() {
	SYSTEMTIME st;
	GetSystemTime(&st);
	hours = st.wHour;
	minutes = st.wMinute;
	seconds = st.wSecond;
}

bool DateTime::isEmpty() {
	if ((day == 0 && month == 0 && year == 0) || (hours == -1 && minutes == -1 && seconds == -1)) return true;
	return false;
}

bool DateTime::CheckingDate() { // валидность даты (1 - false, 0 - true)
	if (day <= 0 || month <= 0 || year <= 0) return 1;
	else if (month > 12) return 1;
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day <= 30)) return 0;
	else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31) return 0;
	else if (month == 2) {
		if ((year % 400 == 0 || year % 100 != 0) && (year % 4 == 0) && (day <= 29)) return 0;
		else if ((year % 4 != 0) && (day <= 28)) return 0;
		else return 1;
	}
	else return 1;
}

char* DateTime::GetDateTime() {
	sprintf(date_time, "%02d.%02d.%04d %02d:%02d:%02d", day, month, year, hours, minutes, seconds);
	char *tmp = new char[20];
	strcpy(tmp, date_time);
	return tmp;
}

char* DateTime::ToString() {
	return GetDateTime();
}

