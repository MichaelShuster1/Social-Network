#ifndef STATUS_VIDEO_H
#define STATUS_VIDEO_H

#include "status.h"

class StatusVideo : public Status
{
private:
	std::string video;

public:
	StatusVideo(std::string text, std::string time, std::string video);
	StatusVideo(StatusVideo& other);
	virtual void attached(std::ostream& os) const;
	virtual bool operator==(const Status& other) const; //checks if the text of 2 statuses is the same
	virtual bool operator!=(const Status& other) const; //checks if the text of 2 statuses isnt the same
};



#endif // !STATUS_VIDEO_H