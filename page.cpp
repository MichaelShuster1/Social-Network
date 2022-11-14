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



Fan_page::~Fan_page()
{
	delete[] name;
	delete[] fans;
	delete[] status_array;
}


void Fan_page::add_status(Date& date, Hour& hour, char* text)
{
	Status temp(date, hour, text);
	reSizeStatusArr(status_array,num_of_status ,num_of_status+1);
	status_array[num_of_status] = temp;
	num_of_status++;                                                                                                                    
}


void Fan_page::reSizeStatusArr(Status* status_array,int size ,int new_size)
{
	Status* temp = new Status[new_size];
	copyStatusArr(temp, status_array);
	deleteStatusArr(status_array);
	status_array = temp;
}

void Fan_page::copyStatusArr(Status* dest, Status* src)
{
	int i;
	for (i = 0; i < num_of_status; i++)
		dest[i] = src[i];
}



void Fan_page::deleteStatusArr(Status* arr)
{
	delete[] arr;
}



void Fan_page::add_Fan(Member& member)
{



}



void Fan_page::delete_Fan(Member& member)
{



}


void Fan_page::show_all_fans()
{
	int i;
	for (i = 0; i < num_of_fans; i++)
		fans[i].showName();	
}



void Fan_page::showAllStatuses()
{
	for (int i = 0; i < num_of_status; i++)
		status_array[i].showStatus();

}
