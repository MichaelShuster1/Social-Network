#ifndef STATUS_VIDEO_H
#define STATUS_VIDEO_H

#include "status.h"

class StatusVideo : public Status
{
private:
	std::string video;

public:
	StatusVideo(const std::string text,const std::string time,const std::string video);
	StatusVideo(const StatusVideo& other);
	virtual void attached(std::ostream& os) const;
	virtual bool operator==(const Status& other) const override; //checks if the text of 2 statuses is the same
	virtual bool operator!=(const Status& other) const override; //checks if the text of 2 statuses isnt the same
	virtual Status* clone() const override;
};



#endif // !STATUS_VIDEO_H