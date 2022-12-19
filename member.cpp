#include "member.h"
#include "page.h"
using namespace std;


Member::Member(const string _name, const Date& date) throw(const char*):birth_date(date)
{
	if (_name.size() == EMPTY)
		throw "Your name cant be empty!";
	name = _name;
}


Member::Member(const Member& other):birth_date(other.birth_date)
{
	this->name = other.name;
	this->friends = other.friends;
	this->pages = other.pages;
	this->statuses = other.statuses;
}

Member::Member(Member&& other) noexcept(true) :birth_date(other.birth_date)
{
	this->name = move(other.name);
	this->friends = move(other.friends);
	this->pages = move(other.pages);
	this->statuses = move(other.statuses);
}


Member::~Member()
{
	int numOfStatuses = statuses.size();
	for (int i = 0; i < numOfStatuses; i++)
		delete statuses[i];
}


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


	if (_member.getFriendIndexFromFriends(*this) != NOT_FOUND)
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
	if (index != NOT_FOUND);
	{
		page.deleteFan(*this, index);
	}
}

void Member::addStatus(Status& status)
{
	if (statuses.size() == statuses.capacity())
	{
		statuses.reserve(statuses.capacity() * INCREASE_RATE);
	}
	statuses.push_back(new Status(status));
}


void Member::operator+=(Member& _member)
{
	if (friends.size() == friends.capacity())
	{
		friends.reserve(friends.capacity() * INCREASE_RATE);
	}
	
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
		pages.reserve(pages.capacity() * INCREASE_RATE);
	}

	pages.push_back(&page);

	int index = page.getFansSize();
	if (index != EMPTY)
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


void Member::showName() const
{
	cout << name;
}


void Member::showAllFriends() const
{
	int numOfFriends = getFriendsSize();
	if (numOfFriends != EMPTY)
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
	
	if (numOfStatuses == EMPTY)
		cout <<name << " has no statuses" << endl;
}


void Member::showTenRecentStatuses() const
{
	int numOfStatuses = statuses.size();
	for (int i = numOfStatuses - 1; (i >= numOfStatuses - RANGE) && (i >= 0); i--)
	{
		statuses[i]->showStatus();
		cout << endl;
	}

}


void Member::showAllFriendsTenStatuses() const
{
	int numOfFriends = getFriendsSize();
	if (numOfFriends != EMPTY)
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



const char* Member::getName() const
{
	return name.c_str();
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
		return NOT_FOUND;
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
		return NOT_FOUND;
}

bool Member::operator>(const Member& member) const
{
	if (getFriendsSize() > member.getFriendsSize())
		return true;
	return false;
}