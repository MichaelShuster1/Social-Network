#include "Entity.h"
using namespace std;


Entity::Entity(const string& name) noexcept(false)
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
	
	*this = other;
}

Entity::Entity(Entity&& other) noexcept(true)
{
	*this = move(other);
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

const string& Entity::getName() const
{
	return name;
}

Entity::~Entity()
{
	DeleteStatuses();
}

void Entity::DeleteStatuses()
{
	auto enditr = statuses.end();
	for (auto itr = statuses.begin(); itr != enditr; ++itr)
	{
		delete *itr;
	}
}

const Entity& Entity::operator=(const Entity& other) noexcept(true)
{
	if (this != &other)
	{
		DeleteStatuses();

		auto enditr = other.statuses.end();

		for (auto itr = other.statuses.begin(); itr != enditr; ++itr)
		{
			this->statuses.push_back((*itr)->clone());
		}

		this->name = other.name;
	}
	return *this;
}


const Entity& Entity::operator=(Entity&& other) noexcept(true)
{
	if (this != &other)
	{
		DeleteStatuses();
		statuses = move(other.statuses);
		name = other.name;
	}
	return *this;
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
		in.ignore();
		if (strcmp(statusType.c_str(), typeid(Status).name() + 6) == 0)
			statuses.push_back(new Status(in));
		else if (strcmp(statusType.c_str(), typeid(StatusPicture).name() + 6) == 0)
			statuses.push_back(new StatusPicture(in));
		else
			statuses.push_back(new StatusVideo(in));
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
		getline(in, entity.name);
		in >> numOfStatuses;
		in.ignore();
		entity.loadStatusesFromFile(numOfStatuses,(ifstream&)in);
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
	
	if (typeid(os) == typeid(ofstream))
	{
		os << entity.name << endl;
		os << entity.statuses.size() << endl;
		entity.saveStatusesToFile((ofstream&)os);
	}
	else
	{
		cout <<entity.name;
	}

	entity.toOs(os);
	return os;
}