#include "helper.h"
using namespace std;

void addNewUserToSystem(System& system)
{
	int year, month, day;
	char name[NAME_LEN];
	bool valid_date = false;
	Member* new_user;

	cout << "Please enter the name of the new user: ";
	getchar();
	cin.getline(name, NAME_LEN);
	while (system.checkIfExistNameUser(name) == true)
	{
		cout << "the name is already taken!" << endl;
		cout << "Please enter the name of the new user: ";
		cin.getline(name, NAME_LEN);
	}

	while(valid_date == false)
	{
		cout << "Please enter the user's birth date in the following format : dd/mm/yyyy" << endl;
		cin >> day;
		getchar();
		cin >> month;
		getchar();
		cin >> year;
		if (day > 31 || day < 1 || month > 12 || month < 1 || year > CURRENT_YEAR || year < 1900) 
			cout << "Incorrect birth date" << endl;
		else
			valid_date = true;
	}


	new_user = new Member(name, Date(year, month, day));
	system.addNewUser(new_user);
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


Status createNewStatus()
{
	char text[STATUS_LEN];
	char* tm;
	time_t curr_time;
	Status* newStatus;

	cout << "Please enter your status: ";
	getchar();
	cin.getline(text, STATUS_LEN);
	while (strlen(text) == 0)
	{
		cout << "You cant add an empty status!";
		cout << "Please enter your status: ";
		getchar();
		cin.getline(text, STATUS_LEN);
	}
	curr_time = time(NULL);
	tm = ctime(&curr_time);

	return Status(text, tm);
}


void printAllRegisteredEntitiesInSystem(System& system)
{
	system.printAllSystemMembers();
	cout << endl;
	system.printAllSystemPages();
}


int chooseOneMember(System& system)
{
	int choice;
	int size = system.getMembersSize();
	bool validInput;

	do
	{
		cout << "please choose the index of the member: " << endl;
		system.printAllSystemMembers();
		cout << "Enter your choice here: ";
		cin >> choice;
		if (1 <= choice && choice <= size)
			validInput = true;
		else
		{
			cout << "error: your choice needs to be a number between 1 and " << size << endl;
			validInput = false;
		}
	} while (validInput == false);
	
	return choice;
}


int chooseOnePage(System& system)
{
	int choice;
	int size = system.getPagesSize();
	bool validInput;

	do
	{
		cout << "Enter the index of the fan page: " << endl;
		system.printAllSystemPages();
		cout << "Enter your choice here: ";
		cin >> choice;
		if (1 <= choice && choice <= size)
			validInput = true;
		else
		{
			cout << "error: your choice needs to be a number between 1 and " << size << endl;
			validInput = false;
		}
	} while (validInput == false);

	return choice;
}


void choosePagesOrMembers(System& system, int& index, int& choice)
{
	while (!(choice == 1 || choice == 2))
	{
		cout << "enter 1 to choose a member" << endl;
		cout << "enter 2 to choose a fan page" << endl;
		cout << "please enter your choice here:  ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			index = chooseOneMember(system);
			cout << endl;
			break;
		case 2:
			index = chooseOnePage(system);
			cout << endl;
			break;
		default:
			cout << "error:your choice needs to be the number 1 or 2 only!,please try again" << endl;
			break;
		}
	}
}


void printAllFriendsOrFansEntity(System& system)
{
	int choice;
	int index;


	choosePagesOrMembers(system, index, choice);
	switch (choice)
	{
	case 1:
		system.printAllFriendsOfMember(index - 1);
		break;
	case 2:
		system.printAllFandsOfPage(index - 1);
		break;
	default:
		break;
	}

}


void addNewStatusToFanPageOrMember(System& system)
{
	int choice, index;
	Status newStatus;

	choosePagesOrMembers(system, index, choice);
	newStatus = createNewStatus();
	switch (choice)
	{
	case 1:
		system.addNewStatusToMember(&newStatus, index - 1);
		break;
	case 2:
		system.addNewStatusToFanPage(&newStatus, index - 1);
		break;
	default:
		break;
	}
}


