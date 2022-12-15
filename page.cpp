#include "page.h"
#include "member.h"



Fan_page::Fan_page(const string& name)
{
	this->name = name;
	numOfFans = numOfStatuses = 0;
}



Fan_page::Fan_page(const Fan_page& other)
{
	fans = other.fans;
	status_array = other.status_array;
	name = other.name;
	numOfFans = other.numOfFans;
	numOfStatuses = other.numOfStatuses;
}


Fan_page::Fan_page(Fan_page&& other)
{
	fans = other.fans;
	status_array = other.status_array;
	name = other.name;
	numOfFans = other.numOfFans;
	numOfStatuses = other.numOfStatuses;
	other.numOfFans = 0;
	other.numOfStatuses = 0;
}


Fan_page::~Fan_page()
{
	for (int i = 0; i < numOfStatuses; i++)
		delete status_array[i];
}


void Fan_page::addStatus(Status& status)
{
	if (status_array.size() ==status_array.capacity())
		status_array.reserve(status_array.capacity() * 2);

	status_array.push_back(new Status(status));
	numOfStatuses++;
}

/*
void Fan_page::reSizeStatusArr()
{
	Status** temp = new Status*[physical_numOfStatus];
	copyStatusArr(temp);
	delete[] status_array;
	status_array = temp;
}





void Fan_page::copyStatusArr(Status** dest)
{
	int i;
	for (i = 0; i < numOfStatuses; i++)
		dest[i]=status_array[i];
}


void Fan_page::addFan(Member& member)
{
	if(numOfFans==physical_numOfFans)
	{
		physical_numOfFans *= 2;
		reSizeFansArr();
	}
	fans[numOfFans] = &member;
	numOfFans++;

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
*/

void Fan_page::operator+=(Member& member)
{
	if (fans.size() == fans.capacity())
		fans.reserve(fans.capacity() * 2);
	fans.push_back(&member);
	numOfFans++;

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

/*
void Fan_page::reSizeFansArr()
{
	Member** temp = new Member*[physical_numOfFans];
	copyFansArr(temp);
	delete[] fans;
	fans = temp;
}

void Fan_page::copyFansArr(Member** dest)
{
	int i;
	for (i = 0; i < numOfFans; i++)
		dest[i] = fans[i];
}
*/


void Fan_page::shiftBackMemberArr(int index)
{
	for (int i = index; i < numOfFans - 1; i++)
	{
		fans[i] = fans[i + 1];
	}
}


void Fan_page::deleteFan(Member& member,int index)
{
	shiftBackMemberArr(index);
	numOfFans--;

	if (member.getPageIndexFromPages(*this) != -1)
	{
		member.removePage(*this);
	}
}


void Fan_page::showAllFans() const
{
	if (numOfFans > 0)
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
	for (int i = 0; i < numOfStatuses; i++)
	{
		status_array[i]->showStatus();
		cout << endl;
	}

	if (numOfStatuses == 0)
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
	return numOfFans;
}

int Fan_page::getfanIndexFromFans(Member& member) const
{
	int i = 0;
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
		return -1;
}

bool Fan_page::operator>(const Fan_page& page) const
{
	if (numOfFans > page.numOfFans)
		return true;
	return false;
}