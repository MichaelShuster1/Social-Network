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




void Member::removeFriend(Member& member)
{

	auto itr = find(friends.begin(), friends.end(), &member);

	if(itr == friends.end())
		throw "error: the members you chose are already not linked!";
	
	swap(*itr, *friends.rend());
	friends.pop_back();


	if (find(member.friends.begin(), member.friends.end(), &member) != member.friends.end())
	{
		member.removeFriend(*this);
	}

	/*if (_member.getFriendIndexFromFriends(*this) != NOT_FOUND)
	{
		_member.removeFriend(*this);
	}*/

}


void Member::removePage(Fan_page& page)
{
	Fan_page* fan_page;
	auto itr = find(pages.begin(), pages.end(), &page);

	if (itr == pages.end() )
		throw "the given page is not followed by the given member";

	swap(*itr, *pages.rbegin());
	fan_page = pages.back();
	pages.pop_back();

	if(fan_page->isFanCheck(*this))
		fan_page->deleteFan(*this);

	/*while (found == false)
	{
		if (pages[i] == &page) 
			found = true;
		else
			i++;
	}

	shiftBackPagesArr(i);
	numOfPages--;*/	
}


bool Member::isPageFollower(const Fan_page& page) const
{
	auto itr = find(pages.begin(), pages.end(), &page);
	if (itr == pages.end())
		return false;
	else
		return true;
}

void Member::addStatus(Status& status)
{
	/*if (statuses.size() == statuses.capacity())
	{
		statuses.reserve(statuses.capacity() * INCREASE_RATE);
	}*/
	statuses.push_back(Status(status));
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
	auto itr = friends.begin();
	auto enditr = friends.end();
	int i = 1;
	if (numOfFriends != EMPTY)
	{
		cout << name << "'s friends are:" << endl;
		for (; itr != enditr; ++itr, i++)
		{
			cout << i << ". ";
			(*itr)->showName();
			cout << endl;
		}
	}	
	else
		cout << name << " has no friends" << endl;
		
}


void Member::showAllStatuses() const
{
	auto itr = statuses.begin();
	auto enditr = statuses.end();

	if (statuses.size() == EMPTY)
		cout << name << " has no statuses" << endl;
	else
	{
		for (; itr != enditr; ++itr)
		{
			(*itr).showStatus();
			cout << endl;
		}
	}

	
	//int numOfStatuses = statuses.size();
	/*for (int i = 0; i < numOfStatuses; i++)
	{
		statuses[i]->showStatus();
		cout << endl;
	}
	
	if (numOfStatuses == EMPTY)
		cout <<name << " has no statuses" << endl;*/
}


void Member::showTenRecentStatuses() const
{
	auto itr = statuses.rbegin();
	auto itrEnd = statuses.rend();
	int size = statuses.size();
	int i = 0;
	for (; itr != itrEnd && i < RANGE; ++itr, i++)
	{
		(*itr).showStatus();
		cout << endl;

	}
	/*int numOfStatuses = statuses.size();
	for (int i = numOfStatuses - 1; (i >= numOfStatuses - RANGE) && (i >= 0); i--)
	{
		statuses[i]->showStatus();
		cout << endl;
	}*/

}


void Member::showAllFriendsTenStatuses() const
{
	auto itr = friends.begin();
	auto itrEnd = friends.end();
	int numOfFriends = getFriendsSize();
	if (numOfFriends != EMPTY)
	{
		cout <<name<< "'s friends latest 10 statuses:" << endl;
		cout << endl;
		for (; itr != itrEnd; ++itr)
		{
			(*itr)->showName();
			cout << "'s ten recent statuses: " << endl;
			(*itr)->showTenRecentStatuses();
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
	auto itr = friends.begin();
	advance(itr, i);
	return *itr;
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
	auto itr = pages.begin();
	advance(itr, i);
	return *itr;
}


int Member::getPageIndexFromPages(Fan_page& page) const
{
	auto itr = pages.begin();
	auto itrEnd = pages.end();
	int i = 0;
	bool found = false;
	while (itr != itrEnd && found == false)
	{
		if ((*itr) == &page)
			found = true;

		++itr;
		i++;
	}

	if (found == true)
		return i - 1;
	else
		return NOT_FOUND;
}



int Member::getFriendIndexFromFriends(Member& member) const
{
	auto itr = friends.begin();
	auto itrEnd = friends.end();
	int i = 0;
	bool found = false;

	while (itr != itrEnd && found == false)
	{
		if ((*itr) == &member)
			found = true;

		++itr;
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


bool Member::operator>(const Fan_page& page) const
{
	if (getFriendsSize() > page.getFansSize())
		return true;
	return false;
}


bool Member::areFriendsCheck(const Member& member) const
{
	auto itr = friends.begin();
	auto itrEnd = friends.end();

	for (; itr != itrEnd; ++itr)
	{
		if (&member == (*itr))
			return true;
	}

	return false;

	/*int friends_size = system_members[index1].getFriendsSize();
	for (int i = 0; i < friends_size; i++)
	{
		if (&system_members[index2] == (system_members[index1].getMemberFromFriends(i)))
			return true;
	}

	return false;*/
}

bool Member::operator==(const string& name) const
{
	if (this->name == name)
		return true;
	else
		return false;
}