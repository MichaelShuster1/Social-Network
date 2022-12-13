#ifndef STATUS_H
#define STATUS_H

#pragma warning(disable: 4996)

#include <iostream>
#include "date.h"

class Status
{
private:
	Date publish_date;
	char* time;
	char* text;

public:
	Status(const char* _text = nullptr, const char* _time=nullptr); //default c'tor
	~Status(); //d'tor
	void showStatus() const; //shows the text and time of this status
	bool operator==(const Status& status) const;
	bool operator!=(const Status& status) const;

};



#endif // !STATUS_H

