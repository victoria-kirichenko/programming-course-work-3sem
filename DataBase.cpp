#include "DataBase.hpp"
#include <cstring>

DataBase::DataBase()
{
	a_city[0] = '\0';
	a_telephone[0] = '\0';
	a_citykey = -1;
	a_price = -1;
	a_duration = 0;
	a_tarif = 0;
}

DataBase::~DataBase()
{
	delete[] a_city;
	delete[] a_telephone;
}

DataBase::DataBase(const char* city, const int& citykey,
	const int& date_d, const int& date_m, const int& date_y,
	const int& duration, const char* telephone,
	const int& payment_d, const int& payment_m, const int& payment_y)
{
	//if (a_city) {
	//	delete[] a_city;
	//}
	a_city = new char[strlen(city) + 1];
	strcpy(a_city, city);

	a_citykey = citykey;
	a_duration = duration;
	a_tarif = 0;
	a_price = -1;
	a_date.SetDate(date_d, date_m, date_y);
	//if (a_telephone) {
	//	delete[] a_telephone;
	//}
	a_telephone = new char[strlen(telephone) + 1];
	strcpy(a_telephone, telephone);
	a_payment.SetDate(payment_d, payment_m, payment_y);
}

DataBase::DataBase(const char* city, const int& citykey,
	const int& date_d, const int& date_m, const int& date_y,
	const int& duration, const char* telephone)
{
	if (a_city) {
		delete[] a_city;
	}
	a_city = new char[strlen(city) + 1];
	strcpy(a_city, city);
	a_citykey = citykey;
	a_duration = duration;
	a_tarif = 0;
	a_price = -1;
	a_date.SetDate(date_d, date_m, date_y);
	if (a_telephone) {
		delete[] a_telephone;
	}
	a_telephone = new char[strlen(telephone) + 1];
	strcpy(a_telephone, telephone);
}

void DataBase::SetCity(const char* newCity) {
	strcpy(a_city, newCity);
}

void DataBase::SetCityKey(int newKey) {
	a_citykey = newKey;
}

void DataBase::ChangeTarif() {
	ChooseTarif();
	GetPrice();
}

 void DataBase::SetDuration() {
	 int a;
	 cin >> a;
	 a_duration = a;
	 GetPrice();
 }

void DataBase::SetTelephone(const char* newTel) {
	strcpy(a_telephone, newTel);
}

void DataBase::SetPayDay(int newDay) {
	a_payment.SetDay(newDay);
}

void DataBase::SetPayMonth(int newMonth) {
	a_payment.SetMonth(newMonth);
}

void DataBase::SetPayYear(int newYear) {
	a_payment.SetYear(newYear);
}

void DataBase::SetDDay(int newDay) {
	a_date.SetDay(newDay);
}

void DataBase::SetMMonth(int newMonth) {
	a_date.SetMonth(newMonth);
}

void DataBase::SetYYear(int newYear) {
	a_date.SetYear(newYear);
}

void DataBase::Print()
{
	std::cout << "City: ";
	if (a_city[0] == '\0') std::cout << "<Empty>" << std::endl;
	else puts(a_city);

	std::cout << "City code: ";
	if (a_citykey == -1) std::cout << "<Empty>" << std::endl;
	else std::cout << a_citykey << std::endl;

	std::cout << "Price: ";
	if (a_price == -1) std::cout << "<Empty>" << std::endl;
	else std::cout << a_price << std::endl;

	std::cout << "Date: ";
	if (a_date.isEmpty()) std::cout << "<Empty> " << std::endl;
	else std::cout << a_date.GetDay() << '.' << a_date.GetMonth() << '.' << a_date.GetYear() << std::endl;

	std::cout << "Duration: ";
	if (a_duration == 0) std::cout << "<Empty> " << std::endl;
	else std::cout << a_duration << " min" << std::endl;

	std::cout << "Payment: ";
	if (a_payment.isEmpty()) std::cout << "<Empty>" << std::endl;
	else std::cout << a_payment.GetDay() << '.' << a_payment.GetMonth() << '.' << a_payment.GetYear() << std::endl;

	std::cout << "Telephone: ";
	if (a_telephone[0] == '\0') std::cout << "<Empty>" << std::endl;
	else puts(a_telephone);
}

