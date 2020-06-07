#include "Institution.h"

int helperA = 1, helperB = 1, helperC = 1, helperD = 1;

Institution::Institution()
{
	institutionName = "";
	institutionID = 0;
	payer = nullptr;
}

Institution::Institution(std::string name, Payer* _payer)
{
	institutionName = name;
	payer = _payer;

	int currentID = payer->getID();

	if (currentID == 1500)
	{
		institutionID = 1000 + helperA;
		helperA++;
	}
	else if (currentID == 2500)
	{
		institutionID = 2000 + helperB;
		helperB++;
	}
	else if (currentID == 3500)
	{
		institutionID = 3000 + helperC;
		helperC++;
	}
	else if (currentID == 4500)
	{
		institutionID = 4000 + helperD;
		helperD++;
	}
}

Institution::Institution(const Institution& other)
{
	institutionName = other.institutionName;
	institutionID = other.institutionID;
	payer = other.payer;
}

Institution& Institution::operator=(const Institution& other)
{
	if (this != &other)
	{
		institutionName = other.institutionName;
		institutionID = other.institutionID;
		payer = other.payer;
	}

	return *this;
}

Payer* Institution::mainPayer()
{
	return payer;
}

unsigned int Institution::getInstitutionID()
{
	return institutionID;
}

std::string Institution::getInstitutionName()
{
	return institutionName;
}