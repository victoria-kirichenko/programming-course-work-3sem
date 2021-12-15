#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include "List.hpp"
#include "full_class/DataBase.hpp"

class Menu {

public:
	Menu();
	void Start();
	void AddR();
	void Add();
	void Del();

private:
	bool loop;
	List info;
};

#endif // MENU_HPP_INCLUDED