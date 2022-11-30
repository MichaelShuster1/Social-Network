#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <string.h>
#include "date.h"


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

	void reSizeStatusArr(Status*** status_array, int old_size, int new_size); //changes the size of the given arr to new size
	void copyStatusArr(Status** dest, Status** src, int size); //duplicates the values of src arr to dest arr
	void reSizeMemberArr(Member*** member_array, int old_size, int new_size); //changes the size of the given arr to new size
	void copyMemberArr(Member** dest, Member** src, int size); //duplicates the values of src arr to dest arr
	void shiftBackMemberArr(int index); //deletes the element in index place in the fans arr

public:
	Fan_page(const char* _name); //c'tor
	Fan_page(); //default c'tor
	Fan_page(const Fan_page& other) = delete;
	~Fan_page(); //d'tor
	void addFan(Member& member);//adds the given member as a fan to this page
	void deleteFan(Member& member,int index); //delete the given member from the this page and vice versa
	void addStatus(Status& status); //adds the given status to this page
	void showAllFans() const; //shows all the fans of this page
	void showAllStatuses() const; //shows all the statuses of this page
	void showName() const; //shows the name of this page
	const char* getName() const; //returns the name of this page
	int getFansSize() const ; //returns the number of fans of this page
	Member* getfanFromFans(int i); //returns the fan in the i'nd place in the fans arr of this page
	int getfanIndexFromFans(Member& member) const; //returns the index of the given member in the fans arr of this page

};




#endif // !PAGE_H