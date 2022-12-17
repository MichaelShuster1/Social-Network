#ifndef DATE_H
#define DATE_H

const int CURRENT_YEAR = 2022;

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date(int y, int m, int d) throw(const char*); //default c'tor
	Date(const Date& other); //copy c'tor
	friend class Member;
};




#endif // !DATE_H
