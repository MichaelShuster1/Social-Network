#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date(int y=0, int m=0, int d=0);
	Date(const Date& other);
};




#endif // !DATE_H
