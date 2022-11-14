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
	Member(const Member& other);
	~Member();
	void addFriend(Member& _member);
	void removeFriend(Member& _member);
	void add_status(Status& status);
	void reSizeStatusArr(Status* status_array, int size, int new_size);
	void reSizeMemberArr(Member* member_array, int size, int new_size);
	void copyStatusArr(Status* dest, Status* src);
	void copyMemberArr(Member* dest, Member* src);
	void copyPageArr(Fan_page* dest, Fan_page* src);
	void shiftBackMemberArr(int index);
	void showStatuses();
	void showAllFriends();
	void showName();
	void showAllStatuses();
};








#endif

