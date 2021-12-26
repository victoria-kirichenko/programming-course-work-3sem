#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include "DataBase.h"
#include "List.h"

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