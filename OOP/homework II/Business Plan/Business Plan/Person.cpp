#include "Person.h"

int a = 1, b = 1, c = 1, d = 1;

Person::Person()
{
	personName = "";
	insuranceID = 0;
	payer = nullptr;
}

Person::Person(std::string _name, Payer* _payer)
{
	personName = _name;
	payer = _payer;

	int currentID = payer->getID();

	if (currentID == 1500)
	{
		insuranceID = 1500 + a;
		a++;
	}
	else if (currentID == 2500)
	{
		insuranceID = 2500 + b;
		b++;
	}
	else if (currentID == 3500)
	{
		insuranceID = 3500 + c;
		c++;
	}
	else if (currentID == 4500)
	{
		insuranceID = 4500 + d;
		d++;
	}
}

Person::Person(const Person& other)
{
	personName = other.personName;
	insuranceID = other.insuranceID;
	payer = other.payer;
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		personName = other.personName;
		insuranceID = other.insuranceID;
		payer = other.payer;
	}

	return *this;
}

std::string Person::getName()
{
	return personName;
}

unsigned int Person::getInsuranceID()
{
	return insuranceID;
}

Payer* Person::getPayer()
{
	return payer;
}

bool Person::hasPayer()
{
	return payer != nullptr;
}