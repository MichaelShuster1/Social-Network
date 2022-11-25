#include "member.h"
#include "page.h"



Member::Member()
{
	name = nullptr;
	status_array =nullptr;
	pages = nullptr;
	friends = nullptr;
}


Member::Member(const char* _name, const Date& date):birth_date(date)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	numOfFriends = numOfPages = numOfStatuses = 0;
	physical_numOfFriends = physical_numOfPages = physical_numOfStatuses = 1;
	status_array = new Status *[physical_numOfStatuses];
	pages = new Fan_page *[physical_numOfPages];
	friends = new Member *[physical_numOfFriends];
}





Member::~Member()
{
	for (int i = 0; i < numOfStatuses; i++)
		delete status_array[i];
	delete[] status_array;
	delete[] name;
	delete[] pages;
	delete[] friends;
}


void Member::shiftBackMemberArr(int index)
{
	
	for (int i = index; i < numOfFriends-1; i++)
	{
		friends[i] = friends[i + 1];
	}
}


void Member::shiftBackPagesArr(int index)
{
	
	for (int i = index; i < numOfPages-1; i++)
	{
		pages[i] = pages[i + 1];
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

	int index = _member.getFriendsSize();;
	if (this == _member.getMemberFromFriends(index - 1))
	{
		_member.removeFriend(*this);
	}

}


void Member::removePage(Fan_page& page)
{
	int i = 0;
	bool found = false;
	while (found == false)
	{
		if (pages[i] == &page) 
			found = true;
		else
			i++;
	}

	shiftBackPagesArr(i);
	reSizePagesArr(&pages, numOfPages , numOfPages - 1);
	numOfPages--;

	int index = page.getFansSize();
	if (this == page.getfanFromFans(index - 1));
	{
		page.delete_Fan(*this, index - 1);
	}
}

void Member::add_status(Status& status)
{
	if(numOfStatuses==physical_numOfStatuses)
	{
		physical_numOfStatuses *= 2;
		reSizeStatusArr(&status_array, numOfStatuses, physical_numOfStatuses);
	}
	status_array[numOfStatuses]=&status;
	numOfStatuses++;
}


void Member::addFriend(Member& _member)
{
	if (numOfFriends == physical_numOfFriends)
	{
		physical_numOfFriends *= 2;
		reSizeMemberArr(&friends, numOfFriends,physical_numOfFriends);
	}
	friends[numOfFriends] = &_member;
	numOfFriends++;

	int index = _member.getFriendsSize();;
	if (this != _member.getMemberFromFriends(index - 1))
	{
		_member.addFriend(*this);
	}
}


void Member::add_page(Fan_page& page)
{
	if (numOfPages == physical_numOfPages)
	{
		physical_numOfPages *= 2;
		reSizePagesArr(&pages, numOfPages,physical_numOfPages);
	}
	pages[numOfPages] = &page;
	numOfPages++;

	int index = page.getFansSize();
	if (this != page.getfanFromFans(index - 1))
	{
		page.add_Fan(*this);
	}

}


void Member::reSizeStatusArr(Status*** status_array, int old_size, int new_size)
{
	Status** temp = new Status*[new_size];
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



void Member::copyStatusArr(Status** dest, Status** src,int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];
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
		cout << i + 1 << ". ";
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
		status_array[i]->showStatus();
		cout << endl;
	}
	
	if (numOfStatuses == 0)
		cout << "the member: " << name << " has no statuses" << endl;
}

void Member::showTenRecentStatuses()
{
	for (int i = numOfStatuses - 1; i >= numOfStatuses - 10 && i >= 0; i--)
	{
		status_array[i]->showStatus();
		cout << endl;
	}

}

void Member::showAllFriendsTenStatuses()
{
	for (int i = 0; i < numOfFriends; i++)
	{
		friends[i]->showName();
		cout << "'s ten recent statuses: " << endl;
		friends[i]->showTenRecentStatuses();
		cout << endl;
	}

}


Member* Member::getMemberFromFriends(int i)
{
	return friends[i];
}



char* Member::getName()
{
	return name;
}

int Member::getFriendsSize()
{
	return numOfFriends;
}

int Member::getNumOfPages()
{
	return numOfPages;
}


Fan_page* Member::getPageFromPages(int i)
{
	return pages[i];
}



