#include "DateTime.hpp"

bool DateTime::operator==(const DateTime& date) {
	if (day == date.day && month == date.month && year == date.year && hours == date.hours 
	&& minutes == date.hours && seconds == date.hours) return true;
	return false;
}

bool DateTime::operator>(const DateTime& date) {
	if (year > date.year) {
        return true;
    } else {
		if (year == date.year)
			if (month > date.month) return true;
			else
			{
				if (month == date.month && day > date.day) return true;
			}
	}
	return false;
}

std::ofstream& operator<< (std::ofstream &os , DateTime& date) {
    try {
        if (!os.is_open()) {
            throw MyException("File cannot open");
        } else {
            os.write((char*)&date.day, sizeof(int));
            os.write((char*)&date.month, sizeof(int));
            os.write((char*)&date.year, sizeof(int));
            os.write((char*)&date.hours, sizeof(int));
            os.write((char*)&date.minutes, sizeof(int));
            os.write((char*)&date.seconds, sizeof(int));

            os.close();
        }
    }
    catch (MyException &ex) {
		cerr << ex.what() << "\n";
    }
   return os;
}

std::ifstream& operator>> (std::ifstream &is , DateTime& date) {
    try {
        if (!is.is_open()) {
            throw MyException("File cannot open");
        } else {
            is.read((char*)&date.day, sizeof(int));
            is.read((char*)&date.month, sizeof(int));
            is.read((char*)&date.year, sizeof(int));
            is.read((char*)&date.hours, sizeof(int));
            is.read((char*)&date.minutes, sizeof(int));
            is.read((char*)&date.seconds, sizeof(int));

            is.close();
        }
    }
    catch (MyException &ex) {
		cerr << ex.what() << "\n";
    }
   return is;
}