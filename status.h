#ifndef STATUS_H
#define STATUS_H

#pragma warning(disable: 4996)

#include <iostream>
using namespace std;
#include "date.h"
#include "hour.h"

class Status
{
private:
	Date publish_date;
	Hour publish_hour;
	char* time;
	char* text;

public:
	Status(const char* _text = nullptr, const char* _time=nullptr); //default c'tor
	~Status(); //d'tor
	void showStatus() const; //shows the text and time of this status

};



#endif // !STATUS_H

