#ifndef STATUS_H
#define STATUS_H

#pragma warning(disable: 4996)

#include <fstream>
#include <string>
#include "exceptions.h"


const int EMPTY = 0;

class Status
{
private:
	std::string time;
	std::string text;


public:
	Status(const std::string& text,const std::string& time) noexcept(false); //c'tor 1
	Status(std::ifstream& in);// c'tor 2
	Status(const Status& other); //copy c'tor
	virtual ~Status() {}; //d'tor
	friend std::ostream& operator<<(std::ostream& os, const Status& status); //prints the status to the console/file
	friend std::istream& operator>>(std::istream& in, Status& status); //gets as input from the console/file the status
	virtual void attached(std::ostream& os) const {}; //used in case the inheriting son doesn't overload the funcion
	virtual void fromOs(std::istream& in) {}; //used in case the inheriting son doesn't overload the funcion
	virtual bool operator==(const Status& status) const; //checks if the text of 2 statuses is the same
	virtual bool operator!=(const Status& status) const; //checks if the text of 2 statuses isnt the same
	virtual Status* clone() const; //returns a allocted clone of this status object

};



#endif // !STATUS_H

