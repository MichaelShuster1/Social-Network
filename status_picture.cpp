#include "status_picture.h"
using namespace std;



StatusPicture::StatusPicture(const string& text,const string& time,const string& picture) : Status(text, time)
{
	if (picture.size() == EMPTY)
		throw EmptyPictureException();
	if (!checkExtension(picture, ".jpg") && !checkExtension(picture, ".png"))
		throw PictureExtensionException();
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



bool StatusPicture::checkExtension(const string& file_name,const string& extension)
{
	if (file_name.size() <= 4)
		return false;
	else
		return (file_name.compare(file_name.size() - 4, 4, extension) == 0);
}

void StatusPicture::attached(std::ostream& os) const
{
	if (typeid(os) == typeid(ofstream))
	{
		os << picture << endl;
	}
	else
	{
		cout << "*picture is opening with operating system's default photo viewer..." << endl;
		string command = "start " + picture;
		system(command.c_str());
	}
}

void StatusPicture::fromOs(std::istream& in)
{
	if (typeid(in) == typeid(ifstream) || typeid(in)== typeid(istream))
		getline(in, picture);
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