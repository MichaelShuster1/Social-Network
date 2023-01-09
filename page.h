#ifndef PAGE_H
#define PAGE_H

#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "date.h"




class Member;
class Status;

class Fan_page
{
private:
	std::string name;
	std::vector<Member*>fans;
	std::list<Status*>statuses;

public:
	Fan_page(const std::string& name) noexcept(false); //c'tor
	Fan_page(const Fan_page& other); //copy c'tor
	Fan_page(Fan_page&& other) noexcept(true); //move c'tor
	~Fan_page(); //d'tor
	void operator+=(Member& member) noexcept(false);//adds the given member as a fan to this page
	bool operator==(const std::string& name) const; //checks if the page have the given name
	void deleteFan(Member& member) noexcept(false); //delete the given member from the this page and vice versa
	void addStatus(Status* status); //adds the given status to this page
	void showAllFans() const; //shows all the fans of this page
	void showAllStatuses() const; //shows all the statuses of this page
	void showName() const; //shows the name of this page
	const std::string getName() const; //returns the name of this page
	int getFansSize() const ; //returns the number of fans of this page
	bool operator>(const Fan_page& page) const;// checks if the number of fans of this page is bigger then the number of fans of the given page
	bool operator>(const Member& member) const; // checks if the number of fans of this page is bigger the number of friends of the given member
	bool isFanCheck(const Member& member) const;//checks if the given member is a fan of this page
	static bool isChar(const char c); //checks if the input is char

};




#endif // !PAGE_H