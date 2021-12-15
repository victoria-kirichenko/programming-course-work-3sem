#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED
#include "DateTime.hpp"
using namespace std;

class DataBase {

public:
	DataBase();

	DataBase(const char* city, const int& citykey, const int& price, const char* telephone);

	DataBase(const char* city, const int& citykey, const int& price,
		const int& date_d, const int& date_m, const int& date_y,
		const int& time_h, const int& time_m, const int& time_s,
		const int& duration_h, const int& duration_m, const int& duration_s,
		const char* telephone,
		const int& payment_d, const int& payment_m, const int& payment_y);

	DataBase(const char* city, const int& citykey, const int& price,
		const int& date_d, const int& date_m, const int& date_y,
		const int& time_h, const int& time_m, const int& time_s,
		const int& duration_h, const int& duration_m, const int& duration_s,
		const char* telephone);

	~DataBase();
	void Print();
	void PrintPaid();
	void Paid(const int& payment_d, const int& payment_m, const int& payment_y);
	void PaidNow();
	bool isPaid() { return !a_payment.isEmpty(); };
	bool isEmpty();
	void RDate();
	void RDuration();
	int Price() { return a_price; };
	DateTime Date() { return a_date; };

	friend std::ostream& operator<< (std::ostream& out, const DataBase& t);
	friend std::istream& operator>> (std::istream& in, DataBase& t);
	DataBase& operator= (DataBase& t);

private:
	char* a_city;
	int a_citykey;
	int a_price;
	DateTime a_date;
	DateTime a_time;
	DateTime a_duration;
	char* a_telephone;
	DateTime a_payment;
};

#endif // DATABASE_HPP_INCLUDED