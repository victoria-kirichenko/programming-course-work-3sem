#ifndef DATETIME_HPP_INCLUDED
#define DATETIME_HPP_INCLUDED
#include <cstring>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <cstdlib>
using namespace std;

class DateTime {

public:

	DateTime();

	DateTime(int day_1, int month_1, int year_1, int hours_1, int minutes_1, int seconds_1);

	DateTime(int day_1, int month_1, int year_1);

	// DateTime(int hours_1, int minutes_1, int seconds_1);

	int GetDay() { return day; };
	int GetMonth() { return month; };
	int GetYear() { return year; };
	int GetHours() { return hours; };
	int GetMinutes() { return minutes; };
	int GetSeconds() { return seconds; };

	bool CheckingDate();
	char* GetDateTime();
	char* ToString();
	bool isEmpty();

	void CheckingDay(int day);
	void CheckingMonth(int month);
	void CheckingYear(int year);
	void CheckingHours(int hours);
	void CheckingMinutes(int minutes);
	void CheckingSeconds(int seconds);

	void SetDate(const int& day_1, const int& month_1, const int& year_1);
	void SetTime(const int& hours_1, const int& minutes_1, const int& seconds_1);
	void SetDateNow();
	void SetTimeNow();

	//DateTime operator= (const DateTime date);
    //operator char*();
	bool operator==(const DateTime& date);
	bool operator>(const DateTime& date);

	friend std::ofstream& operator<< (std::ofstream& os, DateTime& date);
    friend std::ifstream& operator>> (std::ifstream& is, DateTime& date);

	~DateTime();

protected:
	int day, month, year, hours, minutes, seconds;
	char* date_time = new char[20]; // посмотрим
	char* data = new char[11];
	char* time = new char[20];
};

class MyException : public exception {
	public :
		MyException(const char *msg) : message(msg) {};
		const char *what() {
			return message;
		}
	private:
		const char *message;
};

#endif // DATETIME_HPP_INCLUDED 

void SetDateNow();