void DataBase::ChooseTarif() {
	int c;
	cout << "Choose the tarif:" << endl;
	cout << "|1. 50 rub/min with free calls               |" << endl;
	cout << "|2. 100 rub/min with free calls and sms      |" << endl;
	cout << "|3. 150 rub/min with free calls, sms ans wifi|" << endl;
	std::cin >> c;
	switch (c)
	{
	case 1:
		a_tarif = 50;
		break;
	case 2:
		a_tarif = 100;
		break;
	case 3:
		a_tarif = 150;
		break;
	default:
		cout << "Tarif with this number doesn't exist, try again";
		ChooseTarif();
		break;
	}
	GetPrice();
}

void DataBase::PrintNotPaid()
{
	if (a_payment.isEmpty()) Print();
}

void DataBase::PaidNow()
{
	a_payment.SetDateNow();
	a_duration = 0;
	a_price = -1;
}


void DataBase::Paid(const int& payment_d, const int& payment_m, const int& payment_y)
{
	a_payment.SetDate(payment_d, payment_m, payment_y);
}

std::ostream& operator<< (std::ostream& out, const DataBase& t)
{
	out.write((char*)&t.a_citykey, sizeof(t.a_citykey));
	out.write((char*)&t.a_price, sizeof(t.a_price));
	out.write((char*)&t.a_duration, sizeof(t.a_duration));
	out << t.a_date << t.a_payment;

	int buf = strlen(t.a_city);
	out.write((char*)&buf, sizeof(buf));
	out << t.a_city;
	buf = strlen(t.a_telephone);
	out.write((char*)&buf, sizeof(buf));
	out << t.a_telephone;

	return out;
}

std::istream& operator>> (std::istream& in, DataBase& t)
{
	in.read((char*)&t.a_citykey, sizeof(int));
	in.read((char*)&t.a_price, sizeof(int));
	in.read((char*)&t.a_duration, sizeof(int));
	in >> t.a_date >> t.a_payment;

	int buffer = 0;
	in.read((char*)&buffer, sizeof(int));
	delete[] t.a_city;
	t.a_city = new char[buffer + 1];
	for (int i = 0; i < buffer; i++)
	{
		char b;
		in.read((char*)&b, sizeof(char));
		t.a_city[i] = b;
	}
	t.a_city[buffer] = '\0';

	in.read((char*)&buffer, sizeof(int));
	delete[] t.a_telephone;
	t.a_telephone = new char[buffer + 1];
	for (int i = 0; i < buffer; i++)
	{
		char b;
		in.read((char*)&b, sizeof(char));
		t.a_telephone[i] = b;
	}
	t.a_telephone[buffer] = '\0';

	return in;
}

bool DataBase::isEmpty()
{
	if (a_city[0] == '\0' && a_telephone[0] == '\0' && a_date.isEmpty()) return true;
	return false;
}

DataBase& DataBase::operator= (DataBase& t)
{
	if (a_city) {
		delete[] a_city;
	}
	a_city = new char[strlen(t.a_city) + 1];
	strcpy(a_city, t.a_city);

	a_citykey = t.a_citykey;
	a_price = t.a_price;
	a_duration = t.a_duration;
	a_date.SetDate(t.a_date.GetDay(), t.a_date.GetMonth(), t.a_date.GetYear());
	if (a_telephone) {
		delete[] a_telephone;
	}
	a_telephone = new char[strlen(t.a_telephone) + 1];
	strcpy(a_telephone, t.a_telephone);
	a_payment.SetDate(t.a_payment.GetDay(), t.a_payment.GetMonth(), t.a_payment.GetYear());
	return *this;
}

void DataBase::RDate()
{
	a_date.SetDate(rand() % 30 + 1, rand() % 12 + 1, rand() % 100 + 2000);
}
