#ifndef PAGE_H
#define PAGE_H

#include <fstream>
#include <vector>
#include "Entity.h"


class Member;
class Status;

class Fan_page : public Entity
{
private:
	std::vector<Member*>fans;

public:
	Fan_page(const std::string& name) noexcept(false) :Entity(name) {}; //c'tor 1
	Fan_page(std::ifstream& in) :Entity(in) {}; //c'tor 2
	Fan_page(const Fan_page& other); //copy c'tor
	Fan_page(Fan_page&& other) noexcept(true); //move c'tor
	Fan_page& operator+=(Member& member) noexcept(false);//adds the given member as a fan to this page
	bool operator>(const Fan_page& page) const;// checks if the number of fans of this page is bigger then the number of fans of the given page
	bool operator>(const Member& member) const; // checks if the number of fans of this page is bigger the number of friends of the given member 
	void deleteFan(Member& member) noexcept(false); //delete the given member from the this page and vice versa
	void showAllFans() const; //shows all the fans of this page
	void showAllStatuses() const; //shows all the statuses of this page
	int getFansSize() const ; //returns the number of fans of this page
	bool isFanCheck(const Member& member) const;//checks if the given member is a fan of this page
	void saveFansToFile(std::ofstream& os) const;//writes the data of the page's fans to the file
};




#endif // !PAGE_H