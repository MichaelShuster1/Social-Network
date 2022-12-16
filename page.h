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
	string name;
	vector<Member*>fans;
	vector<Status*>statuses;

public:
	Fan_page(const string& name); //c'tor
	Fan_page(const Fan_page& other);
	Fan_page(Fan_page&& other) noexcept(true);
	~Fan_page(); //d'tor
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