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
	void add_Fan(Member& member);
	void delete_Fan(Member& member);
	void add_status(Status& status);
	void reSizeStatusArr(Status* status_array,int size,int new_size);
	void copyStatusArr(Status* dest, Status* src);
	void reSizeMemberArr(Member* status_array, int size, int new_size);
	void copyMemberArr(Member* dest, Member* src);
	void show_all_fans();
	void showAllStatuses();
	void shiftBackMemberArr(int index);

};




#endif // !PAGE_H