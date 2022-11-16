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
	Member** friends;
	int numOfFriends;
	int numOfStatuses;
	int numOfPages;

public:
	Member(const char* name=nullptr);
	Member(const Member& other);
	~Member();
	void addFriend(Member& _member);
	void removeFriend(Member& _member);
	void add_status(const Status& status);
	void reSizeStatusArr(Status** status_array, int old_size, int new_size);
	void reSizeMemberArr(Member*** member_array, int old_size, int new_size);
	void copyStatusArr(Status* dest, Status* src,int size);
	void copyMemberArr(Member** dest, Member** src,int size);
	void copyPageArr(Fan_page* dest, Fan_page* src,int size);
	int getMin(int num1, int num2);
	void shiftBackMemberArr(int index);
	void showStatuses();
	void showAllFriends();
	void showName();
	void showAllStatuses();
};








#endif

