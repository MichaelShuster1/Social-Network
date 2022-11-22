#include "date.h"


Date::Date(int y, int m, int d)
{
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