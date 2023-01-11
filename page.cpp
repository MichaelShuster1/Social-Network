#include "page.h"
#include "member.h"
using namespace std;



Fan_page::Fan_page(const string& name) noexcept(false):Entity(name)
{
}


Fan_page::Fan_page(ifstream& in)
{
	in >> *this;
}


Fan_page::Fan_page(const Fan_page& other):Entity(other)
{
	fans = other.fans;
}


Fan_page::Fan_page(Fan_page&& other) noexcept(true):Entity(other)
{
	fans = move(other.fans);
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
	Entity::showAllStatuses();

	if (statuses.size() == EMPTY)
		cout << "the page " << name << " has no statuses" << endl;
}

void Fan_page::showName() const
{
	cout << name;
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


ostream& operator<<(ostream& os, const Fan_page& page)
{
	if (typeid(os) == typeid(ofstream))
	{
		os << page.name << endl << page.statuses.size() << endl;
		page.saveStatusesToFile((ofstream&)os);
	}
	else
	{
		os << page.name << endl;
	}
	return os;
}

istream& operator>>(istream& in, Fan_page& page)
{
	if (typeid(in) == typeid(ifstream))
	{
		int i, numOfStatuses;
		getline(in,page.name);
		in >> numOfStatuses;
		if (numOfStatuses == 0)
			in.ignore();
		page.loadStatusesFromFile(numOfStatuses,(ifstream&)in);
	}
	else
	{
		in >> page.name;
	}
	return in;
}


void Fan_page::saveFansToFile(ofstream& os) const
{
	auto itr = fans.begin();
	auto itrEnd = fans.end();
	os << fans.size()<<endl;
	for(; itr != itrEnd; ++itr)
		os << (*itr)->getName()<<endl;

}


