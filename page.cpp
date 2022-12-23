#include "page.h"
#include "member.h"



Fan_page::Fan_page(const string& name) throw(const char*)
{
	if (name.size() == EMPTY)
		throw "error: the name of the new page is empty!";
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


void Fan_page::addStatus(Status& status)
{
	statuses.push_back(Status(status));
}


void Fan_page::operator+=(Member& member)  throw(const char*)
{
    if (isFanCheck(member))
	{
		throw "error:The user you chose is already a fan of this page!";
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


void Fan_page::deleteFan(Member& member) throw (const char*)
{
	auto itr = find(fans.begin(), fans.end(), &member);

	if (itr == fans.end())
		throw "the given member is not a fan of the given page";

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
		(*itr).showStatus();
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