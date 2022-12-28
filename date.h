#ifndef DATE_H
#define DATE_H
#include "exceptions.h"

const int CURRENT_YEAR = 2022;
const int EARLIEST_YEAR = 1990;
const int DECEMBER = 12;
const int JANUARY = 1;
const int FIRST_DAY_OF_MONTH = 1;
const int LAST_DAY_OF_MONTH = 31;

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date(int y, int m, int d) throw(DateFormatException); //default c'tor
	Date(const Date& other); //copy c'tor
	friend class Member;
};




#endif // !DATE_H
