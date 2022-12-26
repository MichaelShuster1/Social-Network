#include "system.h"
using namespace std;


System::System()
{
	createHardcodedEntities();
}



void System::addNewUser(const Member& new_user) throw(const char*)
{
	auto itr = find(system_members.begin(), system_members.end(), new_user.getName());
	if(itr!=system_members.end())
	{
		throw "the name is already taken!";
	}
	
	system_members.push_back(Member(new_user));	
}


void System::addNewPage(const Fan_page& new_page) throw(const char*)
{
	auto itr = find(system_pages.begin(), system_pages.end(), new_page.getName());
	if (itr!=system_pages.end())
	{
		throw "the name is already taken!";
	}
	system_pages.push_back(Fan_page(new_page));
}


void System::addNewStatusToMember(Status& new_status,const string& name) throw (const char*)
{
	auto itr = find(system_members.begin(), system_members.end(), name);
	if (itr != system_members.end())
		(*itr).addStatus(new_status);
	else
		throw "error: the user doesn't exist!";
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
}


void System::addNewStatusToFanPage(Status& new_status,const string& name) throw (const char*)
{
	auto itr = find(system_pages.begin(),system_pages.end(),name);
	if (itr == system_pages.end())
		throw("page not found!");
	(*itr).addStatus(new_status);
}


void System::showAllStatusesOfAMember(const string& name) const
{
	auto itr = find(system_members.begin(),system_members.end(),name);
	if (itr != system_members.end())
	{
		(*itr).showName();
		cout << "'s statuses are:" << endl;
		(*itr).showAllStatuses();
	}
	else
		cout << "the user not found!"<<endl;
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
}



void System::ShowTenLatestStatusesOfEachFriend(const string& name) const throw(const char*)
{
	auto itr = find(system_members.begin(), system_members.end(), name);
	if (itr != system_members.end())
		(*itr).showAllFriendsTenStatuses();
	else
		throw "This user doesn't exist!";
}


void System::linkFriends(const string& name1, const string& name2) throw(const char*)
{

	auto itr1 = find(system_members.begin(), system_members.end(), name1);
	auto itr2 = find(system_members.begin(), system_members.end(), name2);

    if (itr1 == system_members.end())
		throw "error: the first user doesn't exist!";

	if (itr2 == system_members.end()) 
		throw "error: the second user doesn't exist!";
	
	if (name1 == name2)
		throw "error: you cant link a member with himself!";


	try
	{
		*itr1 += *itr2;
	}
	catch(const char* msg)
	{
		throw(msg);
	}


}


void System::unLinkFriends(const string& name1, const string& name2) throw (const char*)
{

	auto itr1 = find(system_members.begin(), system_members.end(), name1);
	auto itr2 = find(system_members.begin(), system_members.end(), name2);

	if (itr1 == system_members.end())
		throw "error: the first user doesn't exist!";

	if (itr2 == system_members.end())
		throw "error: the second user doesn't exist!";

	if ((*itr1).getFriendsSize() == 0)
		throw "error: the first user you entered doesn't have friends to delete!";

	if ((*itr2).getFriendsSize() == 0)
		throw "error: the second user you entered doesn't have friends to delete!";
	
	if (itr1 == itr2)
		throw "error: you cant unlink yourself!";

	try
	{
		(*itr1).removeFriend(*itr2);
	}
	catch (const char* msg)
	{
		throw(msg);
	}
}


void System::addFanToAPage(const string& name_page, const string& name_member) throw(const char*)
{
	auto itr_fan = find(system_members.begin(), system_members.end(), name_member);
	auto itr_page = find(system_pages.begin(), system_pages.end(), name_page);

	if (itr_fan == system_members.end())
		throw "error:the name of fan you entered not exist in the system!";

	if (itr_page == system_pages.end())
		throw "error:the name of page you entered not exist in the system!";

	try
	{
		(*itr_page) += (*itr_fan);
	}
	catch(const char* msg)
	{
		throw(msg);
	}
}


void System::removeFanFromAFanPage(const string& name_page, const string& name_member) throw(const char*)
{
	auto itr_page = find(system_pages.begin(), system_pages.end(), name_page);
	auto itr_member = find(system_members.begin(), system_members.end(), name_member);


	if (itr_page == system_pages.end())
		throw "error: page not found in sytem!";

	if (itr_member == system_members.end())
		throw "error: member not found in system!";

	if ((*itr_page).getFansSize() == 0)
		throw "error: the given page doesn't have any fans to delete!";

	try
	{
		(*itr_page).deleteFan(*itr_member);
	}
	catch (const char* msg)
	{
		throw(msg);
	}
}


void System::printAllFriendsOfMember(const string& name) const throw (const char*)
{
	auto itr = find(system_members.begin(), system_members.end(), name);

	if (itr == system_members.end())
		throw "error: the user doesn't exist!";

	(*itr).showAllFriends();
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



int System::getMembersSize() const
{
	return system_members.size();
}

int System::getPagesSize() const
{
	return system_pages.size();
}
