#ifndef DATEHOUR_H
#define DATEHOUR_H




class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date(int y, int m, int d);
	Date() {};
};

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

class Hour
{
public:
	Hour(int h, int m);
	Hour() {};

private:
	int hour;
	int minutes;
};


Hour::Hour(int h, int m)
{
	hour = h;
	minutes = m;
}


#endif // !DATEHOUR_H
