#include "member.h"
#include "page.h"
using namespace std;


Member::Member(const Member& other):Entity(other),birth_date(other.birth_date)
{
	this->friends = other.friends;
	this->pages = other.pages;
	this->statuses = other.statuses;
}


Member::Member(Member&& other) noexcept(true) :Entity(other), birth_date(other.birth_date)
{
	this->pages = move(other.pages);
	this->friends = move(other.friends);
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
			cout << (**itr) << endl;;
		}
	}	
	else
		cout << name << " has no friends" << endl;
		
}


void Member::showAllStatuses() const
{
	if (statuses.size() == EMPTY)
		cout << name << " has no statuses" << endl;
	else
	{
		Entity::showAllStatuses();
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
			cout << (**itr);
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


void Member::saveFriendsToFile(ofstream& os) const
{
	auto itrF = friends.begin();
	auto itrFEnd = friends.end();
	os << friends.size() << endl;
	for (; itrF != itrFEnd; ++itrF)
		os << (*itrF)->name << endl;
}


void Member::oneSidedLink(Member& member)
{
	friends.push_back(&member);
}


void Member::fromOs(istream& in)
{
	if (typeid(in) != typeid(ifstream))
		in >> birth_date;
}

void Member::toOs(ostream& os) const
{
	if (typeid(os) == typeid(ifstream))
		os << birth_date;
}



