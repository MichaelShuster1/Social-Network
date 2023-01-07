#ifndef STATUS_PICTURE_H
#define STATUS_PICTURE_H

#include "status.h"

class StatusPicture : public Status
{
private:
	std::string picture;

public:
	StatusPicture(std::string text,std::string time,std::string picture);
	StatusPicture(StatusPicture& other);
	virtual void attached(std::ostream& os) const;
	virtual bool operator==(const Status& other) const; //checks if the text of 2 statuses is the same
	virtual bool operator!=(const Status& other) const; //checks if the text of 2 statuses isnt the same
};



#endif // !STATUS_PICTURE_H

