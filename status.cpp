#include "status.h"

Status::Status(Date& d, Hour& h, char* t)
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