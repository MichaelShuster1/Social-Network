#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <string>
#include <vector>
#include "date.h"

using namespace std;


class Member;
class Status;

class Fan_page
{
private:
	//char* name;
	string name;
	//Member** fans;
	vector<Member*>fans;
	//Status** status_array;
	vector<Status*>status_array;
	int numOfFans;
	int numOfStatuses;

	/*
	void reSizeStatusArr(); //changes the size of the given arr to new size
	void copyStatusArr(Status** dest); //duplicates the values of src arr to dest arr
	void reSizeFansArr(); //changes the size of the given arr to new size
	void copyFansArr(Member** dest); //duplicates the values of src arr to dest arr
	*/
	void shiftBackMemberArr(int index); //deletes the element in index place in the fans arr

public:
	Fan_page(const string& name); //c'tor
	Fan_page(const Fan_page& other);
	Fan_page(Fan_page&& other);
	~Fan_page(); //d'tor
	//void addFan(Member& member);adds the given member as a fan to this page
	void operator+=(Member& member);//adds the given member as a fan to this page
	void deleteFan(Member& member,int index); //delete the given member from the this page and vice versa
	void addStatus(Status& status); //adds the given status to this page
	void showAllFans() const; //shows all the fans of this page
	void showAllStatuses() const; //shows all the statuses of this page
	void showName() const; //shows the name of this page
	const char* getName() const; //returns the name of this page
	int getFansSize() const ; //returns the number of fans of this page
	Member* getfanFromFans(int i); //returns the fan in the i'nd place in the fans arr of this page
	int getfanIndexFromFans(Member& member) const; //returns the index of the given member in the fans arr of this page
	bool operator>(const Fan_page& member) const;

};




#endif // !PAGE_H