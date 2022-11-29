#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "system.h"
using namespace std;


System::System()
{
	members_size = 3;
	pages_size = 3;
	members_physical_size = 3;
	pages_physical_size = 3;
	system_members = new Member * [members_physical_size];
	system_pages = new Fan_page * [pages_physical_size];
	createHardcodedEntities();
}


System::~System()
{
	freeMemberArr();
	freePageArr();
	_CrtDumpMemoryLeaks();
}


void System::addNewUser(Member* new_user)
{
	if (members_size == members_physical_size)
	{
		members_physical_size *= 2;
		reSizeMemberArr(&system_members,members_size, members_physical_size);
	}
	system_members[members_size] = new_user;
	members_size++;

}

bool System::checkIfExistNameUser(char* name)
{
	for (int i = 0; i < members_size; i++)
	{
		if (strcmp(name, system_members[i]->getName()) == 0)
			return true;
	}
	return false;
}

void System::addNewPage(Fan_page* new_page)
{
	if (pages_size == pages_physical_size)
	{
		pages_physical_size *= 2;
		reSizePagesArr(&system_pages, pages_size, pages_physical_size);
	}
	system_pages[pages_size] = new_page;
	pages_size++;
}


bool System::checkIfExistNamePage(char* name)
{
	for (int i = 0; i < pages_size; i++)
	{
		if (strcmp(name, system_pages[i]->getName()) == 0)
			return true;
	}
	return false;
}

void System::addNewStatusToMember(Status* new_status,int index)
{
	system_members[index]->add_status(*new_status);
}


void System::printAllSystemMembers() const
{
	cout << "the Members:" << endl;
	for (int i = 0; i < members_size; i++)
	{
		cout << (i + 1) << ". ";
		system_members[i]->showName();
		cout << endl;
	}
}

int System::printLinkOptions(int index)
{
	int numofoptions = 0;
	cout << "the Members:" << endl;
	for (int i = 0; i < members_size; i++)
	{
		if ((index != i)  && (areFriendsCheck(index,i) == false))
		{
			cout << (numofoptions + 1) << ". ";
			system_members[i]->showName();
			cout << endl;
			numofoptions++;
		}
	}

	return numofoptions;
}

int System::findLinkOption(int index1, int index2)
{
	int notfriends = 0, i = 0;

	while (notfriends < index2)
	{
		if ((index1 != i) && (areFriendsCheck(index1, i) == false))
		{
			notfriends++;
		}

		i++;
	}

	return i - 1;
}

void System::printAllSystemPages() const
{
	cout << "the Fan pages:" << endl;
	for (int i = 0; i < pages_size; i++)
	{
		cout << (i + 1) << ". ";
		system_pages[i]->showName();
		cout << endl;
	}
}


void System::addNewStatusToFanPage(Status* new_status, int index)
{
	system_pages[index]->add_status(*new_status);
}


void System::showAllStatusesOfAMember(int index) const
{
	system_members[index]->showAllStatuses();
}


void System::showAllStatusesOfAFanPage(int index) const
{
	system_pages[index]->showAllStatuses(); 
}


void System::ShowTenLatestStatusesOfEachFriend(int index) const
{
	system_members[index]->showAllFriendsTenStatuses();
}


void System::linkFriends(int index1, int index2)
{
	system_members[index1]->addFriend(*(system_members[index2]));
}


void System::unLinkFriends(int index1, int index2)
{
	Member* selected_friend;
	selected_friend = system_members[index1]->getMemberFromFriends(index2);
	selected_friend->removeFriend(*system_members[index1]);
}


void System::addFanToAPage(int index1, int index2)
{
	system_members[index1]->add_page(*(system_pages[index2]));
}


void System::removeFanFromAFanPage(int index1, int index2)
{
	Member* selected_friend;
	selected_friend = system_pages[index1]->getfanFromFans(index2);
	selected_friend->removePage(*system_pages[index1]);
}

void System::printMemberName(int index) const
{
	system_members[index]->showName();
}


void System::printPageName(int index) const
{
	system_pages[index]->showName();
}


void System::printAllFriendsOfMember(int index) const
{
	system_members[index]->showAllFriends();
}


void System::printAllFandsOfPage(int index) const
{
	system_pages[index]->show_all_fans();
}


