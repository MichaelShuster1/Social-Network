#include "member.h"
#include "page.h"
using namespace std;

//
//Member::Member()
//{
//	name = nullptr;
//	/*status_array =nullptr;*/
//	/*pages = nullptr;
//	friends = nullptr;*/
//}


Member::Member(const string _name, const Date& date):birth_date(date)
{
	/*name = new char[strlen(_name) + 1];
	strcpy(name, _name);*/
	name = _name;
	/*numOfFriends = numOfPages = numOfStatuses = 0;
	physical_numOfFriends = physical_numOfPages = physical_numOfStatuses = 1;*/
	/*status_array = new Status *[physical_numOfStatuses];*/

	/*pages = new Fan_page *[physical_numOfPages];
	friends = new Member *[physical_numOfFriends];*/
}


Member::Member(const Member& other):birth_date(other.birth_date)
{
	this->name = other.name;
	this->friends = other.friends;
	this->pages = other.pages;
	this->statuses = other.statuses;
}

Member::Member(Member&& other) noexcept(true)
{
	this->name = move(other.name);
	this->birth_date = other.birth_date;
	this->friends = move(other.friends);
	this->pages = move(other.pages);
	this->statuses = move(other.statuses);
}


Member::~Member()
{
	int numOfStatuses = statuses.size();
	for (int i = 0; i < numOfStatuses; i++)
		delete statuses[i];
	//delete[] status_array;
	/*delete name;
	delete[] pages;
	delete[] friends;*/
}

//
//void Member::shiftBackMemberArr(int index)
//{
//	
//	for (int i = index; i < numOfFriends-1; i++)
//	{
//		friends[i] = friends[i + 1];
//	}
//}

//
//void Member::shiftBackPagesArr(int index)
//{
//	
//	for (int i = index; i < numOfPages-1; i++)
//	{
//		pages[i] = pages[i + 1];
//	}
//}


void Member::removeFriend(Member& _member)
{
	//int i = 0;
	bool found = false;
	vector<Member*>::iterator itr = friends.begin();
	while (found == false)
	{
		if (*itr == &_member)
			found = true;
		else
			++itr;
	}
	friends.erase(itr);

	//while (found == false)
	//{
	//	if (friends[i] == &_member) 
	//		found = true;
	//	else
	//		i++;
	//}

	/*shiftBackMemberArr(i);
	numOfFriends--;*/


	if (_member.getFriendIndexFromFriends(*this) != -1)
	{
		_member.removeFriend(*this);
	}

}


void Member::removePage(Fan_page& page)
{
	/*int i = 0;*/
	bool found = false;
	vector<Fan_page*>::iterator itr = pages.begin();
	while (found == false)
	{
		if (*itr == &page)
			found = true;
		else
			++itr;
	}
	pages.erase(itr);
	/*while (found == false)
	{
		if (pages[i] == &page) 
			found = true;
		else
			i++;
	}*/


	/*shiftBackPagesArr(i);
	numOfPages--;*/

	int index = page.getfanIndexFromFans(*this);
	if (index != -1);
	{
		page.deleteFan(*this, index);
	}
}

void Member::addStatus(Status& status)
{
	if (statuses.size() == statuses.capacity())
	{
		statuses.reserve(statuses.capacity() * 2);
	}
	statuses.push_back(new Status(status));
	/*if(numOfStatuses==physical_numOfStatuses)
	{
		physical_numOfStatuses *= 2;
		reSizeStatusArr();
	}
	status_array[numOfStatuses]=&status;
	numOfStatuses++;*/
}

/*
void Member::addFriend(Member& _member)
{
	if (numOfFriends == physical_numOfFriends)
	{
		physical_numOfFriends *= 2;
		reSizeFriendsArr();
	}
	friends[numOfFriends] = &_member;
	numOfFriends++;

	int index = _member.getFriendsSize();
	if (index != 0)
	{
		if (this != _member.getMemberFromFriends(index - 1))
		{
			_member.addFriend(*this);
		}
	}
	else
		_member.addFriend(*this);
}
*/

void Member::operator+=(Member& _member)
{
	if (friends.size() == friends.capacity())
	{
		friends.reserve(friends.capacity() * 2);
	}
	/*if (numOfFriends == physical_numOfFriends)
	{
		physical_numOfFriends *= 2;
		reSizeFriendsArr();
	}

	friends[numOfFriends] = &_member;
	numOfFriends++;
	*/

	friends.push_back(&_member);


	int index = _member.getFriendsSize();
	if (index != 0)
	{
		if (this != _member.getMemberFromFriends(index - 1))
		{
			_member+=(*this);
		}
	}
	else
		_member+=(*this);


}


