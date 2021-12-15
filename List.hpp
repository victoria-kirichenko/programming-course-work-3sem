#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include "full_class/DataBase.hpp"

class List {

public:
	List();
    
	void Printinfo();
	int Size();
	void Get(DataBase& object, const int& i = 0);
	void UpdateInfo();
	void Add(const DataBase& object);
	void Add(const DataBase& object, const int& i);
	void Del(const int& i);
	void Clear();
	void PrintAll();
	void PrintPaidAll();
	void Sort();
	void PricePrint();

    ~List();

private:
	int* index;
	std::fstream Stream;
};

#endif // LIST_HPP_INCLUDED