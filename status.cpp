#include "status.h"



Status::Status(const char* _text, const char* _time)
{
	if (_text != nullptr)
	{
		text = new char[strlen(_text) + 1];
		strcpy(text, _text);
	}
	else
		text = nullptr;

	if (_time != nullptr)
	{
		time= new char[strlen(_time) + 1];
		strcpy(time, _time);
	}
	else
		time = nullptr;
}



Status::~Status()
{
	delete[] text;
	delete[] time;
}


void Status::showStatus()
{
	cout << text << endl;
	cout <<"Status publish time: " << time << endl;
}



void Status::copyStatus(const Status& other)
{
	publish_date = other.publish_date;
	publish_hour = other.publish_hour;
	text = new char[strlen(other.text)+1];
	strcpy(text,other.text);
	time = new char[strlen(other.time) + 1];
	strcpy(time,other.time);
}



