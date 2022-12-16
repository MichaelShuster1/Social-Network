#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "system.h"
using namespace std;


System::System()
{
	members_size = 3;
	system_pages.reserve(3);
	members_physical_size = 3;
	system_members = new Member * [members_physical_size];
	system_members.reserve(3);
	pages_size = 3;
	/*members_physical_size = 3;*/
	pages_physical_size = 3;
	/*system_members = new Member * [members_physical_size];*/
	system_pages = new Fan_page * [pages_physical_size];
	createHardcodedEntities();

}


System::~System()
{
	freeMemberArr();
	_CrtDumpMemoryLeaks();
}


void System::addNewUser(Member* new_user)
{
	if (system_members.size() == system_members.capacity())
	{
		system_members.reserve(system_members.capacity() * 2);
	}
	system_members.push_back(*new_user);
	/*if (members_size == members_physical_size)
	{
		members_physical_size *= 2;
		reSizeMemberArr();
	}
	system_members[members_size] = new_user;
	members_size++;*/

}


bool System::checkIfExistNameUser(char* name)
{
	int members_size = system_members.size();
	for (int i = 0; i < members_size; i++)
	{
		/*if (strcmp(name, system_members[i]->getName()) == 0)
			return true;*/
		if (name == system_members[i].getName())
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
	system_members[index]->addStatus(new_status);
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


void System::linkFriends(int index1, int index2)
{
	//system_members[index1]->addFriend(*(system_members[index2]));
	(system_members[index1])+=((system_members[index2]));
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
	system_pages[index2]+=(*system_members[index1]);
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
	system_pages[0] = new Fan_page("Music fans");
	system_pages[1] = new Fan_page("Gaming fans");
	system_pages[2] = new Fan_page("Movies fans");
	system_members[0] = new Member("Avi Cohen", Date(1990, 10, 22));
	system_members[1] = new Member("Yossi Levi", Date(1995, 1, 10));
	system_members[2] = new Member("Israel Israeli", Date(2000, 2, 28));
	system_pages.push_back(Fan_page("Music fans"));
	system_pages.push_back(Fan_page("Gaming fans"));
	system_pages.push_back(Fan_page("Movies fans"));
	Status* status1 = new Status("status1", "Mon Jul 16 02:03:55 2021");
	Status* status2 = new Status("status2", "Mon Jul 17 02:03:55 2021");
	Status* status3 = new Status("status3", "Mon Jul 18 02:03:55 2022");
	Status* status4 = new Status("status4", "Mon Jul 19 02:03:55 2022");
	Status* status5 = new Status("status5", "Mon Jul 20 02:03:55 2022");
	Status* status6 = new Status("status6", "Mon Jul 21 02:03:55 2022");
	system_members[0].addStatus(*status1);
	system_members[0].addStatus(*status2);
	system_members[1].addStatus(*status3);
	system_members[1].addStatus(*status4);
	system_members[2].addStatus(*status5);
	system_members[2].addStatus(*status6);
	Status* status7 = new Status("status7", "Mon Jul 16 02:03:55 2019");
	Status* status8 = new Status("status8", "Mon Jul 17 02:03:55 2019");
	Status* status9 = new Status("status9", "Mon Jul 18 02:03:55 2020");
	Status* status10 = new Status("status10", "Mon Jul 19 02:03:55 2020");
	Status* status11 = new Status("status11", "Mon Jul 20 02:03:55 2021");
	Status* status12 = new Status("status12", "Mon Jul 21 02:03:55 2022");
	system_pages[0].addStatus(*status7);
	system_pages[0].addStatus(*status8);
	system_pages[1].addStatus(*status9);
	system_pages[1].addStatus(*status10);
	system_pages[2].addStatus(*status11);
	system_pages[2].addStatus(*status12);
	addFanToAPage(0, 0);
	addFanToAPage(1, 1);
	linkFriends(0, 1);
	linkFriends(1, 2);
}
//
//void System::copyMemberArr(Member** dest)
//{
//	int i;
//	int members_size = system_members.size();
//	for (i = 0; i < members_size; i++)
//		dest[i] = system_members[i];
//
//}
//
//
//void System::reSizeMemberArr()
//{
//	Member** temp = new Member * [members_physical_size];
//	copyMemberArr(temp);
//	delete[] system_members;
//	system_members = temp;
//}


void System::copyPageArr(Fan_page** dest)
{
	int i;
	for (i = 0; i < pages_size; i++)
		dest[i] = system_pages[i];

}




int System::getFriendsSizeOfAMember(int index) const
{
	return system_members[index].getFriendsSize();
}

int System::getFansSizeofAPage(int index) const
{
	return system_pages[index].getFansSize();
}

//
//void System::freeMemberArr()
//{
//	int members_size = system_members.size();
//	for (int i = 0; i < members_size; i++)
//		delete system_members[i];
//
//	//delete[] system_members;
//}


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
		if (system_members[index2] == system_pages[index1].getfanFromFans(i))
			return true;
	}

	return false;
}



