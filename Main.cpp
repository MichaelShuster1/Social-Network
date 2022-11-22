#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "system.h"



void main()
{
	bool exit = false;
	int choice;
	int choice2;



	Member** System_Members = new Member*[3];
	Fan_page** System_Pages = new Fan_page*[3];
	int members_size = 3;
	int members_physical_size = 3;
	int pages_size = 3;
	int pages_physical_size = 3;
	int index1, index2;
	Member* selected_friend;

	System_Members[0] = new Member("Avi Cohen");
	System_Members[1] = new Member("Yossi Levi");
	System_Members[2] = new Member("Israel Israeli");
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
	linkFanToPage(*System_Members[0] ,* System_Pages[0]);
	linkFanToPage(*System_Members[1], *System_Pages[1]);
	linkFriends(*System_Members[0], *System_Members[1]);
	linkFriends(*System_Members[1], *System_Members[2]);





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
			cout << "enter 1 to add new status for a member" << endl;
			cout << "enter 2 to add new status for a fan page" << endl;
			cout << "please enter your choice here:  ";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				cout << "choose a user to which you want to add a new status: " << endl;
				index1 = chooseOneMember(System_Members, members_size);
				System_Members[index1 - 1]->add_status(createNewStatus());
				break;
			case 2:
				cout << "choose a page to which you want to add a new status: " << endl;
				index1 = chooseOnePage(System_Pages, pages_size);
				System_Pages[index1 - 1]->add_status(createNewStatus());
				break;

			default:
				break;
			}
			break;

		case 4:
			cout << "enter 1 to choose a member" << endl;
			cout << "enter 2 to choose a fan page" << endl;
			cout << "please enter your choice here:  ";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				cout << "choose a user to see their statuses " << endl;
				index1 = chooseOneMember(System_Members, members_size);
				System_Members[index1 - 1]->showAllStatuses();
				break;
			case 2:
				cout << "choose a page to see its statuses: " << endl;
				index1 = chooseOnePage(System_Pages, pages_size);
				System_Pages[index1 - 1]->showAllStatuses();
				break;

			default:
				break;
			}
			break;

		case 5:
			cout << "choose a member by entering their index number: " << endl;
			index1 = chooseOneMember(System_Members, members_size);
			System_Members[index1 - 1]->showAllFriendsTenStatuses();
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
			cout << "choose the fan page you want to add a member as a fan to : " << endl;
			index1 = chooseOnePage(System_Pages, pages_size);
			cout << "choose the memeber you wish to add to a fan page: " << endl;
			index2 = chooseOneMember(System_Members, members_size);
			linkFanToPage(*System_Members[index2 - 1], *System_Pages[index1 - 1]);
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
