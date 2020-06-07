#pragma once
#include <string>
#include "Payer.h"

class Person
{
private:
	std::string personName;
	unsigned int insuranceID; // there's id if there's a payer
	Payer* payer;

public:
	Person();
	Person(std::string _name, Payer* _payer);
	Person(const Person& other);
	Person& operator=(const Person& other);

	std::string getName();
	unsigned int getInsuranceID();
	Payer* getPayer();

	bool hasPayer();
};

