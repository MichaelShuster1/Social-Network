#ifndef SYSTEM_H
#define SYSTEM_H

#define new DBG_NEW

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "member.h"
#include "page.h"
#include <string.h>
#include <ctime>

const int NAME_LEN = 100;
const int STATUS_LEN = 254;
const int FIRST_SIZE = 3;



class System
{

private:

	list<Fan_page> system_pages;
	list<Member> system_members;

	void createHardcodedEntities();//adds hardcoded members, fan pages, statuses and friendship/fans connections to the system

public:
	System();//system class c'tor
	System(const System& other) = delete;//system class copy c'tor disable
	void addNewUser(const Member& new_user) throw(const char*);//adds the given member to the system
	void addNewPage(const Fan_page& new_page) throw(const char*);// adds the given fan page to the system
	void addNewStatusToFanPage(Status& new_status,int index);//adds the given status to a fan page located in the 'index' index in system pages
	void addNewStatusToMember(Status& new_status, const string& name);//adds the given status to a member located in the 'index' index in system members
	void addNewStatusToFanPage(Status& new_status,const string& name);//adds the given status to a fan page located in the 'index' index in system pages
	void addNewStatusToMember(Status& new_status, int index);//adds the given status to a member located in the 'index' index in system members
	void showAllStatusesOfAFanPage(const string& name) const;//prints all statuses of a fan page
	void showAllStatusesOfAMember(const string& name) const;//prints all statuses of a member
	void addFanToAPage(const string& name_page, const string& name_member) throw(const char*);//add the member in 'index2' in system members to the fans array of the fan page in 'index1'
	void removeFanFromAFanPage(const string& name_page, const string& name_member) throw(const char*); //remove the member in 'index2' in system members from the fans array of the fan page in 'index1'
	void printAllFandsOfPage(const string& name) const throw(const char*);//prints all the fans of the page located in the 'index' index in system pages
	void ShowTenLatestStatusesOfEachFriend(const string& name) const throw(const char*);//// prints 10 last statuses of each friend of the member located in the 'index' index in system members
	void linkFriends(const string& name1, const string& name2) throw(const char*);//add the member in 'index1' in system members to the friends of the member in 'index2' and vice versa
	void unLinkFriends(const string& name1, const string& name2) throw (const char*);//remove the member in 'index1' in system members from the friends of the member in 'index2' and vice versa
	void printAllFriendsOfMember(const string& name) const throw (const char*);//print all friends of the member located  in the 'index' index is system members
	bool checkIfExistNameUser(const char* name);//check if there is a member with the given name in the system
	bool checkIfExistNamePage(const char* name);//check if there is a fan page with the given name in the system
	void printAllSystemMembers() const;//prints all the members in the system
	void printAllSystemPages() const;//prints all the pages in the system
	int getMembersSize() const;//returs the size of the members array
	int getPagesSize() const;//return the size of the fan pages array
	int getFansSizeofAPage(const string& name) const throw(const char*);//return the size of the fans array of the fan page located in the 'index' index in the system pages
	int getFriendsSizeOfAMember(const string& name) const;//return the size of the friends array of the member located in the 'index' index in system members	
};  





#endif // !SYSTEM_H
