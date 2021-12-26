#pragma once
#include "DataBase.h"
#include <iostream>
#include <fstream>

class List
{
private:
	int* index;
	std::fstream Stream;
public:

	List();

	int Size();
	void UpdateInfo();

	void Add(const DataBase& object);
	void Add(const DataBase& object, const int& i);
	void AddWith(DataBase& object);

	void Get(DataBase& object, const int& i = 0);
	void Sort();
	void Edit(int i);
	void Del(const int& i);
	void Clear();

	void Printinfo();
	void PrintAll();
	void PrintNotPaidAll();
	void PaidTarif(int i);
	void PaidTarifAll();
	void PrintPrice();
	void PrintPage();

	~List();
};
