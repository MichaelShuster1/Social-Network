#include "status.h"
using namespace std;


Status::Status(const string& text,const string& time) noexcept(false)
{
	if (text.size() == EMPTY)
		throw EmptyTextException();
	if (time.size() == EMPTY)
		throw EmptyTimeException();
	this->text = text;
	this->time = time;
}


Status::Status(ifstream& in)
{
	in >> *this;
}

Status::Status(const Status& other)
{
	text = other.text;
	time = other.time;
}




ostream& operator<<(ostream& os, const Status& status)
{
	if (typeid(os) == typeid(ofstream))
	{
		os << typeid(status).name() + 6 <<endl;
		os << status.text << endl << status.time << endl;
		status.attached(os);
	}
		
	else
	{
		os << status.text << endl;
		status.attached(os);
		os << "Status publish time: " << status.time << endl;
	}
	return os;
}


istream& operator>>(istream& in, Status& status)
{
	if (typeid(in) == typeid(ifstream))
	{
		getline(in, status.text);
		getline(in, status.time);
	}
	else
	{
		getline(in, status.text);
		time_t curr_time;
		curr_time = time(NULL);
		status.time= ctime(&curr_time);
		status.time.pop_back();
	}
	status.fromOs(in);
	return in;
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

Status* Status::clone() const 
{ 
	return new Status(*this); 
};
