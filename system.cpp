#include "system.h"



System::System()
{
	members_size = 3;
	pages_size = 3;
	members_physical_size = 3;
	pages_physical_size = 3;
	system_members = new Member * [members_physical_size];
	system_pages = new Fan_page * [pages_physical_size];
	createHardcodedEntities(system_members, system_pages);
}


System::~System()
{
	freeMemberArr(system_members, members_size);
	freePageArr(system_pages, pages_size);
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


void System::printAllSystemMembers()
{
	cout << "Members:" << endl;
	for (int i = 0; i < members_size; i++)
	{
		cout << (i + 1) << ". ";
		system_members[i]->showName();
		cout << endl;
	}
	cout << endl;
}


void System::printAllSystemPages()
{
	cout << "Fan pages:" << endl;
	for (int i = 0; i < pages_size; i++)
	{
		cout << (i + 1) << ". ";
		system_pages[i]->showName();
		cout << endl;
	}
	cout << endl;
}


void System::addNewStatusToFanPage(Status* new_status, int index)
{
	system_pages[index]->add_status(*new_status);
}




void System::showAllStatusesOfAMember(int index)
{
	system_members[index]->showAllStatuses();
}

void System::showAllStatusesOfAFanPage(int index)
{
	system_pages[index]->showAllStatuses();
}


void System::ShowTenLatestStatusesOfEachFriend(int index)
{
	system_members[index]->showTenRecentStatuses();
}



void System::linkFriends(int index1, int index2)
{
	system_members[index1]->addFriend(*(system_members[index2]));
	system_members[index2]->addFriend(*(system_members[index1]));
}


void System::addFanToAPage(int index1, int index2)
{
	system_members[index1]->add_page(*(system_pages[index2]));
	system_pages[index2]->add_Fan(*(system_members[index1]));
}


void System::printMemberName(int index)
{
	system_members[index]->showName();
}


void System::printPageName(int index)
{
	system_pages[index]->showName();
}


void System::printAllFriendsOfMember(int index)
{
	system_members[index]->showAllFriends();
}


void System::printAllFandsOfPage(int index)
{
	system_pages[index]->show_all_fans();
}


void copyMemberArr(Member** dest, Member** src, int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];

}


void reSizeMemberArr(Member*** member_array, int old_size, int new_size)
{
	Member** temp = new Member * [new_size];
	copyMemberArr(temp, *member_array, getMin(old_size, new_size));
	delete[](*member_array);
	(*member_array) = temp;
}


void addNewUserToSystem(System& system)
{
	int year, month, day;
	char name[NAME_LEN];
	Member* new_user;

	cout << "Please enter the name of the new user: ";
	getchar();
	cin.getline(name, NAME_LEN);
	while (system.checkIfExistNameUser(name) == true)
	{
		cout << "the name is already taken!"<<endl;
		cout << "Please enter the name of the new user: ";
		cin.getline(name, NAME_LEN);
	}


	cout << "Please enter the user's bith date in the following formt : dd/mm/yyyy" << endl;
	cin >> day;
	getchar();
	cin >> month;
	getchar();
	cin >> year;
	new_user = new Member(name, Date(year, month, day));
	system.addNewUser(new_user);
}


void copyPageArr(Fan_page** dest, Fan_page** src, int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];

}

void reSizePagesArr(Fan_page*** page_array, int old_size, int new_size)
{
	Fan_page** temp = new Fan_page * [new_size];
	copyPageArr(temp, *page_array, getMin(old_size,new_size));
	delete[](*page_array);
	(*page_array) = temp;
}


int getMin(int num1, int num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}

void addNewPageToSystem(System& system)
{
	char name[NAME_LEN];
	Fan_page* new_page;

	cout << "Please enter the name of the new page: ";
	getchar();
	cin.getline(name, NAME_LEN);
	while (system.checkIfExistNamePage(name) == true)
	{
		cout << "the name is already taken!" << endl;
		cout << "Please enter the name of the new page: ";
		cin.getline(name, NAME_LEN);
	}


	new_page = new Fan_page(name);
	system.addNewPage(new_page);
}



Status* createNewStatus()
{
	char text[254];
	char* tm;
	time_t curr_time;
	Status* newStatus;

	cout << "Please enter your status: ";
	getchar();
	cin.getline(text, 254);
	curr_time = time(NULL);
	tm= ctime(&curr_time);

	newStatus = new Status(text, tm);
	return newStatus;
}


