#pragma once
#include "DataBase.hpp"
#include <iostream>
#include <fstream>

class List
{
private:
	int* index;
	std::fstream Stream;
public:
	List();
	~List();
	void Printinfo();
	int Size();
	void Get(DataBase& object, const int& i = 0);
	void UpdateInfo();
	void Add(const DataBase& object);
	void Add(const DataBase& object, const int& i);
	void AddWith(DataBase& object);
	void Del(const int& i);
	void Clear();
	void PrintAll();
	void PrintNotPaidAll();
	void PaidTarif(int i);
	void PaidTarifAll();
	void Sort();
	void PricePrint();
	void Edit(int i);
};
