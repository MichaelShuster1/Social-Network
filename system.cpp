#include "system.h"
using namespace std;


System::System()
{
	system_pages.reserve(FIRST_SIZE);
	system_members.reserve(FIRST_SIZE);
	createHardcodedEntities();
}

System::~System()
{
	auto itrEnd1 = system_pages.end();
	auto itrEnd2 = system_members.end();

	for (auto itr = system_pages.begin(); itr != itrEnd1; ++itr)
		delete (*itr);

	for (auto itr = system_members.begin(); itr != itrEnd2; ++itr)
		delete (*itr);
}

void System::addNewUser(Member new_user) throw(const char*)
{
	if(checkIfExistNameUser(new_user.getName()))
	{
		throw "the name is already taken!";
	}
	if (system_members.size() == system_members.capacity())
	{
		system_members.reserve(system_members.capacity() * INCREASE_RATE);
	}

	system_members.push_back(new Member(new_user));	
}


bool System::checkIfExistNameUser(const char* name)
{
	auto itr = system_members.begin();
	auto itrEnd = system_members.end();
	for (; itr != itrEnd; ++itr)
	{
		if (strcmp(name, (*itr)->getName()) == 0)
			return true;
	}
	return false;
	/*int members_size = system_members.size();
	for (int i = 0; i < members_size; i++)
	{
		if (strcmp(name,system_members[i].getName()) == 0)
			return true;
	}
	return false;*/
}


void System::addNewPage(const Fan_page& new_page) throw(const char*)
{
	if ( checkIfExistNamePage(new_page.getName()) )
	{
		throw "the name is already taken!";
	}
	if (system_pages.size() == system_pages.capacity())
		system_pages.reserve(system_pages.capacity() * INCREASE_RATE);

	system_pages.push_back(new Fan_page(new_page));
}


bool System::checkIfExistNamePage(const char* name)
{
	auto itrEnd = system_pages.end();
	for(auto itr = system_pages.begin(); itr!=itrEnd; ++itr )
	{
		if(strcmp(name,(*itr)->getName())==0)
			return true;
	}
	return false;
    /*
	int pages_size = system_pages.size();
	for (int i = 0; i < pages_size; i++)
	{
		if (strcmp(name, system_pages[i].getName()) == 0)
			return true;
	}
	*/
}

void System::addNewStatusToMember(Status& new_status,int index)
{
	auto itr = system_members.begin();
	advance(itr, index);
	(*itr)->addStatus(new_status);
}


void System::printAllSystemMembers() const
{
	auto itr = system_members.begin();
	auto itrEnd = system_members.end();
	int i = 1;
	for (; itr != itrEnd; ++itr, i++)
	{
		cout << i << ". ";
		(*itr)->showName();
		cout << endl;
	}

	/*int members_size = system_members.size();
	cout << "The members:" << endl;
	for (int i = 0; i < members_size; i++)
	{
		cout << (i + 1) << ". ";
		system_members[i].showName();
		cout << endl;
	}*/
}


void System::printAllSystemPages() const
{
	int i = 1;
	auto itrEnd = system_pages.end();
    cout << "The fan pages:" << endl;
	for(auto itr=system_pages.begin(); itr!=itrEnd;++itr)
	{
		cout << i << ". ";
		(*itr)->showName();
		cout << endl;
		i++;
	}

	/*
	int pages_size = system_pages.size();
	cout << "The fan pages:" << endl;
	for (int i = 0; i < pages_size; i++)
	{
		cout << (i + 1) << ". ";
		system_pages[i].showName();
		cout << endl;
	}
	*/
}


void System::addNewStatusToFanPage(Status& new_status, int index)
{
	auto itr = system_pages.begin();
	advance(itr, index);
	(*itr)->addStatus(new_status);
	//system_pages[index].addStatus(new_status);
}


void System::showAllStatusesOfAMember(int index) const
{
	auto itr = system_members.begin();
	advance(itr, index);

	(*itr)->showName();
	cout << "'s statuses are:" << endl;
	(*itr)->showAllStatuses();
	/*system_members[index].showName();
	cout << "'s statuses are:" << endl;
	system_members[index].showAllStatuses();*/
}


void System::showAllStatusesOfAFanPage(int index) const
{
    auto itr = system_pages.begin();
	advance(itr, index);
	(*itr)->showName();
	cout << "'s statuses are:" << endl;
	(*itr)->showAllStatuses(); 
	
	/*
	system_pages[index].showName();
	cout << "'s statuses are:" << endl;
	system_pages[index].showAllStatuses(); 
	*/
}


void System::ShowTenLatestStatusesOfEachFriend(int index) const
{
	auto itr = system_members.begin();
	advance(itr, index);
	(*itr)->showAllFriendsTenStatuses();


	//system_members[index].showAllFriendsTenStatuses();
}


void System::linkFriends(int index1, int index2) throw(const char*)
{
	if (index1 == index2)
		throw "error: you cant link a member with himself!";
	auto itr1 = system_members.begin();
	auto itr2 = itr1;
	advance(itr1, index1);
	advance(itr2, index2);

	if ((*itr1)->areFriendsCheck((*(*itr2))))
		throw "error: the members you chose are already linked!";

	/*if (areFriendsCheck(index1, index2))
		throw "error: the members you chose are already linked!";*/
	
	(*(*itr1)) += (*(*itr2));

	//system_members[index1]+=system_members[index2];
}


