#ifndef MEMBER_H
#define MEMBER_H



#include "status.h"

class Fan_page;

class Member
{

private:
	char* name;
	Date birth_date;
	Status** status_array;
	Fan_page** pages;
	Member** friends;
	int numOfFriends;
	int physical_numOfFriends;
	int numOfStatuses;
	int physical_numOfStatuses;
	int numOfPages;
	int physical_numOfPages;


public:
	Member();
	Member(const char* _name,const Date& date);
	Member(const Member& other) = delete;
	~Member();
	void addFriend(Member& _member);//adds a user to the members friends array
	void add_status(Status& status);//adds a status to the members status array
	void add_page(Fan_page& page);//adds a fan page to the members fan pages array
	void removeFriend(Member& _member);//removes a user from the members friends array
	void removePage(Fan_page& page);//removes a page fom the users fan page array
	void reSizeStatusArr(Status*** status_array, int old_size, int new_size);//adds more dynamic allocated memory to the array by copying the current array into a larger array, and then deleting the current array (Status)
	void reSizeMemberArr(Member*** member_array, int old_size, int new_size);//adds more dynamic allocated memory to the array by copying the current array into a larger array, and then deleting the current array (Member)
	void reSizePagesArr(Fan_page*** pages_array, int old_size, int new_size);//adds more dynamic allocated memory to the array by copying the current array into a larger array, and then deleting the current array (Fan_page)
	void copyStatusArr(Status** dest, Status** src,int size);//copies the src array into the dest array (Status)
	void copyMemberArr(Member** dest, Member** src,int size);//copies the src array into the dest array (Member)
	void copyPageArr(Fan_page** dest, Fan_page** src,int size);//copies the src array into the dest array (Page)
	int getMin(int num1, int num2);//returns the minimum of 2 numbers
	void shiftBackMemberArr(int index);//moves each cell of the array one index backwards from the 'index' index (Member)
	void shiftBackPagesArr(int index);//moves each cell of the array one index backwards from the 'index' index (Fan_page)
	void showAllFriends() const ;//prints all friends of a member
	void showAllStatuses() const;//prints all statuses of a member
	void showName() const ;//prints members name
	void showTenRecentStatuses() const ;// prints the last 10 statuses of the member
	void showAllFriendsTenStatuses()const ;// prints 10 last statuses of each friend of the member
	Member* getMemberFromFriends(int i);//return the 'i' friend from the friends array
	const char* getName() const;// returns the members name
	int getFriendsSize() const;//return the friends array size
	int getPagesSize() const;//return the pages array size
	Fan_page* getPageFromPages(int i);//return the 'i' page from the pages array
	int getPageIndexFromPages(Fan_page& page) const;// return the index of the given page in the pages array of the member
	int getFriendIndexFromFriends(Member& member) const ;// return the index of the given member from the friends array of the member
};








#endif

