#include "system.h"
using namespace std;


System::System()
{
	createHardcodedEntities();
}



void System::addNewUser(const Member& new_user) throw(const char*)
{
	if(checkIfExistNameUser(new_user.getName()))
	{
		throw "the name is already taken!";
	}
	/*if (system_members.size() == system_members.capacity())
	{
		system_members.reserve(system_members.capacity() * INCREASE_RATE);
	}*/

	system_members.push_back(Member(new_user));	
}


bool System::checkIfExistNameUser(const char* name)
{
	auto itr = system_members.begin();
	auto itrEnd = system_members.end();
	for (; itr != itrEnd; ++itr)
	{
		if (strcmp(name, (*itr).getName()) == 0)
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
	if ( checkIfExistNamePage(new_page.getName()))
	{
		throw "the name is already taken!";
	}
	system_pages.push_back(Fan_page(new_page));
}


bool System::checkIfExistNamePage(const char* name)
{
	auto itrEnd = system_pages.end();
	for(auto itr = system_pages.begin(); itr!=itrEnd; ++itr )
	{
		if(strcmp(name,(*itr).getName())==0)
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

void System::addNewStatusToMember(Status& new_status,const string& name)
{
	auto itr = findMember(name);
	(*itr).addStatus(new_status);
}


void System::printAllSystemMembers() const
{
	auto itr = system_members.begin();
	auto itrEnd = system_members.end();
	int i = 1;
	for (; itr != itrEnd; ++itr, i++)
	{
		cout << i << ". ";
		(*itr).showName();
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
	for(auto itr=system_pages.begin(); itr!=itrEnd; ++itr,i++)
	{
		cout << i << ". ";
		(*itr).showName();
		cout << endl;
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


void System::addNewStatusToFanPage(Status& new_status,const string& name)
{
	auto itr = system_pages.begin();
	advance(itr, index);
	(*itr).addStatus(new_status);
	//system_pages[index].addStatus(new_status);
}


void System::showAllStatusesOfAMember(const string& name) const
{
	auto itr = find(system_members.begin(),system_members.end(),name);
	//auto itr = findMember(name);
	if (itr != system_members.end())
	{
		(*itr).showName();
		cout << "'s statuses are:" << endl;
		(*itr).showAllStatuses();
	}
	else
		cout << "the user not found!"<<endl;
	/**
	auto itr = system_members.begin();
	advance(itr, index);

	(*itr)->showName();
	cout << "'s statuses are:" << endl;
	(*itr)->showAllStatuses();
	*/

	/*system_members[index].showName();
	cout << "'s statuses are:" << endl;
	system_members[index].showAllStatuses();*/
}


void System::showAllStatusesOfAFanPage(const string& name) const
{
	auto itr = find(system_pages.begin(), system_pages.end(),name);
	if (itr != system_pages.end())
	{
		(*itr).showName();
		cout << "'s statuses are:" << endl;
		(*itr).showAllStatuses();
	}
	else
		cout << "the page was not found!"<<endl;
	
	/*
	system_pages[index].showName();
	cout << "'s statuses are:" << endl;
	system_pages[index].showAllStatuses(); 
	*/
}



void System::ShowTenLatestStatusesOfEachFriend(const string& name) const throw(const char*)
{
	/*auto itr = system_members.begin();
	advance(itr, index);*/
	auto itr = find(system_members.begin(), system_members.end(), name);
	if (itr != system_members.end())
		(*itr).showAllFriendsTenStatuses();
	else
		throw "This user doesn't exist!";


	//system_members[index].showAllFriendsTenStatuses();
}


void System::linkFriends(const string& name1, const string& name2) throw(const char*)
{
	if (name1 == name2)
		throw "error: you cant link a member with himself!";
	/*auto itr1 = system_members.begin();
	auto itr2 = itr1;
	advance(itr1, index1);
	advance(itr2, index2);*/
	auto itr1 = find(system_members.begin(), system_members.end(), name1);
	auto itr2 = find(system_members.begin(), system_members.end(), name2);
    
	if (itr1 == system_members.end())
		throw "error: the first user doesn't exist!";

	if (itr2 == system_members.end()) 
		throw "error: the second user doesn't exist!";
	

	if ((*itr1).areFriendsCheck((*itr2)))
		throw "error: the members you chose are already linked!";

	/*if (areFriendsCheck(index1, index2))
		throw "error: the members you chose are already linked!";*/
	
	*itr1 += *itr2;

	//system_members[index1]+=system_members[index2];
}


void System::unLinkFriends(const string& name1, const string& name2) throw (const char*)
{

	auto itr1 = find(system_members.begin(), system_members.end(), name1);
	auto itr2 = find(system_members.begin(), system_members.end(), name2);

	if (itr1 == system_members.end())
		throw "error: the first user doesn't exist!";

	if (itr2 == system_members.end())
		throw "error: the second user doesn't exist!";

	try
	{
		(*itr1).removeFriend(name2);
	}
	catch (const char*)

	/*Member selected_friend = (*itr1).getMemberFromFriends(name2);
	selected_friend->removeFriend((*(*itr2)));*/


	/*selected_friend = system_members[index1].getMemberFromFriends(index2);
	selected_friend->removeFriend(system_members[index1]);*/
}


void System::addFanToAPage(const string& name_page, const string& name_member) throw(const char*)
{
	auto itr_fan = find(system_members.begin(), system_members.end(), name_member);
	auto itr_page = find(system_pages.begin(), system_pages.end(), name_page);

	if (itr_fan == system_members.end())
		throw "error:the name of fan you entered not exist in the system!";

	if (itr_page == system_pages.end())
		throw "error:the name of page you entered not exist in the system!";

	if ((*itr_page).isFanCheck(*itr_fan))
	{
		throw "error:The user you chose is already a fan of this page!";
	}
	(*itr_page) += (*itr_fan);
	//system_pages[index2]+=system_members[index1];
}


void System::removeFanFromAFanPage(const string& name_page, const string& name_member) throw(const char*)
{
	auto itr_page = find(system_pages.begin(), system_pages.end(), name_page);

	if (itr_page == system_pages.end())
		throw "error: page not found!";

	try
	{
		(*itr_page).deleteFan(name_member);
	}
	catch (const char* msg)
	{
		throw(msg);
	}
	




	/*
	selected_friend = system_pages[index1].getfanFromFans(index2);
	selected_friend->removePage(system_pages[index1]);
	*/
}


void System::printAllFriendsOfMember(const string& name) const throw (const char*)
{
	auto itr = find(system_members.begin(), system_members.end(), name);

	if (itr == system_members.end())
		throw "error: the user doesn't exist!";

	//auto itr = system_members.begin();
	//advance(itr, index);
	(*itr).showAllFriends();

	//system_members[index].showAllFriends();
}


void System::printAllFandsOfPage(const string& name) const throw(const char*) 
{
	auto itr = find(system_pages.begin(), system_pages.end(), name);
	if (itr == system_pages.end())
		throw "error: page not found!";
	(*itr).showAllFans();
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
	auto itrMember = system_members.begin();
	(*itrMember).addStatus(status1);
	(*itrMember).addStatus(status2);
	++itrMember;
	(*itrMember).addStatus(status3);
	(*itrMember).addStatus(status4);
	++itrMember;
	(*itrMember).addStatus(status5);
	(*itrMember).addStatus(status6);
	Status status7("status7", "Mon Jul 16 02:03:55 2019");
	Status status8("status8", "Mon Jul 17 02:03:55 2019");
	Status status9("status9", "Mon Jul 18 02:03:55 2020");
	Status status10("status10", "Mon Jul 19 02:03:55 2020");
	Status status11("status11", "Mon Jul 20 02:03:55 2021");
	Status status12("status12", "Mon Jul 21 02:03:55 2022");
	auto itrPage = system_pages.begin();
	(*itrPage).addStatus(status7);
	(*itrPage).addStatus(status8);
	itrPage++;
	(*itrPage).addStatus(status9);
	(*itrPage).addStatus(status10);
	itrPage++;
	(*itrPage).addStatus(status11);
	(*itrPage).addStatus(status12);

	addFanToAPage("Music fans", "Avi Cohen");
	addFanToAPage("Gaming fans", "Yossi Levi");
	linkFriends("Avi Cohen", "Yossi Levi");
	linkFriends("Yossi Levi", "Israel Israeli");
}


int System::getFriendsSizeOfAMember(const string& name) const
{
	auto itr = find(system_members.begin(), system_members.end(), name);
	/*auto itr = system_members.begin();
	advance(itr, index);*/
	return (*itr).getFriendsSize();

	//return system_members[index].getFriendsSize();
}

int System::getFansSizeofAPage(const string& name) const throw(const char*)
{
	auto itr = find(system_pages.begin(), system_pages.end(), name);
	if (itr == system_pages.end())
		throw "error: page not found!";
	return (*itr).getFansSize();
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

