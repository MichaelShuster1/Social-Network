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
	char name[NAME_LEN];
	Member* new_user;

	cout << "Please enter your full name: ";
	getchar();
	cin.getline(name, NAME_LEN);
	new_user = new Member(name);

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
	return Status(tm, status);
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
	cin >> choice;
	return choice;
}


int chooseOnePage(Fan_page** Pages, int size)
{
	int choice;
	printAllSysPages(Pages, size);
	cin >> choice;
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
	char user_input;
	int index;
	cout << "Do you want to choose from members or from fan pages?" << endl << "Enter M for members, or F for fan pages: ";
	cin >> user_input;
	if (user_input == 'M')
	{
		index = chooseOneMember(Users, size_u);
		Users[index - 1]->showAllFriends();
	}
	else
	{
		index = chooseOnePage(Pages, size_p);
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