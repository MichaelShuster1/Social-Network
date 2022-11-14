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


Member::Member(const Member& other)
{
	numOfFriends = other.numOfFriends;
	numOfPages = other.numOfPages;
	numOfStatuses = other.numOfStatuses;
	birth_date = other.birth_date;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	copyStatusArr(status_array, other.status_array);
	copyMemberArr(friends, other.friends);
	copyPageArr(pages, other.pages);
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
	reSizeMemberArr(friends, numOfFriends, numOfFriends + 1);
	friends[numOfFriends] = _member;
	numOfFriends++;
}

void Member::add_status(Status& status)
{
	reSizeStatusArr(status_array, numOfStatuses, numOfStatuses + 1);
	status_array[numOfStatuses] = status;
	numOfStatuses++;
}


void Member::reSizeStatusArr(Status* status_array, int size, int new_size)
{
	Status* temp = new Status[new_size];
	copyStatusArr(temp, status_array);
	delete[] status_array;
	status_array = temp;
}

void Member::reSizeMemberArr(Member* member_array, int size, int new_size)
{
	Member* temp = new Member[new_size];
	copyMemberArr(temp, member_array);
	delete[] member_array;
	member_array = temp;
}



void Member::copyStatusArr(Status* dest, Status* src)
{
	int i;
	for (i = 0; i < numOfStatuses; i++)
		dest[i] = src[i];
}


void Member::copyMemberArr(Member* dest, Member* src)
{
	int i;
	for (i = 0; i < numOfFriends; i++)
		dest[i] = src[i];

}


void Member::copyPageArr(Fan_page* dest, Fan_page* src)
{
	int i;
	for (i = 0; i < numOfPages; i++)
		dest[i] = src[i];
}



void Member::showStatuses()
{
	for (int i = 0; i < numOfStatuses; i++)
		status_array[i].showStatus();
}

void Member::showName()
{
	cout << name;
}

void Member::showAllFriends()
{
	for (int i = 0; i < numOfFriends; i++)
		friends[i].showName();
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