#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "system.h"



void main()
{
	bool exit = false;
	int choice;

	System system;

	/*
	Member** System_Members = new Member*[3];
	Fan_page** System_Pages = new Fan_page*[3];
	int members_size = 3;
	int members_physical_size = 3;
	int pages_size = 3;
	int pages_physical_size = 3;
	createHardcodedEntities(System_Members, System_Pages);
	*/

	while (exit == false)
	{
		printMenu();
		cin >> choice;
		switch (choice)
		{

		case 1:
			addNewUserToSystem(system);
			break;

		case 2:
			addNewPageToSystem(system);
			break;

		case 3:
			addNewStatusToFanPageOrMember(system);
			break;

		case 4:
			showAllStatusesOfAFanPageOrMember(system);

			break;

		case 5:
			ShowTenStatusesOfEachFriend(system);

		case 6:
			linkFriendshipInSystem(system);
			break;

		case 7:
			unLinkFriendshipInSystem(system);
			break;

		case 8:
			addFanToPageInSystem(system);
			break;

		case 9:
			removeFanFromPageInSystem(system);
			break;

		case 10:
			printAllRegisteredEntitiesInSystem(system);
			break;

		case 11:
			printAllFriendsOrFansEntity(system);
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

	/*
	freeMemberArr(System_Members,members_size);
	freePageArr(System_Pages, pages_size);
	*/


	_CrtDumpMemoryLeaks();
}
