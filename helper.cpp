#include "helper.h"
using namespace std;

void addNewUserToSystem(System& system)
{
	int year, month, day;
	string name;
	bool valid_date = false;
	bool valid_name = false;
	bool name_pending = false;

	cin.ignore();

	while (!valid_name)
	{
		cout << "Please enter the name of the new user: ";
		getline(cin, name);
		if (name.size() == 0)
			cout << "the name is empty!" << endl;
		else if (!(Member::isChar(*(name.begin()))))
			cout << "the name must start with a latter!" <<endl;
		else if (!system.checkUserNameTaken(name))
			valid_name = true;
		else
			cout << "the name is already taken" << endl;
		
	}

	while (!valid_date)
	{
		cout << "Please enter the user's birth date in the following format : dd/mm/yyyy" << endl;
		cin >> day;
		cin.ignore();
		cin >> month;
		cin.ignore();
		cin >> year;
		cin.ignore();
		try
		{
			system.addNewUser(Member(name, Date(year, month, day)));
			valid_date = true;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}
}



void addNewPageToSystem(System& system)
{
	string name;
	bool isValidData = false;
	

	cin.ignore();
	while (!isValidData)
	{
		cout << "Please enter the name of the new page: ";
		getline(cin, name);
		try 
		{
			system.addNewPage(Fan_page(name));
			isValidData = true;
		}
		catch (exception& e)
		{
			 cout << e.what() <<endl;
		}
	}	
}

void chooseStatusType(int& choice)
{
	bool isValid = false;
	while (!isValid)
	{
		cout << "Please choose the status type" << endl
			<< "1 - text" << endl << "2 - text and picture" << endl
			<< "3 - text and video" << endl;
		cin >> choice;
		if (choice <= VIDEO_STATUS && choice >= TEXT_STATUS)
			isValid = true;
		else
			cout << "Please choose a number between 1 and 3!" << endl;
	}
}

void createNewStatus(Status** newStatus)
{
	string text;
	string tm;
	string attachment;
	time_t curr_time;
	bool isValidData = false;
	int choice;

	cin.ignore();
	chooseStatusType(choice);
	cin.ignore();
	while (!isValidData)
	{
		cout << "Please enter the status: ";
		getline(cin, text);
		curr_time = time(NULL);
		tm = ctime(&curr_time);
		tm.pop_back();
		if (choice == PICTURE_STATUS || choice == VIDEO_STATUS)
		{
			cout << "Please enter the name of the file with extension (must be located in the program's directory): ";
			getline(cin, attachment);
		}
		try
		{
			switch (choice)
			{
			case TEXT_STATUS:
				*newStatus = new Status(text, tm);
				isValidData = true;
				break;
			case PICTURE_STATUS:
				*newStatus = new StatusPicture(text, tm, attachment);
				isValidData = true;
				break;
			case VIDEO_STATUS:
				*newStatus = new StatusVideo(text, tm, attachment);
				isValidData = true;
				break;
			default:
				break;
			}
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}
}


void printAllRegisteredEntitiesInSystem(System& system)
{
	system.printAllSystemMembers();
	cout << endl;
	system.printAllSystemPages();
}


void chooseOneMember(string& name)
{
	cout << "please enter the name of the member: ";
	getline(cin, name);
}


void chooseOnePage(string& name)
{
	cout << "please enter the name of the page: ";
	getline(cin, name);
}


void choosePagesOrMembers(int& choice)
{
	bool isValidData = false;
	while (!isValidData)
	{
		cout << "enter 1 to choose a member" << endl;
		cout << "enter 2 to choose a fan page" << endl;
		cout << "please enter your choice here:  ";
		cin >> choice;
		if (choice == MEMBER || choice == FAN_PAGE)
			isValidData = true;
		else
			cout << "error:your choice needs to be the number 1 or 2 only!,please try again" << endl;
	}
}


void printAllFriendsOrFansEntity(System& system)
{
	int choice;
	string name;
	bool isValidInput = false;

	choosePagesOrMembers(choice);

	cin.ignore();
	while (!isValidInput)
	{
		try {
			switch (choice)
			{
			case MEMBER:
				chooseOneMember(name);
				system.printAllFriendsOfMember(name);
				break;
			case FAN_PAGE:
				chooseOnePage(name);
				system.printAllFandsOfPage(name);
				break;
			default:
				break;
			}
			isValidInput = true;
		}
		catch (exception& e)
		{
			cout << e.what() <<endl;
		}
	}

}


void addNewStatusToFanPageOrMember(System& system)
{
	int choice;
	string name;
	Status* newStatus;
	bool isValidInput = false;

	choosePagesOrMembers(choice);
	createNewStatus(&newStatus);

	while (!isValidInput)
	{
		try {
			switch (choice)
			{
			case MEMBER:
				cout << "choose the member you want to add the given status to"<<endl;
				chooseOneMember(name);
				system.addNewStatusToMember(newStatus, name);
				break;
			case FAN_PAGE:
				cout << "choose the page you want to add the given status to" << endl;
				chooseOnePage(name);
				system.addNewStatusToFanPage(newStatus, name);
				break;
			default:
				break;
			}
			isValidInput = true;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}
	delete newStatus;
}


void showAllStatusesOfAFanPageOrMember(System& system)
{
	int choice, index;
	string name;
	bool isValidInput = false;


	choosePagesOrMembers(choice);
	cin.ignore();

	while (!isValidInput)
	{
		try
		{
			switch (choice)
			{
			case MEMBER:
				chooseOneMember(name);
				system.showAllStatusesOfAMember(name);
				break;
			case FAN_PAGE:
				chooseOnePage(name);
				system.showAllStatusesOfAFanPage(name);
				break;
			default:
				break;
			}

			isValidInput = true;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}

	}
}


void ShowTenStatusesOfEachFriend(System& system)
{
	int index;
	bool isValidInput = false;
	string name;

	cin.ignore();
	while (!isValidInput)
	{
		chooseOneMember(name);
		try
		{
			system.ShowTenLatestStatusesOfEachFriend(name);
			isValidInput = true;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}
}


void removeFanFromPageInSystem(System& system)
{
	string name_page, name_fan;
	bool isValidInput = false, exit = false;
	char choice;

	do
	{
		cin.ignore();
		cout << "choose a fan page from which you want to unlink a fan: " << endl;
		chooseOnePage(name_page);
		chooseOneMember(name_fan);
		try
		{
			system.removeFanFromAFanPage(name_page, name_fan);
			isValidInput = true;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
			do {
				cout << "do you wish to try again?[y/n]: ";
				cin >> choice;

				if (choice == NO)
					exit = true;
				else if (choice != YES)
					cout << "Invalid input, please enter y or n" << endl;
			} while (choice != NO && choice != YES);
		}
	} while (!isValidInput && !exit);
}


void linkFriendshipInSystem(System& system)
{
	char choice;
	bool validInput = false, exit = false;
	string name1, name2;
	
	do 
	{
		cin.ignore();
		cout << "first member:" << endl;
		chooseOneMember(name1);
		cout << "second member:" << endl;
		chooseOneMember(name2);
		try
		{
			system.linkFriends(name1, name2);
			validInput = true;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
			do {
				cout << "do you wish to try again?[y/n]: ";
				cin >> choice;

				if (choice == NO)
					exit = true;
				else if (choice != YES)
					cout << "Invalid input, please enter y or n" << endl;
			} while (choice != NO && choice != YES);
		}
	} while (!validInput && !exit);

}



void unLinkFriendshipInSystem(System& system)
{
	Member* selected_friend;
	string name1,name2;
	bool isValidInput = false, exit = false;
	char choice;

	do
	{
		cin.ignore();
		cout << "user from which you want to unlink a friend: " << endl;
		chooseOneMember(name1);
		cout << "friend you want to delete: " << endl;
		chooseOneMember(name2);
		try
		{
			system.unLinkFriends(name1, name2);
			isValidInput = true;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
			do {
				cout << "do you wish to try again?[y/n]: ";
				cin >> choice;

				if (choice == NO)
					exit = true;
				else if (choice != YES)
					cout << "Invalid input, please enter y or n" << endl;
			} while (choice != NO && choice != YES);
		}
	} while (!isValidInput && !exit);
}



void addFanToPageInSystem(System& system)
{
	bool isValidData = false, exit = false;
	char choice;
	string name_page, name_member;

	do
	{
		cin.ignore();
		cout << "the fan page you want to add a member as a fan to : " << endl;
		chooseOnePage(name_page);
		cout << "the memeber you wish to add to a fan page: " << endl;
		chooseOneMember(name_member);

		try
		{
			system.addFanToAPage(name_page, name_member);
			isValidData = true;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
			do {
				cout << "do you wish to try again?[y/n]: ";
				cin >> choice;

				if (choice == NO)
					exit = true;
				else if (choice != YES)
					cout << "Invalid input, please enter y or n" << endl;
			} while (choice != NO && choice != YES);
		}
	} while (!isValidData && !exit);
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

	case ADD_NEW_USER:
		addNewUserToSystem(system);
		break;

	case ADD_NEW_PAGE:
		addNewPageToSystem(system);
		break;

	case ADD_NEW_STATUS:
		addNewStatusToFanPageOrMember(system);
		break;

	case SHOW_ALL_STATUSES:
		showAllStatusesOfAFanPageOrMember(system);
		break;

	case SHOW_TEN_STATUSES:
		ShowTenStatusesOfEachFriend(system);
		break;

	case LINK_FRIENDS:
		linkFriendshipInSystem(system);
		break;

	case UNLINK_FRIENDS:
		unLinkFriendshipInSystem(system);
		break;

	case ADD_FAN:
		addFanToPageInSystem(system);
		break;

	case REMOVE_FAN:
		removeFanFromPageInSystem(system);
		break;

	case PRINT_ALL_ENTITIES:
		printAllRegisteredEntitiesInSystem(system);
		break;

	case PRINT_ALL_FANS_FRIENDS:
		printAllFriendsOrFansEntity(system);
		break;

	case EXIT:
		exit = true;
		cout << "Good bye" << endl;
		break;

	default:
		cout << "please choose a number from 1 to 12 only"<< endl;
		break;
	}
	return exit;
}