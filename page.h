#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <string.h>



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
	void add_status(char* text);
	void show_all_status();
	void show_all_fans();

};




#endif // !PAGE_H