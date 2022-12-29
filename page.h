#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "date.h"

using namespace std;



class Member;
class Status;

class Fan_page
{
private:
	string name;
	vector<Member*>fans;
	list<Status>statuses;

public:
	Fan_page(const string& name) noexcept(false); //c'tor
	Fan_page(const Fan_page& other); //copy c'tor
	Fan_page(Fan_page&& other) noexcept(true); //move c'tor
	void operator+=(Member& member) noexcept(false);//adds the given member as a fan to this page
	bool operator==(const string& name) const; //checks if the page have the given name
	void deleteFan(Member& member) noexcept(false); //delete the given member from the this page and vice versa
	void addStatus(Status& status); //adds the given status to this page
	void showAllFans() const; //shows all the fans of this page
	void showAllStatuses() const; //shows all the statuses of this page
	void showName() const; //shows the name of this page
	const string getName() const; //returns the name of this page
	int getFansSize() const ; //returns the number of fans of this page
	bool operator>(const Fan_page& page) const;// checks if the number of fans of this page is bigger then the number of fans of the given page
	bool operator>(const Member& member) const; // checks if the number of fans of this page is bigger the number of friends of the given member
	bool isFanCheck(const Member& member) const;//checks if the given member is a fan of this page

};




#endif // !PAGE_H