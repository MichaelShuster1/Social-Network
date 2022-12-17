#ifndef SYSTEM_H
#define SYSTEM_H

#include "member.h"
#include "page.h"
#include <string.h>
#include <ctime>

const int NAME_LEN = 100;
const int STATUS_LEN = 254;



class System
{

private:

	vector<Fan_page> system_pages;
	vector<Member> system_members;

	void createHardcodedEntities();//adds hardcoded members, fan pages, statuses and friendship/fans connections to the system

public:
	System();//system class c'tor
	~System();//system class d'tor
	System(const System& other) = delete;//system class copy c'tor disable
	void addNewUser(Member new_user) throw(const char*);//adds the given member to the system
	void addNewPage(const Fan_page& new_page) throw(const char*);// adds the given fan page to the system
	void addNewStatusToFanPage(Status& new_status,int index);//adds the given status to a fan page located in the 'index' index in system pages
	void addNewStatusToMember(Status& new_status, int index);//adds the given status to a member located in the 'index' index in system members
	void showAllStatusesOfAFanPage(int index) const;//prints all statuses of a fan page
	void showAllStatusesOfAMember(int index) const;//prints all statuses of a member
	void ShowTenLatestStatusesOfEachFriend(int index) const;//// prints 10 last statuses of each friend of the member located in the 'index' index in system members
	void linkFriends(int index1,int index2) throw(const char*);//add the member in 'index1' in system members to the friends of the member in 'index2' and vice versa
	void unLinkFriends(int index1, int index2);//remove the member in 'index1' in system members from the friends of the member in 'index2' and vice versa
	void addFanToAPage(int index1,int index2)  throw(const char*);//add the member in 'index2' in system members to the fans array of the fan page in 'index1'
	void removeFanFromAFanPage(int index1,int index2); //remove the member in 'index2' in system members from the fans array of the fan page in 'index1'
	void printAllFriendsOfMember(int index) const;//print all friends of the member located  in the 'index' index is system members
	void printAllFandsOfPage(int index) const;//prints all the fans of the page located in the 'index' index in system pages
	bool checkIfExistNameUser(const char* name);//check if there is a member with the given name in the system
	bool checkIfExistNamePage(const char* name);//check if there is a fan page with the given name in the system
	void printAllSystemMembers() const;//prints all the members in the system
	void printAllSystemPages() const;//prints all the pages in the system
	int getMembersSize() const;//returs the size of the members array
	int getPagesSize() const;//return the size of the fan pages array
	int getFriendsSizeOfAMember(int index) const;//return the size of the friends array of the member located in the 'index' index in system members
	int getFansSizeofAPage(int index) const;//return the size of the fans array of the fan page located in the 'index' index in the system pages
	bool areFriendsCheck(int index1, int index2);//checks if the members located in 'index1' and 'index2' in system members ara friends
	bool isFanCheck(int index1, int index2);//checks if the member located in the 'index2' index in system members is a fan of the page located in 'index1' index in system pages
};



#endif // !SYSTEM_H