void printAllSysMembers(Member** Users, int size)
{
	cout << "Members:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ". ";
		Users[i]->showName();
		cout << endl;
	}
	cout << endl;
}


void printAllSysPages(Fan_page** Pages, int size)
{
	cout << "Fan pages:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ". ";
		Pages[i]->showName();
		cout << endl;
	}
	cout << endl;
}


void printAllRegisteredEntitiesInSystem(System& system)
{
	system.printAllSystemMembers();
	system.printAllSystemPages();
}


int chooseOneMember(System& system)
{
	int choice;
	system.printAllSystemMembers();
	cout << "Enter the index of the member: ";
	cin >> choice;
	cout << endl;
	return choice;
}


int chooseOnePage(System& system)
{
	int choice;
	system.printAllSystemPages();
	cout << "Enter the index of the fan page: ";
	cin >> choice;
	cout << endl;
	return choice;
}


void freeMemberArr(Member** Users, int size)
{
	for (int i = 0; i < size; i++)
		delete Users[i];

	delete[] Users;
}


void freePageArr(Fan_page** Pages, int size)
{
	for (int i = 0; i < size; i++)
		delete Pages[i];

	delete[]Pages;
}


void linkFriends(Member& mem1, Member& mem2)
{
	mem1.addFriend(mem2);
	mem2.addFriend(mem1);
}


void unlinkFriends(Member& mem1, Member& mem2)
{
	mem1.removeFriend(mem2);
	mem2.removeFriend(mem1);
}

void printAllFriendsOrFansEntity(System& system)
{
	int user_input;
	int index;
	cout << "Do you want to choose from members or from fan pages?" << endl << "Enter 1 for members, or 2 for fan pages: ";
	cin >> user_input;
	switch (user_input)
	{
	case 1:
		index = chooseOneMember(system);
		cout << endl;
		system.printMemberName(index - 1);
		cout << "'s friends are:" << endl;
		system.printAllFriendsOfMember(index - 1);
		break;
	case 2:
		index = chooseOnePage(system);
		cout << endl;
		system.printPageName(index = 1);
		cout << "'s fans are:" << endl;
		system.printAllFandsOfPage(index - 1);
		break;
	default:
		break;
	}
}


void linkFanToPage(Member& mem, Fan_page& page)
{
	mem.add_page(page);
	page.add_Fan(mem);
}


void unlinkFanFromPage(Member& mem, Fan_page& page)
{
	mem.removePage(page);
	//page.removeFan(mem);
}

void addNewStatusToFanPageOrMember(System& system)
{
	int choice,index;
	Status* newStatus;

	cout << "enter 1 to add new status for a member" << endl;
	cout << "enter 2 to add new status for a fan page" << endl;
	cout << "please enter your choice here:  ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "choose a user to which you want to add a new status: " << endl;
		index = chooseOneMember(system);
		newStatus = createNewStatus();
		system.addNewStatusToMember(newStatus, index-1);
		break;
	case 2:
		cout << "choose a page to which you want to add a new status: " << endl;
		index = chooseOnePage(system);
		newStatus = createNewStatus();
		system.addNewStatusToFanPage(newStatus, index = 1);
		break;

	default:
		break;
	}
}

void showAllStatusesOfAFanPageOrMember(System& system)
{
	int choice, index;

	cout << "enter 1 to choose a member" << endl;
	cout << "enter 2 to choose a fan page" << endl;
	cout << "please enter your choice here:  ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "choose a user to see their statuses " << endl;
		index = chooseOneMember(system);
		system.showAllStatusesOfAMember(index - 1);
		break;
	case 2:
		cout << "choose a page to see its statuses: " << endl;
		index = chooseOnePage(system);
		system.showAllStatusesOfAFanPage(index - 1);
		break;

	default:
		break;
	}
}

void ShowTenStatusesOfEachFriend(System& system)
{
	int index;
	cout << "choose a member by entering their index number: " << endl;
	index = chooseOneMember(system);
	system.ShowTenLatestStatusesOfEachFriend(index-1);
}

void linkFriendshipInSystem(System& system)
{
	int index1,index2;

	cout << "choose the first friend by entering their index number: " << endl;
	index1 = chooseOneMember(system);
	cout << "choose the second friend by entering their index number: " << endl;
	index2 = chooseOneMember(system);
	system.linkFriends(index1 - 1, index2 - 1);
}

