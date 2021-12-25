#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include "DataBase.hpp"
#include "List.hpp"

class Menu
{
private:
	bool loop;
	List info;
public:
	Menu();
	void Start();
	void AddR();
	void Add();
};