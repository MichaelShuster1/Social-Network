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

void Member::addStatus(Status& _status)
{
	//Myrealloc(status_array, numOfStatuses+1);
	status_array[numOfStatuses] = _status;
	numOfStatuses++;
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

void Member::showFriends()
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