void unLinkFriendshipInSystem(System& system)
{
	int index1, index2;
	Member* selected_friend;

	cout << "choose a user from which you want to unlink a friend: " << endl;
	index1 = chooseOneMember(system);
	cout << "choose the friend you want to unlink: " << endl;
	/*
	System_Members[index1 - 1]->showAllFriends();
	cin >> index2;
	selected_friend = System_Members[index1 - 1]->getMemberFromFriends(index2 - 1);
	selected_friend->removeFriend(*System_Members[index1 - 1]);
	System_Members[index1 - 1]->removeFriend(*selected_friend);
	*/
}


void addFanToPageInSystem(System& system)
{
	int index1, index2;
	cout << "choose the fan page you want to add a member as a fan to : " << endl;
	index1 = chooseOnePage(system);
	cout << "choose the memeber you wish to add to a fan page: " << endl;
	index2 = chooseOneMember(system);
	system.addFanToAPage(index2 - 1, index1 - 1);
}


void removeFanFromPageInSystem(System& system)
{
	int index1, index2;
	Member* selected_friend;

	cout << "choose a fan page from which you want to unlink a fan: " << endl;
	index1 = chooseOnePage(system);
	cout << "choose the fan you want to unlink:  " << endl;
	/*
	System_Pages[index1 - 1]->show_all_fans();
	cin >> index2;
	selected_friend = System_Pages[index1 - 1]->getfanFromFans(index2 - 1);
	selected_friend->removePage(*System_Pages[index1 - 1]);
	System_Pages[index1 - 1]->delete_Fan(*selected_friend, index2 - 1);
	*/
}

void printMenu()
{
	cout << "1- add a new member" << endl;
	cout << "2- add a new fan page" << endl;
	cout << "3- add a new status for a member/fan page" << endl;
	cout << "4 -show all statuses of a member/fan page" << endl;
	cout << "5- show 10 most recent statuses of member's friends" << endl;
	cout << "6 -link two members" << endl;
	cout << "7- unlink two members" << endl;
	cout << "8- add a fan to fan page" << endl;
	cout << "9- delete a fan from fan page" << endl;
	cout << "10- show all entities that are registered to the system" << endl;
	cout << "11- show all friends of a member/show all fans of a fan page" << endl;
	cout << "12- exit" << endl;
	cout << "please enter your choice here:  ";
}

void createHardcodedEntities(Member** System_Members, Fan_page** System_Pages)
{
	System_Members[0] = new Member("Avi Cohen", Date(1990, 10, 22));
	System_Members[1] = new Member("Yossi Levi", Date(1995, 1, 10));
	System_Members[2] = new Member("Israel Israeli", Date(2000, 2, 28));
	System_Pages[0] = new Fan_page("Music fans");
	System_Pages[1] = new Fan_page("Gaming fans");
	System_Pages[2] = new Fan_page("Movies fans");
	Status* status1 = new Status("status1", "Mon Jul 16 02:03:55 2021");
	Status* status2 = new Status("status2", "Mon Jul 17 02:03:55 2021");
	Status* status3 = new Status("status3", "Mon Jul 18 02:03:55 2022");
	Status* status4 = new Status("status4", "Mon Jul 19 02:03:55 2022");
	Status* status5 = new Status("status5", "Mon Jul 20 02:03:55 2022");
	Status* status6 = new Status("status6", "Mon Jul 21 02:03:55 2022");
	System_Members[0]->add_status(*status1);
	System_Members[0]->add_status(*status2);
	System_Members[1]->add_status(*status3);
	System_Members[1]->add_status(*status4);
	System_Members[2]->add_status(*status5);
	System_Members[2]->add_status(*status6);
	Status* status7 = new Status("status7", "Mon Jul 16 02:03:55 2019");
	Status* status8 = new Status("status8", "Mon Jul 17 02:03:55 2019");
	Status* status9 = new Status("status9", "Mon Jul 18 02:03:55 2020");
	Status* status10 = new Status("status10", "Mon Jul 19 02:03:55 2020");
	Status* status11 = new Status("status11", "Mon Jul 20 02:03:55 2021");
	Status* status12 = new Status("status12", "Mon Jul 21 02:03:55 2022");
	System_Pages[0]->add_status(*status7);
	System_Pages[0]->add_status(*status8);
	System_Pages[1]->add_status(*status9);
	System_Pages[1]->add_status(*status10);
	System_Pages[2]->add_status(*status11);
	System_Pages[2]->add_status(*status12);
	linkFanToPage(*System_Members[0], *System_Pages[0]);
	linkFanToPage(*System_Members[1], *System_Pages[1]);
	linkFriends(*System_Members[0], *System_Members[1]);
	linkFriends(*System_Members[1], *System_Members[2]);
}