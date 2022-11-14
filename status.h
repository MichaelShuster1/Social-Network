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
	Status(Date& d, Hour& h, char* t);
	~Status();
	void showStatus();
	void showAllStatuses();

private:
	Date publish_date;
	Hour publish_hour;
	char* text;
};



#endif // !STATUS_H

