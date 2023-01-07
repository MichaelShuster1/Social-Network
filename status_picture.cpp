#include "status_picture.h"
using namespace std;



StatusPicture::StatusPicture(string text, string time, string picture) : Status(text, time)
{
	if (picture.size() == EMPTY)
		throw EmptyPictureException();
	this->picture = picture;
}


StatusPicture::StatusPicture(StatusPicture& other) : Status(other)
{
	this->picture = other.picture;
}


void StatusPicture::attached(std::ostream& os) const
{
	string command = "start " + picture;
	system(command.c_str());
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