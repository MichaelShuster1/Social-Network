#ifndef SYSTEM_H
#define SYSTEM_H

#include "member.h"
#include "page.h"
#include <string.h>
#include <ctime>

const int NAME_LEN = 100;


class System
{

private:
	Member** system_members;
	Fan_page** system_pages;
	int members_size;
	int members_physical_size;
	int pages_size;
	int pages_physical_size;

public:
	System();
	~System();
	System(const System& other) = delete;
	void addNewUser(Member* new_user);
	void addNewPage(Fan_page* new_page);
	void addNewStatusToFanPage(Status* new_status,int index);
	void addNewStatusToMember(Status* new_status,int index);
	void showAllStatusesOfAFanPage(int index);
	void showAllStatusesOfAMember(int index);
	void ShowTenLatestStatusesOfEachFriend(int index);
	void linkFriends(int index1,int index2);
	void unLinkFriends(int index1, int index2); 
	void addFanToAPage(int index1,int index2);
	void removeFanFromAFanPage(int index1,int index2);  
	void printAllFriendsOfMember(int index);
	void printAllFandsOfPage(int index);
	bool checkIfExistNameUser(char* name);
	bool checkIfExistNamePage(char* name);
	void printAllSystemMembers();
	void printAllSystemPages();
	void printMemberName(int index);
	void printPageName(int index);
	void copyPageArr(Fan_page** dest, Fan_page** src, int size);
	void reSizePagesArr(Fan_page*** page_array, int old_size, int new_size);
	void copyMemberArr(Member** dest, Member** src, int size);
	void reSizeMemberArr(Member*** member_array, int old_size, int new_size);
	int  getMin(int num1, int num2);
	void createHardcodedEntities();
	void freeMemberArr();
	void freePageArr();
	int getMembersSize();
	int getPagesSize();
	int getFriendsSizeOfAMember(int index);
	int getFansSizeofAPage(int index);
};



#endif // !SYSTEM_H
