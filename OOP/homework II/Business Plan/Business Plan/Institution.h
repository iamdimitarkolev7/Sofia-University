#pragma once
#include <string>
#include <vector>
#include "Payer.h"

class Institution
{
protected:
	std::string institutionName;
	unsigned int institutionID;
	Payer* payer;

public:
	Institution();
	Institution(std::string name, Payer* payer);
	Institution(const Institution& other);
	Institution& operator=(const Institution& other);

	Payer* mainPayer();
	unsigned int getInstitutionID();
	std::string getInstitutionName();
};

