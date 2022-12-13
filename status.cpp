#include "status.h"
using namespace std;

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


void Status::showStatus() const
{
	cout << text << endl;
	cout <<"Status publish time: " << time << endl;
}



bool Status::operator==(const Status& status) const
{
	bool res=false;
	if (strcmp(text, status.text) == 0)
		res = true;
	return res;  
}

bool Status::operator!=(const Status& status) const
{
	return !(*this == status);
}