void Member::addPage(Fan_page& page)
{
	if (pages.size() == pages.capacity())
	{
		pages.reserve(pages.capacity() * 2);
	}
	/*if (numOfPages == physical_numOfPages)
	{
		physical_numOfPages *= 2;
		reSizePagesArr();
	
	pages[numOfPages] = &page;
	numOfPages++;
	}*/
	pages.push_back(&page);

	int index = page.getFansSize();
	if (index != 0)
	{
		if (this != page.getfanFromFans(index - 1))
		{
			page+=(*this);
		}
	}
	else
	{
		page+=(*this);
	}

}


//
//void Member::reSizeStatusArr()
//{
//	Status** temp = new Status * [physical_numOfStatuses];
//	copyStatusArr(temp);
//	delete[] status_array;
//	status_array= temp;
//}



//
//void Member::reSizeFriendsArr()
//{
//	Member** temp = new Member * [physical_numOfFriends];
//	copyFriendsArr(temp);
//	delete[] friends;
//	friends = temp;
//}
//
//
//void Member::reSizePagesArr()
//{
//	Fan_page** temp = new Fan_page * [physical_numOfPages];
//	copyPageArr(temp);
//	delete[]pages;
//	pages = temp;
//}

//
//void Member::copyStatusArr(Status** dest)
//{
//	int i;
//	for (i = 0; i < numOfStatuses; i++)
//		dest[i] = status_array[i];
//}

//
//void Member::copyFriendsArr(Member** dest)
//{
//	int i;
//	for (i = 0; i < numOfFriends; i++)
//		dest[i] = friends[i];
//
//}
//
//
//void Member::copyPageArr(Fan_page** dest)
//{
//	int i;
//	for (i = 0; i < numOfPages; i++)
//		dest[i] = pages[i];
//}


void Member::showName() const
{
	cout << name;
}


void Member::showAllFriends() const
{
	int numOfFriends = getFriendsSize();
	if (numOfFriends > 0)
	{
		cout << name << "'s friends are:" << endl;
		for (int i = 0; i < numOfFriends; i++)
		{
			cout << i + 1 << ". ";
			friends[i]->showName();
			cout << endl;
		}
	}	
	else
		cout << name << " has no friends" << endl;
		
}


void Member::showAllStatuses() const
{
	int numOfStatuses = statuses.size();
	for (int i = 0; i < numOfStatuses; i++)
	{
		statuses[i]->showStatus();
		cout << endl;
	}
	
	if (numOfStatuses == 0)
		cout <<name << " has no statuses" << endl;
}


void Member::showTenRecentStatuses() const
{
	int numOfStatuses = statuses.size();
	for (int i = numOfStatuses - 1; (i >= numOfStatuses - 10) && (i >= 0); i--)
	{
		statuses[i]->showStatus();
		cout << endl;
	}

}


void Member::showAllFriendsTenStatuses() const
{
	int numOfFriends = getFriendsSize();
	if (numOfFriends > 0)
	{
		cout <<name<< "'s friends latest 10 statuses:" << endl;
		cout << endl;
		for (int i = 0; i < numOfFriends; i++)
		{
			friends[i]->showName();
			cout << "'s ten recent statuses: " << endl;
			friends[i]->showTenRecentStatuses();
			cout << endl;
		}
	}
	else
	{
		cout << name << " has no friends"<<endl;
	}

}


Member* Member::getMemberFromFriends(int i)
{
	return friends[i];
}



const string Member::getName() const
{
	return name;
}

int Member::getFriendsSize() const
{
	return friends.size();
}

int Member::getPagesSize() const
{
	return pages.size();
}


Fan_page* Member::getPageFromPages(int i)
{
	return pages[i];
}


int Member::getPageIndexFromPages(Fan_page& page) const
{
	int numOfPages = pages.size();
	int i = 0;
	bool found = false;
	while (i < numOfPages && found == false)
	{
		if (pages[i] == &page)
			found = true;

		i++;
	}

	if (found == true)
		return i - 1;
	else
		return -1;
}



int Member::getFriendIndexFromFriends(Member& member) const
{
	int numOfFriends = getFriendsSize();
	int i = 0;
	bool found = false;
	while (i < numOfFriends && found == false)
	{
		if (friends[i] == &member)
			found = true;

		i++;
	}

	if (found == true)
		return i - 1;
	else
		return -1;
}

bool Member::operator>(const Member& member) const
{
	if (getFriendsSize() > member.getFriendsSize())
		return true;
	return false;
}