void showAllStatusesOfAFanPageOrMember(System& system)
{
	int choice, index;

	choosePagesOrMembers(system, index, choice);
	switch (choice)
	{
	case 1:
		system.showAllStatusesOfAMember(index - 1);
		break;
	case 2:
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
	system.ShowTenLatestStatusesOfEachFriend(index - 1);
}



void linkFriendshipInSystem(System& system)
{
	int index1, index2;
	char choice;
	bool validInput = false;
	bool exit = false;

	do
	{
		cout << "please choose the two members you want to link by entering their index number with following formant: index1 index2" << endl;
		system.printAllSystemMembers();
		cout << "please enter your choice here: ";
		cin >> index1;
		getchar();
		cin >> index2;
		validInput = checkValidInput(system, index1, index2);
		if (!validInput)
		{
			do {
			    cout << "do you wish to try again?[y/n]: ";
			    cin >> choice;
			
				if (choice == 'n')
					exit = true;
				else if (choice != 'y')
					cout << "Invalid input, please enter y or n" << endl;
			} while (choice != 'n' && choice != 'y');
		}

	} while (!validInput && !exit);
	if(!exit)
		system.linkFriends(index1 - 1, index2-1);
}

bool checkValidInput(System& system,int index1, int index2)
{
	bool isVaild = true;
	int size = system.getMembersSize();

	if ((1 <= index1 && index1 <= size) && (1 <= index2 && index2 <= size))
	{
		if (index1 == index2)
		{
			cout << "error: you cant link a member with himself!" << endl;
			isVaild = false;
		}
		else if (system.areFriendsCheck(index1 - 1, index2 - 1))
		{
			cout << "error: the members you chose are already linked!" << endl;
			isVaild = false;
		}
	}
	else
	{
		cout << "error: your choices needs to be a number between 1 and " << size << ",please try again" << endl;
		isVaild = false;
	}
		

	return isVaild;
}


void unLinkFriendshipInSystem(System& system)
{
	int index1, index2;
	Member* selected_friend;
	
	cout << "choose a user from which you want to unlink a friend: " << endl;
	index1 = chooseOneMember(system);
	index2 = chooseOneFriendOfAMember(system,index1 - 1);
	if(index2!=-1)
		system.unLinkFriends(index1 - 1, index2 - 1);
}


int chooseOneFriendOfAMember(System& system,int index)
{
	int choice, size = system.getFriendsSizeOfAMember(index);
	bool validInput;
	if (size != 0)
	{
		do
		{
			cout << "choose the friend you want to unlink: " << endl;
			system.printAllFriendsOfMember(index);
			cout << "Enter your choice here: ";
			cin >> choice;
			if (1 <= choice && choice <= size)
				validInput = true;
			else
			{
				cout << "error: your choice needs to be a number between 1 and " << size << endl;
				validInput = false;
			}
		} while (validInput == false);

		return choice;
	}
	else
	{
		cout << "the user you chose has no friends to unlink from" << endl;
		return -1;
	}

}


void addFanToPageInSystem(System& system)
{
	bool validInput , exit = false;
	char choice;
	int index1, index2;

	do
	{
		cout << "choose the fan page you want to add a member as a fan to : " << endl;
		index1 = chooseOnePage(system);
		cout << "choose the memeber you wish to add to a fan page: " << endl;
		index2 = chooseOneMember(system);
		if (system.isFanCheck(index1 - 1, index2 - 1))
		{
			cout << "error:The user you chose is already a fan of this page!" <<endl;
			validInput = false;
		}
		else
			validInput = true;
		if (!validInput)
		{
			do {
				cout << "do you wish to try again [y/n]:";
				cin >> choice;
				if (choice == 'n')
					exit = true;
				else if (choice != 'y')
					cout << "Invalid input, please enter y or n" << endl;
			} while (choice != 'n' && choice != 'y');
		}
	} while (!validInput && !exit);
	if (!exit)
		system.addFanToAPage(index2 - 1, index1 - 1);	
}


void removeFanFromPageInSystem(System& system)
{
	int index1, index2;
	Member* selected_friend;

	cout << "choose a fan page from which you want to unlink a fan: " << endl;
	index1 = chooseOnePage(system);
	index2 = chooseOneFanOfAPage(system, index1 - 1);
	if(index2!=-1)
		system.removeFanFromAFanPage(index1 - 1, index2 - 1);
}


int chooseOneFanOfAPage(System& system,int index)
{
	int choice, size = system.getFansSizeofAPage(index);
	bool validInput;
	if (size != 0)
	{
		do
		{
			cout << "choose the fan you want to unlink:  " << endl;
			system.printAllFandsOfPage(index);
			cout << "Enter your choice here: ";
			cin >> choice;
			if (1 <= choice && choice <= size)
				validInput = true;
			else
			{
				cout << "error: your choice needs to be a number between 1 and " << size << endl;
				validInput = false;
			}
		} while (validInput == false);
		return choice;
	}
	else
	{
		cout << "the page you chose dont have fans to delete" << endl;
		return -1;
	}

}

void printMenu()
{
	cout << "welcome to the system's menu ,please select an action" << endl;
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


bool processChoice(System& system,int choice)
{
	bool exit = false;
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
		break;

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
		break;

	case 12:
		exit = true;
		cout << "good bye" << endl;
		break;

	default:
		cout << "please choose a number from 1 to 12 only"<< endl;
		break;
	}
	return exit;
}