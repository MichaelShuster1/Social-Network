#ifndef MEMBER_H
#define MEMBER_H
#include "Entity.h"
#include <vector>
#include "status_picture.h"
#include "status_video.h"
#include "date.h"


const int RANGE = 10;
const int INCREASE_RATE = 2;


class Fan_page;

class Member : public Entity
{

private:
	Date birth_date;
	std::vector<Fan_page*> pages;
	std::vector<Member*> friends;

public:
	Member(const std::string _name, const Date& date) noexcept(false) :Entity(_name), birth_date(date) {}; //c'tor
	Member(std::ifstream& in) : birth_date(in), Entity(in) {}; //c'tor for file 
	Member(const Member& other);// copy c'tor
	Member(Member&& other) noexcept(true); // move c'tor
	void operator+=(Member& _member) noexcept(false); //adds a user to the member's friends
	void addPage(Fan_page& page) noexcept(false); //adds a fan page to the member's fan pages 
	void removePage(Fan_page& page) noexcept(false);//removes a page from the user's fan page 
	void removeFriend(Member& member) noexcept(false);//removes a user from the member's friends
	void showAllFriends() const ;//prints all friends of a member
	void showAllStatuses() const;//prints all statuses of a member
	void showTenRecentStatuses() const ;// prints the last 10 statuses of the member
	void showAllFriendsTenStatuses()const ;// prints 10 last statuses of each friend of the member
	int getFriendsSize() const;//return the friends array size
	int getPagesSize() const;//return the pages array size
	bool operator>(const Member& member) const; // return true if this member have more friends than given member
	bool operator>(const Fan_page& page) const; // return true if this member have more friends than the number of fans of the given page
	bool areFriendsCheck(const Member& member) const; //checks if a member is a friend of the given member
	bool isPageFollower(const Fan_page& page) const; //checks if a member is a fan of the given page
	void saveFriendsToFile(std::ofstream& os) const;//print friends and pages of a member to a file
	void oneSidedLink(Member& member); //adds the given member to the friends of the activating object (one sided link)
	virtual void fromOs(std::istream& in) override;
	virtual void toOs(std::ostream& os) const override;
};



#endif

