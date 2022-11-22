#ifndef STATUS_H
#define STATUS_H

#pragma warning(disable: 4996)

#include <iostream>
using namespace std;
#include "date.h"
#include "hour.h"

class Status
{
public:
	Status(const Date& d,const Hour& h, const char* t);
	Status(const char* t=nullptr);
	void copyStatus(const Status& other);
	
	~Status();
	void showStatus();

private:
	Date publish_date;
	Hour publish_hour;
	char* text;
};



#endif // !STATUS_H

