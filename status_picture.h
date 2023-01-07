#ifndef STATUS_PICTURE_H
#define STATUS_PICTURE_H

#include "status.h"

class StatusPicture : public Status
{
private:
	std::string picture;

public:
	StatusPicture(const std::string text,const std::string time,const std::string picture);
	StatusPicture(const StatusPicture& other);
	virtual void attached(std::ostream& os) const;
	virtual bool operator==(const Status& other) const override; //checks if the text of 2 statuses is the same
	virtual bool operator!=(const Status& other) const override; //checks if the text of 2 statuses isnt the same
	virtual Status* clone() const override; 
};



#endif // !STATUS_PICTURE_H

