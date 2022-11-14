#include "member.h"
#include "page.h"



Member::Member()
{
	name = nullptr;
	status_array = nullptr;
	pages = nullptr;
	friends = nullptr;
	numOfFriends = numOfPages = numOfStatuses = 0;
}

void Member::addFriend(Member& _member)
{
	//Myrealloc(friends,numOfFriends+1);
	friends[numOfFriends] = _member;
	numOfFriends++;
}

void Member::add_status(Date& date, Hour& hour, char* text)
{
	Status temp(date, hour, text);
	reSizeStatusArr(status_array, numOfStatuses, numOfStatuses + 1);
	status_array[numOfStatuses] = temp;
	numOfStatuses++;
}


void Member::reSizeStatusArr(Status* status_array, int size, int new_size)
{
	Status* temp = new Status[new_size];
	copyStatusArr(temp, status_array);
	deleteStatusArr(status_array);
	status_array = temp;
}

void Member::copyStatusArr(Status* dest, Status* src)
{
	int i;
	for (i = 0; i < numOfStatuses; i++)
	{
		dest[i] = src[i];
	}
}

void Member::deleteStatusArr(Status* arr)
{
	delete[] arr;
}



void Member::showStatuses()
{
	for (int i = 0; i < numOfStatuses; i++)
	{
		status_array[i].showStatus();
	}
}

void Member::showName()
{
	cout << name;
}

void Member::showAllFriends()
{
	for (int i = 0; i < numOfFriends; i++)
	{
		friends[i].showName();
	}
}


void linkFriends(Member& mem1, Member& mem2)
{
	mem1.addFriend(mem2);
	mem2.addFriend(mem1);
}

void Member::showAllStatuses()
{
	for (int i = 0; i < numOfStatuses; i++) {
		status_array[i].showStatus();
	}
}