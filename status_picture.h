#ifndef STATUS_PICTURE_H
#define STATUS_PICTURE_H

#include "status.h"

class StatusPicture : public Status
{
private:
	std::string picture;

public:
	StatusPicture(const std::string text,const std::string time,const std::string picture); //c'tor 1
	StatusPicture(ifstream& in); //c'tor 2
	StatusPicture(const StatusPicture& other);//copy c'tor
	virtual void attached(std::ostream& os) const; //adds to the given ostream the relevant concatenation
	virtual void fromOs(std::istream& in) override;
	virtual bool operator==(const Status& other) const override; //checks if this status is equal to the given status
	virtual bool operator!=(const Status& other) const override; //checks if this status is not equal to the given status
	virtual Status* clone() const override;  //duplicates a new status with this status and returns it 
};



#endif // !STATUS_PICTURE_H

