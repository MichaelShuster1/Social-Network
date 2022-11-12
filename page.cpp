#include "page.h"
#include "member.h"



Fan_page::Fan_page(char* _name)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	num_of_fans = 0;
	num_of_status = 0;
	status_array = nullptr;
	fans = nullptr;
}

void Fan_page::add_Member(Member& member)
{
	
}

Fan_page::~Fan_page()
{
	delete[] name;
	delete[] fans;
	delete[] status_array;
}

void Fan_page::show_all_fans()
{
	int i;
	for (i = 0; i < num_of_fans; i++)
	{
		fans[i].showName();
	}	
}

void Fan_page::show_all_status()
{
	int i;
	for (i = 0; i < num_of_status; i++)
	{
		status_array[i].showStatus();
	}
}

void Fan_page::test()
{
	int n;
}