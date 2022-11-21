#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "system.h"



void main()
{
	bool exit = false;
	int choice;

	//temp
	Date date_array[2] = { {2022,12,12},{2022,11,12} };
	Hour hour_array[2] = { {18,20},{19,20} };
	Status status_array[2] = { {date_array[0],hour_array[0],"hello1"}, {date_array[1],hour_array[1],"hello2"}};
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
			chooseOneMember(&System_Members, members_size);
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

	freeMemberArr(System_Members,members_size);
	freePageArr(System_Pages, pages_size);


	_CrtDumpMemoryLeaks();
}
