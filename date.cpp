#include "date.h"
using namespace std;

Date::Date(int y, int m, int d) noexcept(false)
{
	if (d > LAST_DAY_OF_MONTH ||d < FIRST_DAY_OF_MONTH ||m > DECEMBER || m < JANUARY || y > CURRENT_YEAR || y < EARLIEST_YEAR)
		throw DateFormatException();
	year = y;
	month = m;
	day = d;
}

Date::Date(ifstream& in)
{
	in >> *this;
}

Date::Date(const Date& other)
{
	year = other.year;
	month = other.month;
	day = other.day;
}

ostream& operator<<(ostream& os, const Date& date)
{
	if (typeid(os) == typeid(ofstream))
		os << date.day << " " << date.month << " " << date.year << endl;
	else
		os << date.day << "/" << date.month << "/" << date.year << endl;
	return os;
}

istream& operator>>(istream& in, Date& date)
{
	if (typeid(in) == typeid(ifstream))
	{
		in >> date.day >> date.month >> date.year;
		in.ignore();
	}
	else
	{
		char slash;
		in >> date.day >> slash >> date.month >> slash >> date.year;
	}
	return in;


}