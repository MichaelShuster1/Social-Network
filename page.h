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
	Status** status_array;
	int numOfFans;
	int numOfStatuses;
	int physical_numOfFans;
	int physical_numOfStatus;

public:
	Fan_page(const char* _name);
	Fan_page();
	Fan_page(const Fan_page& other) = delete;
	~Fan_page();
	void add_Fan(Member& member);
	void delete_Fan(Member& member,int index);
	void add_status(Status& status);
	void reSizeStatusArr(Status** *status_array,int old_size,int new_size);
	int getMin(int num1, int num2) const;
	void copyStatusArr(Status** dest, Status** src,int size);
	void reSizeMemberArr(Member*** status_array, int old_size, int new_size);
	void copyMemberArr(Member** dest, Member** src,int size);
	void show_all_fans() const;
	void showAllStatuses() const;
	void shiftBackMemberArr(int index);
	void showName() const;
	const char* getName() const;
	int getFansSize() const ;
	Member* getfanFromFans(int i);
	int getfanIndexFromFans(Member& member) const;

};




#endif // !PAGE_H