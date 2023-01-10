#include "system.h"
using namespace std;


System::System()
{
	ifstream inFile("data.txt");
	if (!inFile)
		cout << "not good";
	Member m1(inFile);
	//Member m2(inFile);
	//Member m3(inFile);
	
	createHardcodedEntities();;

	inFile.close();
}

System::~System()
{
	ofstream outFile("data.txt", ios::trunc);
	auto itr = system_members.begin();
	outFile << *itr;
	++itr;
	outFile << *itr;
	++itr;
	outFile << *itr;
	outFile.close();
}



void System::addNewUser(const Member& new_user) noexcept(false)
{
	if(checkUserNameTaken(new_user.getName()))
		throw UserNameTakenException();	
	system_members.push_back(Member(new_user));	
}

bool System::checkUserNameTaken(const string& name) const
{
	auto itr = find(system_members.begin(), system_members.end(),name);
	if (itr != system_members.end())
		return true;
	return false;
}


void System::addNewPage(const Fan_page& new_page) noexcept(false)
{
	auto itr = find(system_pages.begin(), system_pages.end(), new_page.getName());
	if (itr!=system_pages.end())
	{
		throw UserNameTakenException();
	}
	system_pages.push_back(Fan_page(new_page));
}


void System::addNewStatusToMember(Status* new_status,const string& name) noexcept(false)
{
	auto itr = find(system_members.begin(), system_members.end(), name);
	if (itr != system_members.end())
		(*itr).addStatus(new_status);
	else
		throw UserNotFoundException();
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


void System::addNewStatusToFanPage(Status* new_status,const string& name) noexcept(false)
{
	auto itr = find(system_pages.begin(),system_pages.end(),name);
	if (itr == system_pages.end())
		throw PageNotFoundException();
	(*itr).addStatus(new_status);
}


void System::showAllStatusesOfAMember(const string& name) const noexcept(false)
{
	auto itr = find(system_members.begin(),system_members.end(),name);
	if (itr != system_members.end())
	{
		(*itr).showName();
		cout << "'s statuses are:" << endl;
		(*itr).showAllStatuses();
	}
	else
		throw UserNotFoundException();
}


void System::showAllStatusesOfAFanPage(const string& name) const noexcept(false)
{
	auto itr = find(system_pages.begin(), system_pages.end(),name);
	if (itr != system_pages.end())
	{
		(*itr).showName();
		cout << "'s statuses are:" << endl;
		(*itr).showAllStatuses();
	}
	else
		throw PageNotFoundException();
}



void System::ShowTenLatestStatusesOfEachFriend(const string& name) const noexcept(false)
{
	auto itr = find(system_members.begin(), system_members.end(), name);
	if (itr != system_members.end())
		(*itr).showAllFriendsTenStatuses();
	else
		throw UserNotFoundException();
}


void System::linkFriends(const string& name1, const string& name2) noexcept(false)
{

	auto itr1 = find(system_members.begin(), system_members.end(), name1);
	auto itr2 = find(system_members.begin(), system_members.end(), name2);

	if (itr1 == system_members.end())
		throw FirstUserNotFoundException();

	if (itr2 == system_members.end())
		throw SecondUserNotFoundException();
	
	if (name1 == name2)
		throw SameUsersException();


	try
	{
		*itr1 += *itr2;
	}
	catch(UserLinkingException& e)
	{
		throw(e);
	}


}


void System::unLinkFriends(const string& name1, const string& name2) noexcept(false)
{

	auto itr1 = find(system_members.begin(), system_members.end(), name1);
	auto itr2 = find(system_members.begin(), system_members.end(), name2);

	if (itr1 == system_members.end())
		throw FirstUserNotFoundException();

	if (itr2 == system_members.end())
		throw SecondUserNotFoundException();

	if ((*itr1).getFriendsSize() == 0)
		throw NoFriendsFirstException();

	if ((*itr2).getFriendsSize() == 0)
		throw NoFriendsSecondException();
	
	if (itr1 == itr2)
		throw SameUsersException();

	try
	{
		(*itr1).removeFriend(*itr2);
	}
	catch (UnLinkingException& e)
	{
		throw(e);
	}
}


void System::addFanToAPage(const string& name_page, const string& name_member) noexcept(false)
{
	auto itr_fan = find(system_members.begin(), system_members.end(), name_member);
	auto itr_page = find(system_pages.begin(), system_pages.end(), name_page);

	if (itr_fan == system_members.end())
		throw UserNotFoundException();

	if (itr_page == system_pages.end())
		throw PageNotFoundException();

	try
	{
		(*itr_page) += (*itr_fan);
	}
	catch(AddFanException& e)
	{
		throw(e);
	}
}


void System::removeFanFromAFanPage(const string& name_page, const string& name_member) noexcept(false)
{
	auto itr_page = find(system_pages.begin(), system_pages.end(), name_page);
	auto itr_member = find(system_members.begin(), system_members.end(), name_member);


	if (itr_page == system_pages.end())
		throw PageNotFoundException();

	if (itr_member == system_members.end())
		throw UserNotFoundException();

	try
	{
		(*itr_page).deleteFan(*itr_member);
	}
	catch (NotFanException& e1)
	{
		throw(e1);
	}
	catch (NoFansException& e2)
	{
		throw(e2);
	}
}


void System::printAllFriendsOfMember(const string& name) const noexcept(false)
{
	auto itr = find(system_members.begin(), system_members.end(), name);

	if (itr == system_members.end())
		throw UserNotFoundException();

	(*itr).showAllFriends();
}


void System::printAllFandsOfPage(const string& name) const noexcept(false)
{
	auto itr = find(system_pages.begin(), system_pages.end(), name);
	if (itr == system_pages.end())
		throw PageNotFoundException();
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
	(*itrMember).addStatus(&status1);
	(*itrMember).addStatus(&status2);
	++itrMember;
	(*itrMember).addStatus(&status3);
	(*itrMember).addStatus(&status4);
	++itrMember;
	(*itrMember).addStatus(&status5);
	(*itrMember).addStatus(&status6);
	Status status7("status7", "Mon Jul 16 02:03:55 2019");
	Status status8("status8", "Mon Jul 17 02:03:55 2019");
	Status status9("status9", "Mon Jul 18 02:03:55 2020");
	Status status10("status10", "Mon Jul 19 02:03:55 2020");
	Status status11("status11", "Mon Jul 20 02:03:55 2021");
	Status status12("status12", "Mon Jul 21 02:03:55 2022");
	auto itrPage = system_pages.begin();
	(*itrPage).addStatus(&status7);
	(*itrPage).addStatus(&status8);
	itrPage++;
	(*itrPage).addStatus(&status9);
	(*itrPage).addStatus(&status10);
	itrPage++;
	(*itrPage).addStatus(&status11);
	(*itrPage).addStatus(&status12);

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
