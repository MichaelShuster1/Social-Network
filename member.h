#ifndef MEMBER_H
#define MEMBER_H



#include "status.h"

class Fan_page;

class Member
{

private:
	char* name;
	Date birth_date;
	Status* status_array;
	Fan_page* pages;
	Member* friends;
	int numOfFriends;
	int numOfStatuses;
	int numOfPages;

public:
	Member();
	void addFriend(Member& _member);
	void addStatus(Status& _status);
	void showStatuses();
	void showFriends();
	void showName();
	void showAllStatuses();
};








#endif

