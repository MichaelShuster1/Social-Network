#include "system.h"
using namespace std;


System::System()
{
	loadDataFromFile();	
}


System::~System()
{
	saveDataToFile();
}

void System::saveDataToFile() const
{
	ofstream outFile("data.txt", ios::trunc);
	saveMembersToFile(outFile);
	savePagesToFile(outFile);
	saveFriendsOfMembersToFile(outFile);
	saveFansOfPagesToFile(outFile);
	outFile.close();
}

void System::saveMembersToFile(ofstream& os) const
{
	auto itr = system_members.begin();
	auto itrEnd = system_members.end();
	os << system_members.size() << endl;
	for (; itr != itrEnd; ++itr)
	{
		os<< *itr;
	}
}

void System::savePagesToFile(std::ofstream& os) const
{
	auto itr = system_pages.begin();
	auto itrEnd = system_pages.end();
	os << system_pages.size() << endl;

	for (; itr != itrEnd; ++itr)
	{
		os << *itr;
	}
}

void System::saveFriendsOfMembersToFile(std::ofstream& os) const
{
	auto itr = system_members.begin();
	auto itrEnd = system_members.end();
	for (; itr != itrEnd; ++itr)
	{
		(*itr).saveFriendsToFile(os);
	}
}

void System::saveFansOfPagesToFile(std::ofstream& os) const
{
	auto itr = system_pages.begin();
	auto itrEnd = system_pages.end();
	for (; itr != itrEnd; ++itr)
	{
		(*itr).saveFansToFile(os);
	}
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
		cout << i << ". " <<(*itr) << endl;
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
		cout<<(*itr)<<endl;
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
		cout<<(*itr) << "'s statuses are:" << endl;
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
		cout<<(*itr);
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

	*itr1 += *itr2;
}


void System::unLinkFriends(const string& name1, const string& name2) noexcept(false)
{

	auto itr1 = find(system_members.begin(), system_members.end(), name1);
	auto itr2 = find(system_members.begin(), system_members.end(), name2);

	if (itr1 == system_members.end())
		throw FirstUserNotFoundException();

	if (itr2 == system_members.end())
		throw SecondUserNotFoundException();

	if ((*itr1).getFriendsSize() == EMPTY)
		throw NoFriendsFirstException();

	if ((*itr2).getFriendsSize() == EMPTY)
		throw NoFriendsSecondException();
	
	if (itr1 == itr2)
		throw SameUsersException();

	(*itr1).removeFriend(*itr2);
}


void System::addFanToAPage(const string& name_page, const string& name_member) noexcept(false)
{
	auto itr_fan = find(system_members.begin(), system_members.end(), name_member);
	auto itr_page = find(system_pages.begin(), system_pages.end(), name_page);

	if (itr_fan == system_members.end())
		throw UserNotFoundException();

	if (itr_page == system_pages.end())
		throw PageNotFoundException();

	(*itr_page) += (*itr_fan);
}


void System::removeFanFromAFanPage(const string& name_page, const string& name_member) noexcept(false)
{
	auto itr_page = find(system_pages.begin(), system_pages.end(), name_page);
	auto itr_member = find(system_members.begin(), system_members.end(), name_member);


	if (itr_page == system_pages.end())
		throw PageNotFoundException();

	if (itr_member == system_members.end())
		throw UserNotFoundException();

	(*itr_page).deleteFan(*itr_member);
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
	StatusPicture status1("What an amazing beach!", "Mon Jul 16 02:03:55 2021", "sea.jpg");
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
	StatusPicture status7("Awesome tree!", "Mon Jul 16 02:03:55 2019", "tree.jpg");
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

void System::loadUserFriendsFromFile(ifstream& in)
{
	auto itr = system_members.begin();
	auto itrEnd = system_members.end();
	string name;
	int numOfFriends, numOfPages;
	for (; itr != itrEnd; ++itr)
	{
		in >> numOfFriends;
		in.ignore();
		for (int i = 0; i < numOfFriends; i++)
		{
			getline(in, name);
			auto itrUser = find(system_members.begin(), system_members.end(), name);
			(*itr).oneSidedLink(*itrUser);

		}

	}

}


void System::loadFansFromFile(ifstream& in)
{
	string name;
	int numOfFans, i;

	auto itrPage = system_pages.begin();
	auto itrEnd = system_pages.end();

	for (; itrPage != itrEnd; ++itrPage)
	{
		in >> numOfFans;
		in.ignore();
		for (i = 0; i < numOfFans; i++)
		{
			getline(in, name);
			auto itrUser = find(system_members.begin(), system_members.end(), name);
			(*itrPage) += (*itrUser);
		}
	}
}

void System::loadDataFromFile()
{
	ifstream inFile("data.txt");
	if (!inFile)
		createHardcodedEntities();
	else
	{
		loadUsersFromFile(inFile);
		loadPagesFromFile(inFile);
		loadUserFriendsFromFile(inFile);
		loadFansFromFile(inFile);
	}
	inFile.close();
}

void System::loadUsersFromFile(ifstream& in)
{
	int numOfUsers;

	in >> numOfUsers;
	in.ignore();
	for (int i = 0; i < numOfUsers; i++)
	{
		system_members.push_back(Member(in));
	}
}

void System::loadPagesFromFile(ifstream& in)
{
	int numOfPages;

	in >> numOfPages;
	in.ignore();
	for (int i = 0; i < numOfPages; i++)
	{
		system_pages.push_back(Fan_page(in));
	}

}