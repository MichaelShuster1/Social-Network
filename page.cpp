#include "page.h"
#include "member.h"
using namespace std;


Fan_page::Fan_page(const char* _name)
{
	if (_name != nullptr)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	else
		name = nullptr;
	numOfFans = numOfStatuses = 0;
	physical_numOfFans = physical_numOfStatus = 1;
	status_array = new Status*[physical_numOfStatus];
	fans = new Member*[physical_numOfFans];
}

Fan_page::Fan_page()
{
	name = nullptr;
	status_array = nullptr;
	fans = nullptr;
}


Fan_page::~Fan_page()
{
	for (int i = 0; i < numOfStatuses; i++)
		delete status_array[i];
	delete[] status_array;
	delete[] name;
	delete[] fans;
}


void Fan_page::add_status(Status& status)
{
	if (numOfStatuses == physical_numOfStatus)
	{
		physical_numOfStatus *= 2;
		reSizeStatusArr(&status_array, numOfStatuses,physical_numOfStatus);
	}
	status_array[numOfStatuses]=&status;
	numOfStatuses++;
}


void Fan_page::reSizeStatusArr(Status*** status_array,int old_size ,int new_size)
{
	Status** temp = new Status*[new_size];
	copyStatusArr(temp, *status_array,getMin(old_size,new_size));
	delete[] (*status_array);
	(*status_array) = temp;
}


int Fan_page::getMin(int num1, int num2) const
{
	if (num1 < num2)
		return num1;
	return num2;
}


void Fan_page::copyStatusArr(Status** dest, Status** src,int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i]=src[i];
}


void Fan_page::add_Fan(Member& member)
{
	if(numOfFans==physical_numOfFans)
	{
		physical_numOfFans *= 2;
		reSizeMemberArr(&fans, numOfFans,physical_numOfFans);
	}
	fans[numOfFans] = &member;
	numOfFans++;

	int index = member.getPagesSize();
	if (index != 0)
	{
		if (this != member.getPageFromPages(index - 1))
		{
			member.add_page(*this);
		}
	}
	else
		member.add_page(*this);
}


void Fan_page::reSizeMemberArr(Member*** member_array, int old_size, int new_size)
{
	Member** temp = new Member*[new_size];
	copyMemberArr(temp, *member_array,getMin(old_size,new_size));
	delete[] (*member_array);
	(*member_array) = temp;
}

void Fan_page::copyMemberArr(Member** dest, Member** src,int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];
}


void Fan_page::shiftBackMemberArr(int index)
{
	for (int i = index; i < numOfFans - 1; i++)
	{
		fans[i] = fans[i + 1];
	}
}


void Fan_page::delete_Fan(Member& member,int index)
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
		cout << "the page: " << name << " has no fans" << endl;
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
	return name;
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
