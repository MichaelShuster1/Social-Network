#ifndef STATUS_VIDEO_H
#define STATUS_VIDEO_H
#include "status.h"

class StatusVideo : public Status
{
private:
	std::string video;

public:
	StatusVideo(const std::string& text,const std::string& time,const std::string& video);// c'tor 1
	StatusVideo(std::ifstream& in);//c'tor 2
	StatusVideo(const StatusVideo& other); //copy c'tor
	virtual void attached(std::ostream& os) const; // Starts the video specified in the `video` member variable.
	virtual void fromOs(std::istream& in) override; //reads the video name from the file/console
	virtual bool operator==(const Status& other) const override; //checks if the 2 objects are the same
	virtual bool operator!=(const Status& other) const override; //checks if the 2 objects are not the same
	virtual Status* clone() const override; //make a clone (allocates new memory) of the object as a StatusVideo object
	static bool checkExtension(const std::string& video, const std::string& extension); //checks if the video have a correct extension
};



#endif // !STATUS_VIDEO_H