void System::unLinkFriends(int index1, int index2)
{
	auto itr1 = system_members.begin();
	auto itr2 = itr1;
	advance(itr1, index1);
	advance(itr2, index2);
	Member* selected_friend = (*itr1)->getMemberFromFriends(index2);
	selected_friend->removeFriend((*(*itr2)));


	/*selected_friend = system_members[index1].getMemberFromFriends(index2);
	selected_friend->removeFriend(system_members[index1]);*/
}


void System::addFanToAPage(int index1, int index2) throw(const char*)
{
    auto itr1 = system_members.begin();
	auto itr2 = system_pages.begin();
	advance(itr1, index1);
	advance(itr2, index2);
	if ((*itr2)->isFanCheck( (*(*itr1))) )
	{
		throw "error:The user you chose is already a fan of this page!";
	}
	(*(*itr2)) += (*(*itr1));
	//system_pages[index2]+=system_members[index1];
}


void System::removeFanFromAFanPage(int index1, int index2)
{
	Member* selected_friend;
	auto itr=system_pages.begin();
	advance(itr, index1);
	selected_friend = (*itr)->getfanFromFans(index2);
	selected_friend->removePage( (*(*itr)) );

	/*
	selected_friend = system_pages[index1].getfanFromFans(index2);
	selected_friend->removePage(system_pages[index1]);
	*/
}


void System::printAllFriendsOfMember(int index) const
{
	auto itr = system_members.begin();
	advance(itr, index);
	(*itr)->showAllFriends();

	//system_members[index].showAllFriends();
}


void System::printAllFandsOfPage(int index) const
{
	auto itr=system_pages.begin();
	advance(itr, index);
	(*itr)->showAllFans();
}


void System::createHardcodedEntities()
{
	system_members.push_back(new Member("Avi Cohen", Date(1990, 10, 22)));
	system_members.push_back(new Member("Yossi Levi", Date(1995, 1, 10)));
	system_members.push_back(new Member("Israel Israeli", Date(2000, 2, 28)));
	system_pages.push_back(new Fan_page("Music fans"));
	system_pages.push_back(new Fan_page("Gaming fans"));
	system_pages.push_back(new Fan_page("Movies fans"));
	Status status1("status1", "Mon Jul 16 02:03:55 2021");
	Status status2("status2", "Mon Jul 17 02:03:55 2021");
	Status status3("status3", "Mon Jul 18 02:03:55 2022");
	Status status4("status4", "Mon Jul 19 02:03:55 2022");
	Status status5("status5", "Mon Jul 20 02:03:55 2022");
	Status status6("status6", "Mon Jul 21 02:03:55 2022");
	auto itrMember = system_members.begin();
	(*itrMember)->addStatus(status1);
	(*itrMember)->addStatus(status2);
	++itrMember;
	(*itrMember)->addStatus(status3);
	(*itrMember)->addStatus(status4);
	++itrMember;
	(*itrMember)->addStatus(status5);
	(*itrMember)->addStatus(status6);
	Status status7("status7", "Mon Jul 16 02:03:55 2019");
	Status status8("status8", "Mon Jul 17 02:03:55 2019");
	Status status9("status9", "Mon Jul 18 02:03:55 2020");
	Status status10("status10", "Mon Jul 19 02:03:55 2020");
	Status status11("status11", "Mon Jul 20 02:03:55 2021");
	Status status12("status12", "Mon Jul 21 02:03:55 2022");
	auto itrPage = system_pages.begin();
	(*itrPage)->addStatus(status7);
	(*itrPage)->addStatus(status8);
	itrPage++;
	(*itrPage)->addStatus(status9);
	(*itrPage)->addStatus(status10);
	itrPage++;
	(*itrPage)->addStatus(status11);
	(*itrPage)->addStatus(status12);

	
	addFanToAPage(0, 0);
	addFanToAPage(1, 1);
	linkFriends(0, 1);
	linkFriends(1, 2);
}






int System::getFriendsSizeOfAMember(int index) const
{
	auto itr = system_members.begin();
	advance(itr, index);
	return (*itr)->getFriendsSize();

	//return system_members[index].getFriendsSize();
}

int System::getFansSizeofAPage(int index) const
{
    auto itr=system_pages.begin();
	advance(itr, index);
	return (*itr)->getFansSize();
}


int System::getMembersSize() const
{
	return system_members.size();
}

int System::getPagesSize() const
{
	return system_pages.size();
}

//
//bool System::areFriendsCheck(int index1, int index2)
//{
//	int friends_size = system_members[index1].getFriendsSize();
//	for (int i = 0; i <friends_size; i++)
//	{
//		if (&system_members[index2] == (system_members[index1].getMemberFromFriends(i)))
//			return true;
//	}
//
//	return false;
//}

/*
bool System::isFanCheck(int index1, int index2)
{
	int fans_size = system_pages[index1].getFansSize();
	for (int i = 0; i < fans_size; i++)
	{
		if (&system_members[index2] == system_pages[index1].getfanFromFans(i))
			return true;
		system_pages[index1].isFanCheck(&system_members[index2]);
	}

	return false;
}
*/

