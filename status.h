#ifndef STATUS_H
#define STATUS_H

#pragma warning(disable: 4996)

#include <iostream>
#include <string>

using namespace std;

const int EMPTY = 0;

class Status
{
private:
	string time;
	string text;


public:
	Status(string text, string time) throw(const char*); //default c'tor
	Status(const Status& other);
	void showStatus() const; //shows the text and time of this status
	bool operator==(const Status& status) const;
	bool operator!=(const Status& status) const;

};



#endif // !STATUS_H

