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
	Member** fans;
	Status* status_array;
	int numOfFans;
	int numOfStatus;
	int physical_numOfFans;
	int physical_numOfStatus;

public:
	Fan_page(const char* _name=nullptr);
	~Fan_page();
	void add_Fan(Member& member);
	void delete_Fan(Member& member,int index);
	void add_status(const Status& status);
	void reSizeStatusArr(Status** status_array,int old_size,int new_size);
	int getMin(int num1, int num2);
	void copyStatusArr(Status* dest, Status* src,int size);
	void reSizeMemberArr(Member*** status_array, int old_size, int new_size);
	void copyMemberArr(Member** dest, Member** src,int size);
	void show_all_fans();
	void showAllStatuses();
	void shiftBackMemberArr(int index);
	void showName();
	Member* getfanFromFans(int i);

};




#endif // !PAGE_H