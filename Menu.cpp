#include "Menu.h"

void Menu::Start()
{
	int idx = 0;
	int c = 0;
	while (loop)
	{
		std::cin >> c;
		switch (c)
		{
		case 1:
			AddR();
			std::cout << "Ready!\n";
			break;
		case 2:
			Add();
			std::cout << "Ready!\n";
			break;
		case 3:
			info.PrintAll();
			std::cout << "Ready!\n";
			break;
		case 4:
			info.PrintPage();
			std::cout << "Ready!\n";
			break;
		case 5:
			info.PrintNotPaidAll();
			std::cout << "Ready!\n";
			break;
		case 6:
			info.Clear();
			std::cout << "Ready!\n";
			break;
		case 7:
			info.Sort();
			std::cout << "Ready!\n";
			break;
		case 8:
			std::cin >> idx;
			info.Del(idx - 1);
			std::cout << "Ready!\n";
			break;
		case 9:
			std::cin >> idx;
			info.Edit(idx - 1);
			std::cout << "Ready!\n";
			break;
		case 10:
			std::cin >> idx;
			info.PaidTarif(idx - 1);
			std::cout << "Ready!\n";
			break;
		case 11:
			info.PaidTarifAll();
			std::cout << "Ready!\n";
			break;
		case 12:
			info.PrintPrice();
			std::cout << "Ready!\n";
			break;
		case 13:
			loop = false;
			std::cout << "Ready!\n";
			break;

		default:
			std::cout << "Size of objects:" << info.Size() << endl;
			std::cout << "1 - Add Random\n";
			std::cout << "2 - Add [City] [CityKey] [Date] [Duration] [Tele] [index]\n";
			std::cout << "3 - Print All\n";
			std::cout << "4 - Print Page\n";
			std::cout << "5 - Print Not Paid All\n";
			std::cout << "6 - Clear all file\n";
			std::cout << "7 - Sort by dates\n";
			std::cout << "8 - Delete from file [number of object]\n";
			std::cout << "9 - Edit object [number of object]\n";
			std::cout << "10 - Paid Tarif of object [number of object]\n";
			std::cout << "11 - Paid Tarifs of All objects\n";
			std::cout << "12 - Print price durations of objects\n";
			std::cout << "13 - Exit\n";
			break;
		}
	}
}

Menu::Menu()
{
	loop = true;
	srand(1);
}

void Menu::AddR()
{
	char City[5][50] = { "NSK","Moskow","Ufa","Komchatka","Piter" };
	char Tele[5][50] = { "89124355020","2362020","+79134449900","911","+2" };
	DataBase b(City[rand() % 5], rand() % 500, rand() % 30 + 1,
	rand() % 12 + 1, rand() % 100 + 2000, 0, Tele[rand() % 5]);
	if (rand() % 3 == 1) b.PaidNow();
	b.RDuration();
	b.ChooseTarif();
	b.RDate();
	info.Add(b);
}

void Menu::Add()
{
	char *City = new char[50];
	int key, dd, mm, yy, ms, k;
	char *Tele = new char[50];
	int index;
	std::cout << "preserving add or add with index?\n|0 - Add with index                  |\n|1 - Preserving Add (only after Sort)|\n";
	std::cin >> k;
	cout << "City: ";
	std::cin >> City;
	cout << "City key: ";
	std::cin >> key;
	cout << "Date: [day] [month] [year]" << endl;
	std::cin >> dd >> mm >> yy;
	cout << "Duration: [minutes]" << endl;
	std::cin >> ms;
	cout << "Telephone: ";
	std::cin >> Tele;
	DataBase c(City, key, dd, mm, yy, ms, Tele);
	c.ChooseTarif();
	if (rand() % 3 == 1) c.PaidNow();
	if (k == 0) {
		cout << "number of object [begin from 1]: ";
		std::cin >> index;
		info.Add(c, index - 1);
	}
	else {
		info.AddWith(c);
	}
	try {
		if (c.CheckingDate() == 1) {
			throw MyException("\n!DATE INPUT INCORRECT, you can choose command *9 - Edit* in menu!\n");
		}
		else if (ms < 0) {
			throw MyException("\n!DURATION INPUT INCORRECT, you can choose command *9 - Edit* in menu!\n");
		}
	}
	catch (MyException& ex) {
		cerr << ex.what() << "\n";
	}
	delete[] City;
	delete[] Tele;
}
