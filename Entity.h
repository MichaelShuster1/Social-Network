#ifndef ENTITY_H
#define ENTITY_H
#include <fstream>
#include <string>
#include <list>
#include "status_video.h"
#include "status_picture.h"
#include <vector>


const int BIGZ = 90;
const int BIGA = 65;
const int LITTLEZ = 122;
const int LITTLEA = 97;

class Entity
{
protected:
	std::string name;
	std::list<Status*> statuses;
	Entity(const std::string name) noexcept(false);
	Entity(std::ifstream & inFile);
	Entity(Entity&& other) noexcept(true);
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
	friend std::istream& operator>>(std::istream& in, Entity& entity);
	friend std::ostream& operator<<(std::ostream& os, const Entity& entity);
	virtual void fromOs(std::istream& in) {};
	virtual void toOs(std::ostream& os) const {};

};











#endif // !ENTITY_H

