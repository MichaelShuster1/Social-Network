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
	void add_status(Date& date, Hour& hour, char* text);
	void reSizeStatusArr(Status* status_array, int size, int new_size);
	void copyStatusArr(Status* dest, Status* src);
	void deleteStatusArr(Status* arr);
	void showStatuses();
	void showAllFriends();
	void showName();
	void showAllStatuses();
};








#endif

