#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <string.h>


#include "date.h"
#include "hour.h"



using namespace std;
#pragma warning(disable: 4996)


class Member;
class Status;

class Fan_page
{
private:
	char* name;
	Member* fans;
	Status* status_array;
	int num_of_fans;
	int num_of_status;

public:
	Fan_page(char* _name);
	~Fan_page();
	void add_Member(Member& member);
	void delete_Member(Member& member);
	void add_status(Date& date, Hour& hour, char* text);
	void reSizeStatusArr(Status* status_array,int size,int new_size);
	void copyStatusArr(Status* dest, Status* src);
	void deleteStatusArr(Status* arr);
	void show_all_fans();
	void showAllStatuses();

};




#endif // !PAGE_H