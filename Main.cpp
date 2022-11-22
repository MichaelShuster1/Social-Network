#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "system.h"



void main()
{
	bool exit = false;
	int choice;

	Member** System_Members = new Member*[3];
	Fan_page** System_Pages = new Fan_page*[3];
	int members_size = 3;
	int members_physical_size = 3;
	int pages_size = 3;
	int pages_physical_size = 3;


	while (exit == false)
	{
		printMenu();
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
			addNewStatusToFanPageOrMember(System_Members, members_size, System_Pages, pages_size);
			break;

		case 4:
			showAllStatusesOfAFanPageOrMember(System_Members, members_size, System_Pages, pages_size);

			break;

		case 5:
			ShowTenLatestStatusesOfEachFriend(System_Members, members_size);

		case 6:
			linkFriendship(System_Members, members_size);
			break;

		case 7:
			unLinkFriendship(System_Members, members_size);
			break;

		case 8:
			addFanToAFanPage(System_Members, members_size, System_Pages, pages_size);
			break;

		case 9:
			removeAFanFromAFanPage(System_Pages, pages_size);
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
