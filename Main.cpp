#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "member.h"
#include "page.h"
#include <string.h>
#include <ctime>

const int NAME_LEN = 100;

void copyMemberArr(Member** dest, Member** src, int size);
void reSizeMemberArr(Member*** member_array, int old_size, int new_size);
void AddNewUser(Member*** Users, int& size);
void copyPageArr(Fan_page** dest, Fan_page** src, int size);
void reSizePagesArr(Fan_page*** page_array, int old_size, int new_size);
void AddNewPage(Fan_page*** Pages, int& size);
void printAllSysMembers(Member*** Users, int size);
void printAllSysPages(Fan_page*** Pages, int size);
void printAllRegisteredEntities(Member*** Users, int size_u, Fan_page*** Pages, int size_p);
int chooseOneMember(Member*** Users, int size);
int chooseOnePage(Fan_page*** Pages, int size);


void main()
{
	bool exit = false;
	int choice;

	//temp
	Date date_array[2] = { {2022,12,12},{2022,11,12} };
	Hour hour_array[2] = { {18,20},{19,20} };
	Status status_array[2] = { {date_array[0],hour_array[0],"hello1"}, {date_array[1],hour_array[1],"hello2"}};
	Member members_array[3] = { {"dani"},{"avi"},{"beni"}};
	Fan_page pages_array[3] = { {"page1"},{"page2"},{"page3"} };

	members_array[0].add_status(status_array[0]); 
	members_array[0].add_status(status_array[1]);
	pages_array[0].add_status(status_array[0]);

	pages_array[0].add_Fan(members_array[0]); 
	members_array[0].add_page(pages_array[0]);

	members_array[0].addFriend(members_array[1]);
	members_array[1].addFriend(members_array[0]);

	//temp


	Member** System_Members = new Member*;
	Fan_page** System_Pages = new Fan_page*;
	int members_size = 0;
	int pages_size = 0;


	while (exit == false)
	{
		cout << "1- add a new member"<<endl;
		cout << "2- add a new fan page" << endl;
		cout << "3- add a new status for a member/fan page" << endl;
		cout << "4 -show all statuses of a member/fan page" << endl;
		cout << "5- show 10 most recent statuses of member's friends" << endl;
		cout << "6 -link two members" << endl;
		cout << "7- unlink two members" << endl;
		cout << "8- add a fan to fan page" << endl;
		cout << "9- delete a fan from fan page" << endl;
		cout << "10- show all entities that are registered to the system" << endl;
		cout << "11- show all friends of a member/show all fands of a fan page" << endl;
		cout << "12- exit" << endl;
		cout << "please enter your choice here:  ";
		cin >> choice;
		switch (choice)
		{

		case 1:
			AddNewUser(&System_Members,members_size);
			break;

		case 2:
			AddNewPage(&System_Pages, pages_size);
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			break;

		case 9:
			break;

		case 10:
			printAllRegisteredEntities(&System_Members, members_size, &System_Pages, pages_size);
			break;

		case 11:
			break;

		case 12:
			exit = true;
			cout << "good bye"<<endl;
			break;

		default:
			break;
		}

		cout << endl;
	}

	_CrtDumpMemoryLeaks();
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

void printAllSysMembers(Member*** Users, int size)
{
	cout << "Members:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ". ";
		(*Users)[i]->showName();
		cout << endl;
	}
	cout << endl;
}

void printAllSysPages(Fan_page*** Pages, int size)
{
	cout << "Fan pages:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ". ";
		(*Pages)[i]->showName();
		cout << endl;
	}
	cout << endl;
}

void printAllRegisteredEntities(Member*** Users, int size_u, Fan_page*** Pages, int size_p)
{
	if (size_u > 0) 
		printAllSysMembers(Users, size_u);
	if (size_p > 0)
		printAllSysPages(Pages, size_p);
	
}

int chooseOneMember(Member*** Users, int size)
{
	int choice;
	cout << "Please choose a member: ";
	printAllSysMembers(Users, size);
	cin >> choice;
	return choice;
}

int chooseOnePage(Fan_page*** Pages, int size)
{
	int choice;
	cout << "Please choose a fan page: ";
	printAllSysPages(Pages, size);
	cin >> choice;
	return choice;
}

//void printAllfriendsOrFans()