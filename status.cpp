#include "status.h"

Status::Status(const Date& d,const Hour& h,const char* t)
{
	publish_date = d;
	publish_hour = h;
	text = new char[strlen(t) + 1];
	strcpy(text, t);
}

Status::~Status()
{
	delete[] text;
}


void Status::showStatus()
{
	cout << text;
}

Status::Status(const Status& other)
{
	publish_date = other.publish_date;
	publish_hour = other.publish_hour;
	text = new char[strlen(other.text)+1];
	strcpy(text,other.text);
}



