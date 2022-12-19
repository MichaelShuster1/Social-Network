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


Fan_page::~Fan_page()
{
	int numOfStatuses = statuses.size();
	for (int i = 0; i < numOfStatuses; i++)
		delete statuses[i];
}


void Fan_page::addStatus(Status& status)
{
	if (statuses.size() == statuses.capacity())
		statuses.reserve(statuses.capacity() * INCREASE_RATE);

	statuses.push_back(new Status(status));
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

	swap(fans[index], fans[fans.size() - 1]);
	fans.pop_back();

	if (member.getPageIndexFromPages(*this) != NOT_FOUND)
	{
		member.removePage(*this);
	}
}


void Fan_page::showAllFans() const
{
	int numOfFans = fans.size();
	if (numOfFans != EMPTY)
	{
		cout << name << "'s fans are: " << endl;
		for (int i = 0; i < numOfFans; i++)
		{
			cout << i + 1 << ". ";
			fans[i]->showName();
			cout << endl;
		}
	}
	else
		cout << "The page: " << name << " has no fans" << endl;
}


void Fan_page::showAllStatuses() const
{ 
	int numOfStatuses = statuses.size();
	for (int i = 0; i < numOfStatuses; i++)
	{
		statuses[i]->showStatus();
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
	return fans[i];
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
	int i = 0,numOfFans=fans.size();
	bool found = false;
	while (i < numOfFans && found == false)
	{
		if (fans[i] == &member)
			found = true;

		i++;
	}

	if (found == true)
		return i-1;
	else
		return NOT_FOUND;
}

bool Fan_page::operator>(const Fan_page& page) const
{
	if (fans.size() > page.fans.size())
		return true;
	return false;
}