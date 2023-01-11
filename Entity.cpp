#include "Entity.h"
using namespace std;


Entity::Entity(const string name) noexcept(false)
{
	if (name.size() == EMPTY)
		throw EmptyEntityNameException();
	if (!isChar(*(name.begin())))
		throw invalidEntityNameException();
	this->name = name;
}

Entity::Entity(ifstream& inFile)
{
	inFile >> *this;
}

Entity::Entity(const Entity& other)
{
	auto enditr = other.statuses.end();

	for (auto itr = other.statuses.begin(); itr != enditr; ++itr)
	{
		this->statuses.push_back(new Status(**itr));
	}

	this->name = other.name;
}

Entity::Entity(Entity&& other) noexcept(true)
{
	this->name = move(other.name);
	this->statuses = move(other.statuses);
}

void Entity::addStatus(Status* status)
{
	statuses.push_back(status->clone());
}


void Entity::showAllStatuses() const
{
	auto itr = statuses.begin();
	auto enditr = statuses.end();

	for (; itr != enditr; ++itr)
	{
		cout << (**itr);
		cout << endl;
	}
	
}

bool Entity::isChar(const char c)
{
	if ((c >= BIGA && c <= BIGZ) || (c >= LITTLEA && c <= LITTLEZ))
		return true;
	return false;
}

const string Entity::getName() const
{
	return name;
}

Entity::~Entity()
{
	auto enditr = statuses.end();
	for (auto itr = statuses.begin(); itr != enditr; ++itr)
	{
		delete* itr;
	}
}


bool Entity::operator==(const string& name) const
{
	if (this->name == name)
		return true;
	else
		return false;
}

void Entity::loadStatusesFromFile(int numOfStatuses,ifstream& in)
{
	string statusType;
	for (int i = 0; i < numOfStatuses; i++)
	{
		in >> statusType;
		if (strcmp(statusType.c_str(), typeid(Status).name() + 6) == 0)
			statuses.push_back(new Status((ifstream&)in));
		else if (strcmp(statusType.c_str(), typeid(StatusPicture).name() + 6) == 0)
			statuses.push_back(new StatusPicture((ifstream&)in));
		else
			statuses.push_back(new StatusVideo((ifstream&)in));
	}
}

void Entity::saveStatusesToFile(std::ofstream& os) const
{
	auto itr = statuses.begin();
	auto itrEnd = statuses.end();
	for (; itr != itrEnd; ++itr)
		os << *(*itr);
}


istream& operator>>(istream& in, Entity& entity)
{
	if (typeid(in) == typeid(ifstream))
	{
		int numOfStatuses;
		string statusType;
		in.ignore();
		getline(in, entity.name);
		in >> numOfStatuses;
		entity.loadStatusesFromFile(numOfStatuses, (ifstream&)in);
	}
	else
	{
		in >> entity.name;
	}

	entity.fromOs(in);
	return in;
}

ostream& operator<<(ostream& os, const Entity& entity)
{
	entity.toOs(os);
	if (typeid(os) == typeid(ofstream))
	{
		os << entity.name << endl << entity.statuses.size() << endl;
		entity.saveStatusesToFile((ofstream&)os);
	}
	else
		cout << "name:" << entity.name;

	return os;
}