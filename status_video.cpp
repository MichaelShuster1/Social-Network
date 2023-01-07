#include "status_video.h"
using namespace std;



StatusVideo::StatusVideo(string text, string time, string video) : Status(text, time)
{
	if (video.size() == EMPTY)
		throw EmptyVideoException();
	this->video = video;
}


StatusVideo::StatusVideo(StatusVideo& other) : Status(other)
{
	this->video = other.video;
}


void StatusVideo::attached(std::ostream& os) const
{
	string command = "start " + video;
	system(command.c_str());
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