#include "page.h"
#include "member.h"



Fan_page::Fan_page(const char* _name)
{
	if (name != nullptr)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	else
		name = nullptr;
	num_of_fans = 0;
	num_of_status = 0;
	status_array = nullptr;
	fans = nullptr;
}



Fan_page::~Fan_page()
{
	delete[] name;
	delete[] fans;
	delete[] status_array;
}


void Fan_page::add_status(Status& status)
{
	reSizeStatusArr(&status_array,num_of_status ,num_of_status+1);
	status_array[num_of_status] = status;
	num_of_status++;                                                                                                                    
}


void Fan_page::reSizeStatusArr(Status** status_array,int old_size ,int new_size)
{
	Status* temp = new Status[new_size];
	copyStatusArr(temp, *status_array,getMin(old_size,new_size));
	delete[] (*status_array);
	(*status_array) = temp;
}


int Fan_page::getMin(int num1, int num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}


void Fan_page::copyStatusArr(Status* dest, Status* src,int size)
{
	int i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];
}


void Fan_page::add_Fan(Member& member)
{
	reSizeMemberArr(&fans, num_of_fans, num_of_fans + 1);
	fans[num_of_fans] = &member;
	num_of_fans++;
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
	for (int i = index; i < num_of_fans - 1; i++)
	{
		fans[i] = fans[i + 1];
	}
}


void Fan_page::delete_Fan(Member& member)
{
	int i = 0;
	bool found = false;
	while (found == false)
	{
		if (fans[i] == &member)
			found = true;
		else
			i++;
	}

	shiftBackMemberArr(i);
	reSizeMemberArr(&fans, num_of_fans, num_of_fans - 1);
	num_of_fans--;
}


void Fan_page::show_all_fans()
{
	int i;
	for (i = 0; i < num_of_fans; i++)
		fans[i]->showName();	
}



void Fan_page::showAllStatuses()
{
	for (int i = 0; i < num_of_status; i++)
		status_array[i].showStatus();
}



