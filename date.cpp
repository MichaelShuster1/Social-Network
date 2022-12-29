#include "date.h"

Date::Date(int y, int m, int d) noexcept(false)
{
	if (d > LAST_DAY_OF_MONTH ||d < FIRST_DAY_OF_MONTH ||m > DECEMBER || m < JANUARY || y > CURRENT_YEAR || y < EARLIEST_YEAR)
		throw DateFormatException();
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