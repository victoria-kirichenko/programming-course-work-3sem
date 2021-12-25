#include "List.hpp"

void List::UpdateInfo()
{
	int buffer[1000];
	int max = 0;
	delete[] index;
	Stream.open("File.bin", std::fstream::in | std::ios::binary);
	Stream.seekg(0);

	do
	{
		DataBase buf;
		Stream >> buf;
		buffer[max] = Stream.tellg();
		max++;
	} while (buffer[max - 1] != -1);

	index = new int[max];
	for (int i = 0; i < max; i++) index[i] = buffer[i];
	Stream.close();
}

List::List()
{
	index = new int[1];
	UpdateInfo();
	Stream.seekg(0);
}

List::~List()
{
	delete[] index;
}

void List::Printinfo()
{
	std::cout << "Have: " << Size() << " objects\n";
	for (int i = 0; i < Size(); i++)
	{
		std::cout << "index " << i << " is " << index[i] << ";\n";
	}
}

int List::Size()
{
	int i = 0;
	while (index[i] != -1)
	{
		i++;
	}
	return i;
}

void List::Get(DataBase& object, const int& i)
{
	if (i <= Size() && i >= 0)
	{
		Stream.open("File.bin", std::fstream::in | std::fstream::out | std::ios::binary);
		if (i != 0) Stream.seekg(index[i - 1], std::ios::beg);
		Stream >> object;
		Stream.close();
	}
}

void List::Add(const DataBase& object)
{
	Stream.open("File.bin", std::fstream::out | std::ios::binary | std::fstream::app);
	Stream << object;
	Stream.close();
	UpdateInfo();
}

void List::Add(const DataBase& object, const int& i)
{
	if (i <= Size() && i >= 0)
	{
		std::fstream BufferStream("Buffer.bin", std::fstream::out | std::ios::binary | std::ios::trunc);

		int size = Size();
		for (int j = 0; j < size; j++)
		{
			DataBase b;
			if (j == i) BufferStream << object;
			Get(b, j);
			BufferStream << b;
		}
		BufferStream.close();

		Stream.open("File.bin", std::fstream::out | std::ios::binary | std::ios::trunc);
		BufferStream.open("Buffer.bin", std::fstream::in | std::ios::binary);

		do
		{
			DataBase b;
			BufferStream >> b;
			if (!b.isEmpty()) Stream << b;

		} while (BufferStream.tellg() != -1);
		Stream.close();
		BufferStream.close();

		BufferStream.open("Buffer.bin", std::ofstream::out | std::ios::trunc);
		BufferStream.close();

		UpdateInfo();
	}
	else
	{
		Add(object);
	}
}

void List::Del(const int& i)
{
	if (i <= Size() + 1 && i >= 0)
	{
		std::fstream BufferStream("Buffer.bin", std::fstream::out | std::ios::binary | std::ios::trunc);

		int size = Size();
		for (int j = 0; j <= size; j++)
		{
			if (j != i)
			{
				DataBase b;
				Get(b, j);
				BufferStream << b;
			}
		}
		BufferStream.close();

		Stream.open("File.bin", std::fstream::out | std::ios::binary | std::ios::trunc);
		BufferStream.open("Buffer.bin", std::fstream::in | std::ios::binary);

		do
		{
			DataBase b;
			BufferStream >> b;
			if (!b.isEmpty()) Stream << b;

		} while (BufferStream.tellg() != -1);
		Stream.close();
		BufferStream.close();

		BufferStream.open("Buffer.bin", std::ofstream::out | std::ios::trunc);
		BufferStream.close();

		UpdateInfo();
	}
}

void List::Clear()
{
	Stream.open("File.bin", std::fstream::out | std::ios::binary | std::ios::trunc);
	Stream.close();
	UpdateInfo();
}

void List::PrintAll()
{
	int size = Size();
	for (int i = 0; i < size; i++)
	{
		std::cout << "Object " << i + 1 << " have info: \n";
		DataBase b;
		Get(b, i);
		b.Print();
		std::cout << "\n";
	}
}

void List::PrintNotPaidAll()
{
	int size = Size();
	for (int i = 0; i < size; i++)
	{
		DataBase b;
		Get(b, i);
		if (!b.isPaid())
		{
			std::cout << "Object " << i + 1 << " have info:";
			b.PrintNotPaid();
			std::cout << "\n";
		}
	}
}

