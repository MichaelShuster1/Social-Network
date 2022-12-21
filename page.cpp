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


void Fan_page::operator+=(Member& member)
{
	if (fans.size() == fans.capacity())
		fans.reserve(fans.capacity() * INCREASE_RATE);
	fans.push_back(&member);

	int index = member.getPagesSize();
	if (index != 0)
	{
		if (this != member.getPageFromPages(index - 1))
		{
			member.addPage(*this);
		}
	}
	else
		member.addPage(*this);
}




void Fan_page::deleteFan(Member& member,int index)
{
	auto itrEnd = fans.end();
	auto itr = fans.begin();
	advance(itrEnd, -1);
	advance(itr, index);
	swap(*itr, *itrEnd);
	fans.pop_back();

	if (member.getPageIndexFromPages(*this) != NOT_FOUND)
	{
		member.removePage(*this);
	}
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

Member* Fan_page::getfanFromFans(int i) 
{
	auto itr= fans.begin();
	advance(itr, i);
	return *itr;
}


const char* Fan_page::getName() const
{
	return name.c_str();
}

int Fan_page::getFansSize() const
{
	return fans.size();
}

int Fan_page::getfanIndexFromFans(Member& member) const
{
	auto itr = fans.begin();
	auto itrEnd = fans.end();
	bool found = false;
	int i=0;
	while (itr!=itrEnd && found == false)
	{
		if ( (*itr) == &member)
			found = true;

		++itr;
		i++;
	}
	if (found)
		return i - 1;
	else
		return NOT_FOUND;
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