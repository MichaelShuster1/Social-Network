#include "system.h"
using namespace std;




System::System()
{
	system_pages.reserve(3);
	system_members.reserve(3);
	createHardcodedEntities();
}


System::~System()
{
	_CrtDumpMemoryLeaks();
}


void System::addNewUser(Member new_user) throw(const char*)
{
	if(checkIfExistNameUser(new_user.getName()))
	{
		throw "the name is already taken!";
	}
	if (system_members.size() == system_members.capacity())
	{
		system_members.reserve(system_members.capacity() * 2);
	}

	system_members.push_back(new_user);	
}


bool System::checkIfExistNameUser(const char* name)
{
	int members_size = system_members.size();
	for (int i = 0; i < members_size; i++)
	{
		if (strcmp(name,system_members[i].getName()) == 0)
			return true;
	}
	return false;
}


void System::addNewPage(const Fan_page& new_page) throw(const char*)
{
	if ( checkIfExistNamePage(new_page.getName()) )
	{
		throw "the name is already taken!";
	}
	if (system_pages.size() == system_pages.capacity())
		system_pages.reserve(system_pages.capacity() * 2);

	system_pages.push_back(new_page);
}


bool System::checkIfExistNamePage(const char* name)
{
	int pages_size = system_pages.size();
	for (int i = 0; i < pages_size; i++)
	{
		if (strcmp(name, system_pages[i].getName()) == 0)
			return true;
	}
	return false;
}

void System::addNewStatusToMember(Status& new_status,int index)
{
	system_members[index].addStatus(new_status);
}


void System::printAllSystemMembers() const
{
	int members_size = system_members.size();
	cout << "The members:" << endl;
	for (int i = 0; i < members_size; i++)
	{
		cout << (i + 1) << ". ";
		system_members[i].showName();
		cout << endl;
	}
}


void System::printAllSystemPages() const
{
	int pages_size = system_pages.size();
	cout << "The fan pages:" << endl;
	for (int i = 0; i < pages_size; i++)
	{
		cout << (i + 1) << ". ";
		system_pages[i].showName();
		cout << endl;
	}
}


void System::addNewStatusToFanPage(Status& new_status, int index)
{
	system_pages[index].addStatus(new_status);
}


void System::showAllStatusesOfAMember(int index) const
{
	system_members[index].showName();
	cout << "'s statuses are:" << endl;
	system_members[index].showAllStatuses();
}


void System::showAllStatusesOfAFanPage(int index) const
{
	system_pages[index].showName();
	cout << "'s statuses are:" << endl;
	system_pages[index].showAllStatuses(); 
}


void System::ShowTenLatestStatusesOfEachFriend(int index) const
{
	system_members[index].showAllFriendsTenStatuses();
}


void System::linkFriends(int index1, int index2) throw(const char*)
{
	if (index1 == index2)
		throw "error: you cant link a member with himself!";

	if (areFriendsCheck(index1, index2))
		throw "error: the members you chose are already linked!";
	
	system_members[index1]+=system_members[index2];
}


void System::unLinkFriends(int index1, int index2)
{
	Member* selected_friend;
	selected_friend = system_members[index1].getMemberFromFriends(index2);
	selected_friend->removeFriend(system_members[index1]);
}


void System::addFanToAPage(int index1, int index2) throw(const char*)
{
	if (isFanCheck(index1, index2))
	{
		throw "error:The user you chose is already a fan of this page!";
	}
	system_pages[index2]+=system_members[index1];
}


void System::removeFanFromAFanPage(int index1, int index2)
{
	Member* selected_friend;
	selected_friend = system_pages[index1].getfanFromFans(index2);
	selected_friend->removePage(system_pages[index1]);
}


void System::printAllFriendsOfMember(int index) const
{
	system_members[index].showAllFriends();
}


void System::printAllFandsOfPage(int index) const
{
	system_pages[index].showAllFans();
}


void System::createHardcodedEntities()
{
	system_members.push_back(Member("Avi Cohen", Date(1990, 10, 22)));
	system_members.push_back(Member("Yossi Levi", Date(1995, 1, 10)));
	system_members.push_back(Member("Israel Israeli", Date(2000, 2, 28)));
	system_pages.push_back(Fan_page("Music fans"));
	system_pages.push_back(Fan_page("Gaming fans"));
	system_pages.push_back(Fan_page("Movies fans"));
	Status status1("status1", "Mon Jul 16 02:03:55 2021");
	Status status2("status2", "Mon Jul 17 02:03:55 2021");
	Status status3("status3", "Mon Jul 18 02:03:55 2022");
	Status status4("status4", "Mon Jul 19 02:03:55 2022");
	Status status5("status5", "Mon Jul 20 02:03:55 2022");
	Status status6("status6", "Mon Jul 21 02:03:55 2022");
	system_members[0].addStatus(status1);
	system_members[0].addStatus(status2);
	system_members[1].addStatus(status3);
	system_members[1].addStatus(status4);
	system_members[2].addStatus(status5);
	system_members[2].addStatus(status6);
	Status status7("status7", "Mon Jul 16 02:03:55 2019");
	Status status8("status8", "Mon Jul 17 02:03:55 2019");
	Status status9("status9", "Mon Jul 18 02:03:55 2020");
	Status status10("status10", "Mon Jul 19 02:03:55 2020");
	Status status11("status11", "Mon Jul 20 02:03:55 2021");
	Status status12("status12", "Mon Jul 21 02:03:55 2022");
	system_pages[0].addStatus(status7);
	system_pages[0].addStatus(status8);
	system_pages[1].addStatus(status9);
	system_pages[1].addStatus(status10);
	system_pages[2].addStatus(status11);
	system_pages[2].addStatus(status12);
	addFanToAPage(0, 0);
	addFanToAPage(1, 1);
	linkFriends(0, 1);
	linkFriends(1, 2);
}






int System::getFriendsSizeOfAMember(int index) const
{
	return system_members[index].getFriendsSize();
}

int System::getFansSizeofAPage(int index) const
{
	return system_pages[index].getFansSize();
}


int System::getMembersSize() const
{
	return system_members.size();
}

int System::getPagesSize() const
{
	return system_pages.size();
}

bool System::areFriendsCheck(int index1, int index2)
{
	int friends_size = system_members[index1].getFriendsSize();
	for (int i = 0; i <friends_size; i++)
	{
		if (&system_members[index2] == (system_members[index1].getMemberFromFriends(i)))
			return true;
	}

	return false;
}

bool System::isFanCheck(int index1, int index2)
{
	int fans_size = system_pages[index1].getFansSize();
	for (int i = 0; i < fans_size; i++)
	{
		if (&system_members[index2] == system_pages[index1].getfanFromFans(i))
			return true;
	}

	return false;
}

