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
	copyMemberArr(temp, *member_array, new_size);
	delete[](*member_array);
	(*member_array) = temp;
}


void AddNewUser(Member*** Users, int& size)
{
	char name[NAME_LEN];
	cout << "Please enter your full name: ";
	getchar();
	cin.getline(name, NAME_LEN);
	Member* new_user = new Member(name);
	reSizeMemberArr(Users, size, size + 1);
	(*Users)[size] = new_user;
	size++;
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
	copyPageArr(temp, *page_array, new_size);
	delete[](*page_array);
	(*page_array) = temp;
}


void AddNewPage(Fan_page*** Pages, int& size)
{
	char name[NAME_LEN];
	cout << "Please enter your fan page's name: ";
	getchar();
	cin.getline(name, NAME_LEN);
	Fan_page* new_page = new Fan_page(name);
	reSizePagesArr(Pages, size, size + 1);
	(*Pages)[size] = new_page;
	size++;
}


//void AddStatus(Member* user)
//{
//	char status[254];
//	cout << "Please enter your status: ";
//	getchar();
//	cin.getline(status, 254);
//	Status new_status = Status();
//    time_t curr_time;
//	curr_time = time(NULL);
//	char* tm = ctime(&curr_time);
//}


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
	cout << "Please choose a member: ";
	printAllSysMembers(Users, size);
	cin >> choice;
	return choice;
}


int chooseOnePage(Fan_page** Pages, int size)
{
	int choice;
	cout << "Please choose a fan page: ";
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

//void printAllfriendsOrFans()