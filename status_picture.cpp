#include "status_picture.h"
using namespace std;



StatusPicture::StatusPicture(const string text,const string time,const string picture) : Status(text, time)
{
	if (picture.size() == EMPTY)
		throw EmptyPictureException();
	this->picture = picture;
}


StatusPicture::StatusPicture(ifstream& in) :Status(in)
{
	fromOs(in);
}


StatusPicture::StatusPicture(const StatusPicture& other) : Status(other)
{
	this->picture = other.picture;
}


void StatusPicture::attached(std::ostream& os) const
{
	if (typeid(os) == typeid(ofstream))
	{
		os << picture << endl;
	}
	else
	{
		string command = "start " + picture;
		system(command.c_str());
	}
}

void StatusPicture::fromOs(std::istream& in)
{
	if (typeid(in) == typeid(ifstream))
		in >> picture;
	else
	{
		//
	}
}


bool StatusPicture::operator==(const Status& other)  const
{
	if (!Status::operator==(other))
		return false;

	const StatusPicture* temp = dynamic_cast<const StatusPicture*>(&other);
	if (temp == NULL)
		return false;

	return picture == temp->picture;

}


bool StatusPicture::operator!=(const Status& other) const
{
	return !((*this) == other);
}


Status* StatusPicture::clone() const
{
	 return new StatusPicture(*this);
}