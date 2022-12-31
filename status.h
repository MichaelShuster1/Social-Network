#ifndef STATUS_H
#define STATUS_H

#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include "exceptions.h"


const int EMPTY = 0;

class Status
{
private:
	std::string time;
	std::string text;


public:
	Status(std::string text, std::string time) noexcept(false); //default c'tor
	Status(const Status& other); //copy c'tor
	void showStatus() const; //shows the text and time of this status
	bool operator==(const Status& status) const; //checks if the text of 2 statuses is the same
	bool operator!=(const Status& status) const; //checks if the text of 2 statuses isnt the same

};



#endif // !STATUS_H

