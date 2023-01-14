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
	Entity(const std::string& name) noexcept(false);
	Entity(std::ifstream & inFile);
	Entity(Entity&& other) noexcept(true);
	Entity(const Entity& other);
public:
	virtual ~Entity();
	void addStatus(Status* status); //adds the given status to this page
	virtual void showAllStatuses() const = 0; //shows all the of the entity's statuses 
	static bool isChar(const char c); //checks if the input is char
	const std::string getName() const; //returns the name of this entity
	bool operator==(const std::string& name) const; //checks if the entity's name have the given name
	void loadStatusesFromFile(int numOfStatuses,std::ifstream& in);  //loads the entity's statuses from the file
	void saveStatusesToFile(std::ofstream& os) const; //saves the entity's statuses to the file
	friend std::istream& operator>>(std::istream& in, Entity& entity); //prints the entity to the console/file
	friend std::ostream& operator<<(std::ostream& os, const Entity& entity); //gets as input the entity from console/file
	virtual void fromOs(std::istream& in) {};  //used in case the inheriting son doesn't overload the funcion
	virtual void toOs(std::ostream& os) const {}; //used in case the inheriting son doesn't overload the funcion

};











#endif // !ENTITY_H

