#include "status_video.h"
using namespace std;



StatusVideo::StatusVideo(const string& text,const string& time,const string& video) : Status(text, time)
{
	if (video.size() == EMPTY)
		throw EmptyVideoException();
	if(!(checkExtension(video,".mov")))
		throw VideoExtensionException();
	this->video = video;
}


StatusVideo::StatusVideo(ifstream& in): Status(in)
{
	fromOs(in);
}


StatusVideo::StatusVideo(const StatusVideo& other) : Status(other)
{
	this->video = other.video;
}


void StatusVideo::attached(std::ostream& os) const
{
	if (typeid(os) == typeid(ofstream))
	{
		os << video << endl;
	}
	else
	{
		string command = "start " + video;
		system(command.c_str());
	}
}


void StatusVideo::fromOs(std::istream& in)
{
	if (typeid(in) == typeid(ifstream)|| typeid(in) == typeid(istream))
		getline(in, video);
}


bool StatusVideo::operator==(const Status& other)  const
{
	if (!Status::operator==(other))
		return false;

	const StatusVideo* temp = dynamic_cast<const StatusVideo*>(&other);
	if (temp == NULL)
		return false;

	return video == temp->video;

}


bool StatusVideo::operator!=(const Status& other) const
{
	return !((*this) == other);
}


Status* StatusVideo::clone() const
{
	return new StatusVideo(*this);
}


bool StatusVideo::checkExtension(const string& video, const string& extension)
{
	if (video.size() < 5)
		return false;
	else
		return ((video.compare(video.size() - 4, 4, extension) == 0));
}