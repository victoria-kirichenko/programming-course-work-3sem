#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

class MyException : public exception
{
public:
	MyException(const char* msg) : message(msg) {};
	const char* what() {
		return message;
	}
private:
	const char* message;
};

class Date
{
protected:
	int dd, mm, yy;

public:

	Date();

	Date(const int& day, const int& month, const int& year);

	int GetDay() { return dd; };
	int GetMonth() { return mm; };
	int GetYear() { return yy; };

	void SetDay(int valueDay);
	void SetMonth(int valueMonth);
	void SetYear(int valueYear);
	void SetDate(const int& day, const int& month, const int& year);
	void SetDateNow();

	bool isEmpty();

	bool operator==(const Date& t);
	bool operator>(const Date& t);

	friend std::ostream& operator<< (std::ostream& out, const Date& t);
	friend std::istream& operator>> (std::istream& in, Date& t);

	~Date();
};

class DataBase
{
private:
	char* a_city = new char[100];
	int a_citykey;
	int a_price;
	int a_tarif;
	Date a_date;
	int a_duration;
	char* a_telephone = new char[100];
	Date a_payment;
public:
	DataBase();

	DataBase(const char* city, const int& citykey,
		const int& date_d, const int& date_m, const int& date_y,
		const int& duration, const char* telephone,
		const int& payment_d, const int& payment_m, const int& payment_y);

	DataBase(const char* city, const int& citykey,
		const int& date_d, const int& date_m, const int& date_y,
		const int& duration, const char* telephone);

	void SetCity(const char* newCity);
	void SetCityKey(int newKey);
	void SetDuration();
	void SetTelephone(const char* newTel);
	void SetPayDay(int newDay);
	void SetPayMonth(int newMonth);
	void SetPayYear(int newYear);
	void SetDDay(int newDay);
	void SetMMonth(int newMonth);
	void SetYYear(int newYear);
	void SetPayDateNow();

	void ChooseTarif();
	void Paid(const int& payment_d, const int& payment_m, const int& payment_y);
	void PaidNow();

	void Print();
	void PrintNotPaid();

	void RDate();
	void RDuration() {
		a_duration = rand() % 200;
	};

	Date Date() { return a_date; };
	bool isPaid() { return !a_payment.isEmpty(); };
	bool isEmpty();
	bool CheckingDate();

	void SetPrice() {
		a_price = a_tarif * a_duration;
	};

	int GetPrice() {
		return a_price;
	}

	DataBase& operator= (DataBase& t);
	friend std::ostream& operator<< (std::ostream& out, const DataBase& t);
	friend std::istream& operator>> (std::istream& in, DataBase& t);

	~DataBase();
};