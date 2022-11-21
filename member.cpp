#include "member.h"
#include "page.h"



Member::Member(const char* _name)
{
	if (_name != nullptr)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	else
		name = nullptr;
	status_array = nullptr;
	pages = nullptr;
	friends = nullptr;
	numOfFriends = numOfPages = numOfStatuses = 0;
}


Member::Member(const Member& other)
{
	numOfFriends = other.numOfFriends;
	numOfPages = other.numOfPages;
	numOfStatuses = other.numOfStatuses;
	birth_date = other.birth_date;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	copyStatusArr(status_array, other.status_array,numOfStatuses);
	copyMemberArr(friends, other.friends,numOfFriends);
	copyPageArr(pages, other.pages,numOfPages);
}



Member::~Member()
{
	delete[] name;
	delete[] pages;
	delete[] friends;
	delete[] status_array;
}


void Member::addFriend(Member& _member)
{
	reSizeMemberArr(&friends, numOfFriends, numOfFriends + 1);
	friends[numOfFriends] = &_member;
	numOfFriends++;
}

void Member::shiftBackMemberArr(int index)
{
	
	for (int i = index; i < numOfFriends-1; i++)
	{
		friends[i] = friends[i + 1];
	}
}


void Member::removeFriend(Member& _member)
{
	int i = 0;
	bool found = false;
	while (found == false)
	{
		if (friends[i] == &_member) 
			found = true;
		else
			i++;
	}

	shiftBackMemberArr(i);
	reSizeMemberArr(&friends, numOfFriends, numOfFriends-1);
	numOfFriends--;
}


void Member::add_status(const Status& status)
{
	reSizeStatusArr(&status_array, numOfStatuses, numOfStatuses + 1);
	status_array[numOfStatuses].copyStatus(status);
	numOfStatuses++;
}

void Member::add_page(Fan_page& page)
{
	reSizePagesArr(&pages, numOfPages, numOfPages + 1);
	pages[numOfPages] = &page;
	numOfPages++;
}


void Member::reSizeStatusArr(Status** status_array, int old_size, int new_size)
{
	Status* temp = new Status[new_size];
	copyStatusArr(temp, *status_array,getMin(old_size,new_size));
	delete[] (*status_array);
	(*status_array )= temp;
}

void Member::reSizeMemberArr(Member*** member_array, int old_size, int new_size)
{
	Member** temp = new Member*[new_size];
	copyMemberArr(temp, *member_array, getMin(old_size, new_size));
	delete[] (*member_array);
	(*member_array) = temp;
}


void Member::reSizePagesArr(Fan_page*** pages_array, int old_size, int new_size)
{
	Fan_page** temp = new Fan_page * [new_size];
	copyPageArr(temp, *pages_array, getMin(old_size, new_size));
	delete[](*pages_array);
	(*pages_array) = temp;
}



void Member::copyStatusArr(Status* dest, Status* src,int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i].copyStatus(src[i]);
}


void Member::copyMemberArr(Member** dest, Member** src,int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];

}


void Member::copyPageArr(Fan_page** dest, Fan_page** src,int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];
}


int Member::getMin(int num1, int num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}


void Member::showName()
{
	cout << name;
}

void Member::showAllFriends()
{
	for (int i = 0; i < numOfFriends; i++)
	{
		friends[i]->showName();
		cout << endl;
	}
		
}

void Member::showAllPages()
{
	for (int i = 0; i < numOfPages; i++)
	{
		pages[i]->showName();
		cout << endl;
	}
		
}

void Member::showAllStatuses()
{
	for (int i = 0; i < numOfStatuses; i++)
	{
		status_array[i].showStatus();
		cout << endl;
	}
		
}




