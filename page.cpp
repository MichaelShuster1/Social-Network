#include "page.h"
#include "member.h"
using namespace std;



Fan_page::Fan_page(const string& name) noexcept(false)
{
	if (name.size() == EMPTY)
		throw EmptyPageNameException();
	if (!isChar(*(name.begin())))
		throw invalidPageNameException();
	this->name = name;
}



Fan_page::Fan_page(const Fan_page& other)
{
	fans = other.fans;
	statuses = other.statuses;
	name = other.name;
}


Fan_page::Fan_page(Fan_page&& other) noexcept(true)
{
	fans = move(other.fans);
	statuses = move(other.statuses);
	name = move(other.name);
}


void Fan_page::addStatus(Status* status)
{
	statuses.push_back(status->clone());
}


void Fan_page::operator+=(Member& member) noexcept(false)
{
    if (isFanCheck(member))
	{
		throw AddFanException();
	}
	
	if (fans.size() == fans.capacity())
		fans.reserve(fans.capacity() * INCREASE_RATE);
	fans.push_back(&member);

	if (!member.isPageFollower(*this))
	{
		member.addPage(*this);
	}
}


bool Fan_page::operator==(const string& name) const
{
	return (this->name == name);
}


void Fan_page::deleteFan(Member& member) noexcept(false)
{
	auto itr = find(fans.begin(), fans.end(), &member);


	if (fans.size() == 0)
		throw NoFansException();

	if (itr == fans.end())
		throw NotFanException();


	swap(*itr, *fans.rbegin());
	fans.pop_back();

	if(member.isPageFollower(*this))
		member.removePage(*this);
}


void Fan_page::showAllFans() const
{
	int numOfFans = fans.size(),i=1;
	if (numOfFans != EMPTY)
	{
		cout << name << "'s fans are: " << endl;
		auto itrEnd = fans.end();
		for (auto itr=fans.begin(); itr!=itrEnd; ++itr)
		{
			cout << i << ". ";
			(*itr)->showName();
			cout << endl;
			i++;
		}
	}
	else
		cout << "The page: " << name << " has no fans" << endl;
}


void Fan_page::showAllStatuses() const
{ 
	int numOfStatuses = statuses.size();
	auto itrEnd = statuses.end();
	for (auto itr = statuses.begin(); itr!=itrEnd ;++itr)
	{
		cout << (*itr);
		cout << endl;
	}

	if (numOfStatuses == EMPTY)
		cout << "the page " << name << " has no statuses" << endl;
}

void Fan_page::showName() const
{
	cout << name;
}



const string Fan_page::getName() const
{
	return name;
}

int Fan_page::getFansSize() const
{
	return fans.size();
}


bool Fan_page::operator>(const Fan_page& page) const
{
	if (fans.size() > page.fans.size())
		return true;
	return false;
}

bool Fan_page::operator>(const Member& member) const
{
	if (fans.size() > member.getFriendsSize())
		return true;
	return false;
}


bool Fan_page::isFanCheck(const Member& member) const
{
	auto itr = find(fans.begin(), fans.end(), &member);
	if (itr == fans.end())
		return false;
	else
		return true;
}


bool Fan_page::isChar(const char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return true;
	return false;
}