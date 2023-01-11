#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>
#include <list>
#include "status_video.h"
#include "status_picture.h"
#include <vector>


const int BIGZ = 90;
const int BIGA = 65;
const int LITTLEZ = 122;
const int LITTLEA = 97;

class Member;

class Entity
{
protected:
	std::string name;
	std::list<Status*> statuses;
	Entity(const std::string name) noexcept(false);
	Entity(const Entity& other);
public:
	virtual ~Entity();
	void addStatus(Status* status);
	virtual void showAllStatuses() const = 0;
	static bool isChar(const char c);
	const std::string getName() const;
	bool operator==(const std::string& name) const;
	void loadStatusesFromFile(int numOfStatuses, std::ifstream& in);
	void saveStatusesToFile(std::ofstream& os) const;

};











#endif // !ENTITY_H

