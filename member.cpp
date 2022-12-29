#include "member.h"
#include "page.h"
using namespace std;


Member::Member(const string _name, const Date& date) noexcept(false):birth_date(date)
{
	if (_name.size() == EMPTY)
		throw  EmptyUserNameException();
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


void Member::removeFriend(Member& member) noexcept(false)
{

	auto itr = find(friends.begin(), friends.end(), &member);

	if(itr == friends.end())
		throw UnLinkingException();
	
	swap(*itr, *friends.rbegin());
	friends.pop_back();


	if (member.areFriendsCheck(*this))
	{
		member.removeFriend(*this);
	}

}


void Member::removePage(Fan_page& page) noexcept(false)
{
	Fan_page* fan_page;
	auto itr = find(pages.begin(), pages.end(), &page);

	if (itr == pages.end())
		throw RemovePageException();

	swap(*itr, *pages.rbegin());
	fan_page = pages.back();
	pages.pop_back();

	if(fan_page->isFanCheck(*this))
		fan_page->deleteFan(*this);

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
	statuses.push_back(Status(status));
}


void Member::operator+=(Member& _member) noexcept(false)
{

	if (areFriendsCheck((_member)))
		throw UserLinkingException();

	if (friends.size() == friends.capacity())
	{
		friends.reserve(friends.capacity() * INCREASE_RATE);
	}
	
	friends.push_back(&_member);

	if (!_member.areFriendsCheck(*this))
	{
		_member+=(*this);
	}

}


void Member::addPage(Fan_page& page) noexcept(false)
{
	if(isPageFollower(page))
	{
		throw UserLinkingPageException();
	}
	if (pages.size() == pages.capacity())
	{
		pages.reserve(pages.capacity() * INCREASE_RATE);
	}

	pages.push_back(&page);

    if (!page.isFanCheck(*this))
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
}


void Member::showTenRecentStatuses() const
{
	int i = 0;
	auto itr = statuses.rbegin();
	auto itrEnd = statuses.rend();

	if(statuses.size()==EMPTY)
		cout << name << " has no statuses" << endl;
	else
	{
		cout <<name<<"'s ten recent statuses: " << endl;
		for (; itr != itrEnd && i < RANGE; ++itr, i++)
		{
			(*itr).showStatus();
			cout << endl;
		}
	}
	
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
			(*itr)->showTenRecentStatuses();
			cout << endl;
		}
	}
	else
	{
		cout << name << " has no friends"<<endl;
	}
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
	auto itr = find(friends.begin(), friends.end(), &member);
	
	if(itr==friends.end())
		return false;

	return true;

}


bool Member::operator==(const string& name) const
{
	if (this->name == name)
		return true;
	else
		return false;
}