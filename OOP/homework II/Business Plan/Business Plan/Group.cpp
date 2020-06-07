#include "Group.h"

int helpA = 1, helpB = 1, helpC = 1, helpD = 1;

Group::Group()
{
	institutionName = "";
	institutionID = 0;
	payer = nullptr;
}

Group::Group(std::string name)
{
	institutionName = name;
	institutionID = 0;
	payer = nullptr;
}

Group::Group(std::string name, Payer* _payer)
{
	institutionName = name;
	institutionName = name;
	payer = _payer;

	int currentID = payer->getID();

	if (currentID == 1500)
	{
		institutionID = 1000 + helpA;
		helpA++;
	}
	else if (currentID == 2500)
	{
		institutionID = 2000 + helpB;
		helpB++;
	}
	else if (currentID == 3500)
	{
		institutionID = 3000 + helpC;
		helpC++;
	}
	else if (currentID == 4500)
	{
		institutionID = 4000 + helpD;
		helpD++;
	}
}

Group::Group(const Group& other)
{
	institutionName = other.institutionName;
	institutionID = other.institutionID;
	payer = other.payer;
	peopleList.resize(other.peopleList.size());
	for (int i = 0; i < other.peopleList.size(); i++)
	{
		peopleList[i] = other.peopleList[i];
	}
}

Group& Group::operator=(const Group& other)
{
	if (this != &other)
	{
		institutionName = other.institutionName;
		institutionID = other.institutionID;
		payer = other.payer;
		peopleList.resize(other.peopleList.size());
		for (int i = 0; i < other.peopleList.size(); i++)
		{
			peopleList[i] = other.peopleList[i];
		}
	}

	return *this;
}

int Group::getUsersCount()
{
	return peopleList.size();
}

bool Group::isValid()
{
	return payer != nullptr;
}

bool Group::hasMember(std::string name)
{
	for (int i = 0; i < peopleList.size(); i++)
	{
		if (peopleList[i] == name)
			return true;
	}

	return false;
}

void Group::addMember(std::string personName)
{
	peopleList.push_back(personName);
}

void Group::print()
{
	std::cout << "Name: " << institutionName << " ID: " << institutionID << std::endl;
	std::cout << "Members: " << std::endl;

	for (int i = 0; i < peopleList.size(); i++)
	{
		std::cout << (i + 1) << ". " << peopleList[i] << std::endl;
	}

	std::cout << std::endl;
}