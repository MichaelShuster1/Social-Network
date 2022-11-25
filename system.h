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
	void unLinkFriends(int index1, int index2); //not working for the meantime
	void addFanToAPage(int index1,int index2);
	void removeAFanFromAFanPage();
	void printAllRegisteredEntities();
	void printAllFriendsOfMember(int index);
	void printAllFandsOfPage(int index);
	bool checkIfExistNameUser(char* name);
	bool checkIfExistNamePage(char* name);
	void printAllSystemMembers();
	void printAllSystemPages();
	void printMemberName(int index);
	void printPageName(int index);

};

void copyMemberArr(Member** dest, Member** src, int size);
void reSizeMemberArr(Member*** member_array, int old_size, int new_size);
void addNewUserToSystem(System& system);
int getMin(int num1, int num2);
void copyPageArr(Fan_page** dest, Fan_page** src, int size);
void reSizePagesArr(Fan_page*** page_array, int old_size, int new_size);
void addNewPageToSystem(System& system);
void printAllSysMembers(Member** Users, int size);
void printAllSysPages(Fan_page** Pages, int size);
void printAllRegisteredEntitiesInSystem(System& system);
int chooseOneMember(System& system);
int chooseOnePage(System& system);
void freeMemberArr(Member** Users, int size);
void freePageArr(Fan_page** Pages, int size);
void linkFriends(Member& mem1, Member& mem2);
void unlinkFriends(Member& mem1, Member& mem2);
void printAllFriendsOrFansEntity(System& system);
void linkFanToPage(Member& mem, Fan_page& page);
void unlinkFanFromPage(Member& mem, Fan_page& page);
Status* createNewStatus();
void addNewStatusToFanPageOrMember(System& system);
void showAllStatusesOfAFanPageOrMember(System& system);
void ShowTenStatusesOfEachFriend(System& system);
void linkFriendshipInSystem(System& system);
void unLinkFriendshipInSystem(System& system);
void addFanToPageInSystem(System& system);
void removeFanFromPageInSystem(System& system);
void printMenu();
void createHardcodedEntities(Member** System_Members, Fan_page** System_Pages);

#endif // !SYSTEM_H
