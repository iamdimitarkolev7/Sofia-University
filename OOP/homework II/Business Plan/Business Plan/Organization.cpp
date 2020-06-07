#include "Organization.h"

int _helpA = 50, _helpB = 50, _helpC = 50, _helpD = 50;

Organization::Organization()
{
	organizationAddress = "";
}

Organization::Organization(std::string name, std::string address, Payer* _payer)
{
	this->institutionName = name;
	organizationAddress = address;
	payer = _payer;

	int currentID = payer->getID();

	if (currentID == 1500)
	{
		institutionID = 1000 + _helpA;
		_helpA++;
	}
	else if (currentID == 2500)
	{
		institutionID = 2000 + _helpB;
		_helpB++;
	}
	else if (currentID == 3500)
	{
		institutionID = 3000 + _helpC;
		_helpC++;
	}
	else if (currentID == 4500)
	{
		institutionID = 4000 + _helpD;
		_helpD++;
	}
}

Organization::Organization(const Organization& other)
{
	institutionList.resize(other.institutionList.size());

	for (int i = 0; i < other.institutionList.size(); i++)
	{
		institutionList[i] = other.institutionList[i];
	}

	organizationAddress = other.organizationAddress;
}

Organization& Organization::operator=(const Organization& other)
{
	if (this != &other)
	{
		institutionList.resize(other.institutionList.size());

		for (int i = 0; i < other.institutionList.size(); i++)
		{
			institutionList[i] = other.institutionList[i];
		}

		institutionID = other.institutionID;
		institutionName = other.institutionName;
		organizationAddress = other.organizationAddress;
	}

	return *this;
}

int Organization::getUsersCount()
{
	int result = 0;

	for (int i = 0; i < institutionList.size(); i++)
	{
		result += institutionList[i].getUsersCount();
	}

	return result;
}

bool Organization::isValid()
{
	return institutionList.size() != 0;
}

bool Organization::isCompatibleWith(const Organization& other)
{
	return payer == other.payer;
}

void Organization::addGroup(const Group& group)
{
	institutionList.emplace_back(group);
}

std::string Organization::getAddress()
{
	return organizationAddress;
}