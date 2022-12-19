#include "status.h"


Status::Status(string text, string time) throw(const char*)
{
	if (text.size() == EMPTY)
		throw "You cant add an empty status!";
	if (time.size() == EMPTY)
		throw "You cant add a status with empty time!";
	this->text = text;
	this->time = time;
}

Status::Status(const Status& other)
{
	text = other.text;
	time = other.time;
}



void Status::showStatus() const
{
	cout << text << endl;
	cout <<"Status publish time: " << time << endl;
}



bool Status::operator==(const Status& status) const
{
	bool res=false;
	if (text == status.text)
		res = true;
	return res;  
}

bool Status::operator!=(const Status& status) const
{
	return !(*this == status);
}
