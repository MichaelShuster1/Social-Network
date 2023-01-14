#ifndef DATE_H
#define DATE_H
#include "exceptions.h"
#include <fstream>

const int CURRENT_YEAR = 2022;
const int EARLIEST_YEAR = 1900;
const int DECEMBER = 12;
const int JANUARY = 1;
const int FIRST_DAY_OF_MONTH = 1;
const int LAST_DAY_OF_MONTH = 31;
const char SLASH = '/';

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date(int y, int m, int d) noexcept(false); //default c'tor
	Date(std::ifstream& in);//c'tor for file
	Date(const Date& other); //copy c'tor
	friend class Member;
	friend std::ostream& operator<<(std::ostream& os, const Date& date); // << operator overload for date
	friend std::istream& operator>>(std::istream& os, Date& date); // >> operator overload for date
};




#endif // !DATE_H
