#include "date.h"


Date::Date(int y, int m, int d) throw (const char*)
{
	if (d > 31 ||d < 1 ||m > 12 || m < 1 || y > CURRENT_YEAR || y < 1900)
		throw "Incorrect birth date";
	year = y;
	month = m;
	day = d;
}


Date::Date(const Date& other)
{
	year = other.year;
	month = other.month;
	day = other.day;
}