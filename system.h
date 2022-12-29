#ifndef SYSTEM_H
#define SYSTEM_H

#include "member.h"
#include "page.h"
#include "exceptions.h"
#include <string.h>
#include <ctime>


class System
{

private:

	list<Fan_page> system_pages;
	list<Member> system_members;

	void createHardcodedEntities();//adds hardcoded members, fan pages, statuses and friendship/fans connections to the system

public:
	System();//system class c'tor
	System(const System& other) = delete;//system class copy c'tor disable
	void addNewUser(const Member& new_user) noexcept(false);//adds the given member to the system
	void addNewPage(const Fan_page& new_page) noexcept(false);// adds the given fan page to the system
	void addNewStatusToMember(Status& new_status, const string& name) noexcept(false);//adds the given status to a member 
	void addNewStatusToFanPage(Status& new_status,const string& name) noexcept(false);//adds the given status to a fan page
	void showAllStatusesOfAMember(const string& name) const noexcept(false);//prints all statuses of a member
	void showAllStatusesOfAFanPage(const string& name) const noexcept(false); //prints all statuses of a fan page
	void addFanToAPage(const string& name_page, const string& name_member) noexcept(false);//adds a fan to a page and vice versa
	void removeFanFromAFanPage(const string& name_page, const string& name_member) noexcept(false); //remove the member in 'index2' in system members from the fans array of the fan page in 'index1'
	void printAllFandsOfPage(const string& name) const noexcept(false);//prints all the fans of the page located in the 'index' index in system pages
	void ShowTenLatestStatusesOfEachFriend(const string& name) const noexcept(false);//// prints 10 last statuses of each friend of the member located in the 'index' index in system members
	void linkFriends(const string& name1, const string& name2) noexcept(false);//add the member in 'index1' in system members to the friends of the member in 'index2' and vice versa
	void unLinkFriends(const string& name1, const string& name2) noexcept(false);//remove the member in 'index1' in system members from the friends of the member in 'index2' and vice versa
	void printAllFriendsOfMember(const string& name) const noexcept(false);//print all friends of the member located  in the 'index' index is system members
	void printAllSystemMembers() const;//prints all the members in the system
	void printAllSystemPages() const;//prints all the pages in the system
	int getMembersSize() const;//returs the size of the members array
	int getPagesSize() const;//return the size of the fan pages array
};  





#endif // !SYSTEM_H
