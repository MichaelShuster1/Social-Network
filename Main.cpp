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


	Member** System_Members = new Member*[1];
	Fan_page** System_Pages = new Fan_page*[1];
	int members_size = 0;
	int members_physical_size = 1;
	int pages_size = 0;
	int pages_physical_size = 1;
	int index1, index2;
	Member* selected_friend;


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
		cout << "11- show all friends of a member/show all friends of a fan page" << endl;
		cout << "12- exit" << endl;
		cout << "please enter your choice here:  ";
		cin >> choice;
		switch (choice)
		{

		case 1:
			AddNewUser(&System_Members,members_size,members_physical_size);
			break;

		case 2:
			AddNewPage(&System_Pages, pages_size,pages_physical_size);
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			cout << "choose the first friend by entering their index number: " << endl;
			index1 = chooseOneMember(System_Members, members_size);
			cout << "choose the second friend by entering their index number: " << endl;
			index2 = chooseOneMember(System_Members, members_size);
			linkFriends(*System_Members[index1 - 1], *System_Members[index2 - 1]);
			break;

		case 7:
			cout << "choose a user from which you want to unlink a friend: " << endl;
			index1 = chooseOneMember(System_Members, members_size);
			cout << "choose the friend you want to unlink:  " << endl;
			System_Members[index1 - 1]->showAllFriends(); 
			cin >> index2;
			selected_friend = System_Members[index1 - 1]->getMemberFromFriends(index2 - 1);
			selected_friend->removeFriend(*System_Members[index1 - 1]);
			System_Members[index1 - 1]->removeFriend(*selected_friend);
			break;

		case 8:
			cout << "choose the memeber you wish to add to a fan page: " << endl;
			index1 = chooseOneMember(System_Members, members_size);
			cout << "choose the fan page you want to add the member as a fan to: " << endl;
			index2 = chooseOnePage(System_Pages, pages_size);
			linkFanToPage(*System_Members[index1 - 1], *System_Pages[index2 - 1]);
			break;

		case 9:
			cout << "choose a fan page from which you want to unlink a fan: " << endl;
			index1 = chooseOnePage(System_Pages, pages_size);
			cout << "choose the fan you want to unlink:  " << endl;
			System_Pages[index1 - 1]->show_all_fans();
			cin >> index2;
			selected_friend = System_Pages[index1 - 1]->getfanFromFans(index2 - 1);
			selected_friend->removePage(*System_Pages[index1 - 1]);
			System_Pages[index1 - 1]->delete_Fan(*selected_friend, index2 - 1);
			break;

		case 10:
			printAllRegisteredEntities(System_Members, members_size, System_Pages, pages_size);
			break;

		case 11:
			printAllfriendsOrFansOfanEntity(System_Members, members_size, System_Pages, pages_size);
			cout << "choose the friend by entering their index number: ";
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
