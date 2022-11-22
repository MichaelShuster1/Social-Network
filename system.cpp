#include "system.h"

void copyMemberArr(Member** dest, Member** src, int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];

}


void reSizeMemberArr(Member*** member_array, int old_size, int new_size)
{
	Member** temp = new Member * [new_size];
	copyMemberArr(temp, *member_array, getMin(old_size,new_size));
	delete[](*member_array);
	(*member_array) = temp;
}


void AddNewUser(Member*** Users, int& logic_size,int& phyical_size)
{
	int year, month, day;
	char name[NAME_LEN];
	Member* new_user;

	cout << "Please enter your full name: ";
	getchar();
	cin.getline(name, NAME_LEN);
	cout << "Please enter your bith date in the following formt : dd/mm/yyyy" << endl;
	cin >> day;
	getchar();
	cin >> month;
	getchar();
	cin >> year;
	new_user = new Member(name,Date(year,month,day));

	if (logic_size == phyical_size)
	{
		phyical_size *= 2;
		reSizeMemberArr(Users, logic_size, phyical_size);
	}
	(*Users)[logic_size] = new_user;
	logic_size++;
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

void AddNewPage(Fan_page*** Pages, int& logic_size,int& physical_size)
{
	char name[NAME_LEN];
	cout << "Please enter your fan page's name: ";
	getchar();
	cin.getline(name, NAME_LEN);
	Fan_page* new_page = new Fan_page(name);

	if (logic_size == physical_size)
	{
		physical_size *= 2;
		reSizePagesArr(Pages, logic_size, physical_size);
	}
	(*Pages)[logic_size] = new_page;
	logic_size++;
}


Status createNewStatus()
{
	char status[254];
	time_t curr_time;
	char* tm;
	cout << "Please enter your status: ";
	getchar();
	cin.getline(status, 254);
	curr_time = time(NULL);
	tm= ctime(&curr_time);
	return Status(status, tm);
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


void printAllRegisteredEntities(Member** Users, int size_u, Fan_page** Pages, int size_p)
{
	if (size_u > 0)
		printAllSysMembers(Users, size_u);
	if (size_p > 0)
		printAllSysPages(Pages, size_p);

}


int chooseOneMember(Member** Users, int size)
{
	int choice;
	printAllSysMembers(Users, size);
	cout << "Enter the index of the member: ";
	cin >> choice;
	cout << endl;
	return choice;
}


int chooseOnePage(Fan_page** Pages, int size)
{
	int choice;
	printAllSysPages(Pages, size);
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

void printAllfriendsOrFansOfanEntity(Member** Users, int size_u, Fan_page** Pages, int size_p)
{
	int user_input;
	int index;
	cout << "Do you want to choose from members or from fan pages?" << endl << "Enter 1 for members, or 2 for fan pages: ";
	cin >> user_input;
	if (user_input == 1)
	{
		index = chooseOneMember(Users, size_u);
		cout << endl;
		Users[index - 1]->showName();
		cout << " friends are:" << endl;
		Users[index - 1]->showAllFriends();
	}
	else
	{
		index = chooseOnePage(Pages, size_p);
		cout << endl;
		Pages[index - 1]->showName();
		cout << " fans are:" << endl;
		Pages[index - 1]->show_all_fans();
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

void addNewStatusToFanPageOrMember(Member** System_Members, int members_size, Fan_page** System_Pages,int pages_size)
{
	int choice,index;

	cout << "enter 1 to add new status for a member" << endl;
	cout << "enter 2 to add new status for a fan page" << endl;
	cout << "please enter your choice here:  ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "choose a user to which you want to add a new status: " << endl;
		index = chooseOneMember(System_Members, members_size);
		System_Members[index - 1]->add_status(createNewStatus());
		break;
	case 2:
		cout << "choose a page to which you want to add a new status: " << endl;
		index = chooseOnePage(System_Pages, pages_size);
		System_Pages[index - 1]->add_status(createNewStatus());
		break;

	default:
		break;
	}
}

void showAllStatusesOfAFanPageOrMember(Member** System_Members, int members_size, Fan_page** System_Pages, int pages_size)
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
		index = chooseOneMember(System_Members, members_size);
		System_Members[index - 1]->showAllStatuses();
		break;
	case 2:
		cout << "choose a page to see its statuses: " << endl;
		index = chooseOnePage(System_Pages, pages_size);
		System_Pages[index - 1]->showAllStatuses();
		break;

	default:
		break;
	}
}

void ShowTenLatestStatusesOfEachFriend(Member** System_Members, int members_size)
{
	int index;

	cout << "choose a member by entering their index number: " << endl;
	index = chooseOneMember(System_Members, members_size);
	System_Members[index - 1]->showAllFriendsTenStatuses();
}

void linkFriendship(Member** System_Members, int members_size)
{
	int index1,index2;

	cout << "choose the first friend by entering their index number: " << endl;
	index1 = chooseOneMember(System_Members, members_size);
	cout << "choose the second friend by entering their index number: " << endl;
	index2 = chooseOneMember(System_Members, members_size);
	linkFriends(*System_Members[index1 - 1], *System_Members[index2 - 1]);
}

void unLinkFriendship(Member** System_Members, int members_size)
{
	int index1, index2;
	Member* selected_friend;

	cout << "choose a user from which you want to unlink a friend: " << endl;
	index1 = chooseOneMember(System_Members, members_size);
	cout << "choose the friend you want to unlink: " << endl;
	System_Members[index1 - 1]->showAllFriends();
	cin >> index2;
	selected_friend = System_Members[index1 - 1]->getMemberFromFriends(index2 - 1);
	selected_friend->removeFriend(*System_Members[index1 - 1]);
	System_Members[index1 - 1]->removeFriend(*selected_friend);
}

void addFanToAFanPage(Member** System_Members, int members_size, Fan_page** System_Pages, int pages_size)
{
	int index1, index2;
	cout << "choose the fan page you want to add a member as a fan to : " << endl;
	index1 = chooseOnePage(System_Pages, pages_size);
	cout << "choose the memeber you wish to add to a fan page: " << endl;
	index2 = chooseOneMember(System_Members, members_size);
	linkFanToPage(*System_Members[index2 - 1], *System_Pages[index1 - 1]);
}

void removeAFanFromAFanPage(Fan_page** System_Pages, int pages_size)
{
	int index1, index2;
	Member* selected_friend;

	cout << "choose a fan page from which you want to unlink a fan: " << endl;
	index1 = chooseOnePage(System_Pages, pages_size);
	cout << "choose the fan you want to unlink:  " << endl;
	System_Pages[index1 - 1]->show_all_fans();
	cin >> index2;
	selected_friend = System_Pages[index1 - 1]->getfanFromFans(index2 - 1);
	selected_friend->removePage(*System_Pages[index1 - 1]);
	System_Pages[index1 - 1]->delete_Fan(*selected_friend, index2 - 1);
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
	cout << "11- show all friends of a member/show all friends of a fan page" << endl;
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
	Status status1 = Status("status1", "Mon Jul 16 02:03:55 2021");
	Status status2 = Status("status2", "Mon Jul 17 02:03:55 2021");
	Status status3 = Status("status3", "Mon Jul 18 02:03:55 2022");
	Status status4 = Status("status4", "Mon Jul 19 02:03:55 2022");
	Status status5 = Status("status5", "Mon Jul 20 02:03:55 2022");
	Status status6 = Status("status6", "Mon Jul 21 02:03:55 2022");
	System_Members[0]->add_status(status1);
	System_Members[0]->add_status(status2);
	System_Members[1]->add_status(status3);
	System_Members[1]->add_status(status4);
	System_Members[2]->add_status(status5);
	System_Members[2]->add_status(status6);
	Status status7 = Status("status7", "Mon Jul 16 02:03:55 2019");
	Status status8 = Status("status8", "Mon Jul 17 02:03:55 2019");
	Status status9 = Status("status9", "Mon Jul 18 02:03:55 2020");
	Status status10 = Status("status10", "Mon Jul 19 02:03:55 2020");
	Status status11 = Status("status11", "Mon Jul 20 02:03:55 2021");
	Status status12 = Status("status12", "Mon Jul 21 02:03:55 2022");
	System_Pages[0]->add_status(status7);
	System_Pages[0]->add_status(status8);
	System_Pages[1]->add_status(status9);
	System_Pages[1]->add_status(status10);
	System_Pages[2]->add_status(status11);
	System_Pages[2]->add_status(status12);
	linkFanToPage(*System_Members[0], *System_Pages[0]);
	linkFanToPage(*System_Members[1], *System_Pages[1]);
	linkFriends(*System_Members[0], *System_Members[1]);
	linkFriends(*System_Members[1], *System_Members[2]);
}