void System::createHardcodedEntities()
{
	system_members[0] = new Member("Avi Cohen", Date(1990, 10, 22));
	system_members[1] = new Member("Yossi Levi", Date(1995, 1, 10));
	system_members[2] = new Member("Israel Israeli", Date(2000, 2, 28));
	system_pages[0] = new Fan_page("Music fans");
	system_pages[1] = new Fan_page("Gaming fans");
	system_pages[2] = new Fan_page("Movies fans");
	Status* status1 = new Status("status1", "Mon Jul 16 02:03:55 2021");
	Status* status2 = new Status("status2", "Mon Jul 17 02:03:55 2021");
	Status* status3 = new Status("status3", "Mon Jul 18 02:03:55 2022");
	Status* status4 = new Status("status4", "Mon Jul 19 02:03:55 2022");
	Status* status5 = new Status("status5", "Mon Jul 20 02:03:55 2022");
	Status* status6 = new Status("status6", "Mon Jul 21 02:03:55 2022");
	system_members[0]->add_status(*status1);
	system_members[0]->add_status(*status2);
	system_members[1]->add_status(*status3);
	system_members[1]->add_status(*status4);
	system_members[2]->add_status(*status5);
	system_members[2]->add_status(*status6);
	Status* status7 = new Status("status7", "Mon Jul 16 02:03:55 2019");
	Status* status8 = new Status("status8", "Mon Jul 17 02:03:55 2019");
	Status* status9 = new Status("status9", "Mon Jul 18 02:03:55 2020");
	Status* status10 = new Status("status10", "Mon Jul 19 02:03:55 2020");
	Status* status11 = new Status("status11", "Mon Jul 20 02:03:55 2021");
	Status* status12 = new Status("status12", "Mon Jul 21 02:03:55 2022");
	system_pages[0]->add_status(*status7);
	system_pages[0]->add_status(*status8);
	system_pages[1]->add_status(*status9);
	system_pages[1]->add_status(*status10);
	system_pages[2]->add_status(*status11);
	system_pages[2]->add_status(*status12);
	addFanToAPage(0, 0);
	addFanToAPage(1, 1);
	linkFriends(0, 1);
	linkFriends(1, 2);
}

void System::copyMemberArr(Member** dest, Member** src, int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];

}


void System::reSizeMemberArr(Member*** member_array, int old_size, int new_size)
{
	Member** temp = new Member * [new_size];
	copyMemberArr(temp, *member_array, getMin(old_size, new_size));
	delete[](*member_array);
	(*member_array) = temp;
}


void System::copyPageArr(Fan_page** dest, Fan_page** src, int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];

}


void System::reSizePagesArr(Fan_page*** page_array, int old_size, int new_size)
{
	Fan_page** temp = new Fan_page * [new_size];
	copyPageArr(temp, *page_array, getMin(old_size, new_size));
	delete[](*page_array);
	(*page_array) = temp;
}


int System::getMin(int num1, int num2) const
{
	if (num1 < num2)
		return num1;
	return num2;
}

int System::getFriendsSizeOfAMember(int index) const
{
	return system_members[index]->getFriendsSize();
}

int System::getFansSizeofAPage(int index) const
{
	return system_pages[index]->getFansSize();
}


void System::freeMemberArr()
{
	for (int i = 0; i < members_size; i++)
		delete system_members[i];

	delete[] system_members;
}


void System::freePageArr()
{
	for (int i = 0; i < pages_size; i++)
		delete system_pages[i];

	delete[] system_pages;
}


int System::getMembersSize() const
{
	return members_size;
}

int System::getPagesSize() const
{
	return pages_size;
}

bool System::areFriendsCheck(int index1, int index2)
{
	int friends_size = system_members[index1]->getFriendsSize();
	for (int i = 0; i <friends_size; i++)
	{
		if (system_members[index2] == system_members[index1]->getMemberFromFriends(i))
			return true;
	}

	return false;
}

bool System::isFanCheck(int index1, int index2)
{
	int fans_size = system_pages[index1]->getFansSize();
	for (int i = 0; i < fans_size; i++)
	{
		if (system_members[index2] == system_pages[index1]->getfanFromFans(i))
			return true;
	}

	return false;
}