void List::Sort()
{
	int size = Size();
	int* id = new int[size + 1];
	for (int i = 0; i < size; i++) id[i] = i;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			DataBase b1, b2;
			Get(b1, id[j - 1]);
			Get(b2, id[j]);

			if (b1.Date() > b2.Date())
			{
				int temp = id[j - 1];
				id[j - 1] = id[j];
				id[j] = temp;
			}
		}
	}

	std::fstream BufferStream("Buffer.bin", std::fstream::out | std::ios::binary | std::ios::trunc);

	for (int j = 0; j < size; j++)
	{
		DataBase b;
		Get(b, id[j]);
		BufferStream << b;
	}
	BufferStream.close();


	Stream.open("File.bin", std::fstream::out | std::ios::binary | std::ios::trunc);
	BufferStream.open("Buffer.bin", std::fstream::in | std::ios::binary);

	do
	{
		DataBase b;
		BufferStream >> b;
		if (!b.isEmpty()) Stream << b;

	} while (BufferStream.tellg() != -1);
	Stream.close();
	BufferStream.close();

	BufferStream.open("Buffer.bin", std::ofstream::out | std::ios::trunc);
	BufferStream.close();

	UpdateInfo();
}

void List::PricePrint()
{
	int size = Size();
	for (int i = 0; i < size; i++)
	{
		DataBase b;
		Get(b, i);
		std::cout << b.GetPrice() << std::endl;
	}
}

void List::PaidTarif(int i) {
	DataBase b;
	Get(b, i);
	b.PaidNow();
	Add(b, i);
	Del(i + 1);
}

void List::PaidTarifAll() {
	int size = Size();
	DataBase b;
	for (int i = 0; i < size; i++) {
		Get(b, i);
		b.PaidNow();
		Add(b, i);
		Del(i + 1);
	}
}

void List::Edit(int i) {
	char City[50];
	bool loop = true;
	int key, dd, mm, yy;
	char Tele[50];
	DataBase b;
	Get(b, i);
	std::cout << "What do you want to change? Click '0'" << endl;
	int c = 0;
	while (loop)
	{
		std::cin >> c;
		switch (c)
		{
		case 1:
			std::cin >> City;
			b.SetCity(City);
			std::cout << "Ready!\n";
			break;
		case 2:
			std::cin >> key;
			b.SetCityKey(key);
			std::cout << "Ready!\n";
			break;
		case 3:
			std::cin >> dd >> mm >> yy;
			b.SetDDay(dd);
			b.SetMMonth(mm);
			b.SetYYear(yy);
			std::cout << "Ready!\n";
			break;
		case 4:
			b.SetDuration();
			std::cout << "Ready!\n";
			break;
		case 5:
			b.ChangeTarif();
			std::cout << "Ready!\n";
			break;
		case 6:
			std::cin >> Tele;
			b.SetTelephone(Tele);
			std::cout << "Ready!\n";
			break;
		case 7:
			std::cin >> dd >> mm >> yy;
			b.SetPayDay(dd);
			b.SetPayMonth(mm);
			b.SetPayYear(yy);
			std::cout << "Ready!\n";
			break;
		case 8:
			b.PaidNow();
			std::cout << "Ready!\n";
			break;
		case 9:
			loop = false;
			std::cout << "Ready!\n";
			break;
		default:
			std::cout << "1 - City\n";
			std::cout << "2 - City key\n";
			std::cout << "3 - Date\n";
			std::cout << "4 - Duration\n";
			std::cout << "5 - Change Tarif\n";
			std::cout << "6 - Telephone\n";
			std::cout << "7 - Payment date\n";
			std::cout << "8 - Paid Tarif\n";
			std::cout << "9 - Exit from editor\n";
			break;
		}
	}
	Add(b, i);
	Del(i + 1);
}

void List::AddWith(DataBase& object) {
	int size = Size();
	DataBase b;
	for (int i = 0; i < size; i++) {
		Get(b, i);
		if (object.Date() > b.Date()) {
			;
		}
		else {
			Add(object, i);
			break;
		}
	}
}
