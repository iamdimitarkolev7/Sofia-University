#include <iostream>
#include <cstring>
#include "Challenge.h"

Challenge::Challenge()
{
	name = nullptr;
	occ = 0;
	rating = 0;
	currSum = 0;
	numOfRaters = 0;
}

Challenge::Challenge(const char* _name)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	occ = 1;
	rating = 0; 
	currSum = 0;
	numOfRaters = 0;
}

Challenge::Challenge(const Challenge& other)
{
	strcpy(name, other.name);
	occ = other.occ;
	rating = other.rating;
	currSum = other.currSum;
	numOfRaters = other.numOfRaters;
}

Challenge::~Challenge()
{
	delete[] name;
}

bool Challenge::isValid()
{
	if (name[0] != '#')
	{
		std::cout << "Invalid challenge! It must start with \'#\'!" << std::endl;
		return false;
	}

	for (int i = 1; i < strlen(name); i++)
	{
		if (name[i] == ' ')
		{
			std::cout << "Invalid challenge! It mustn't contain space!" << std::endl;
			return false;
		}
	}

	if (strlen(name) > 32)
	{
		std::cout << "Invalid challenge! Name of challenge is too long!" << std::endl;
		return false;
	}

	return true;
}

char* Challenge::getName() const
{
	return name;
}

double Challenge::getRating() const
{
	return rating;
}

double Challenge::getCurrSum() const
{
	return currSum;
}

int Challenge::getNumOfRaters() const
{
	return numOfRaters;
}

void Challenge::incrementOcc()
{
	occ++;
}

int Challenge::getOcc() const
{
	return occ;
}

Challenge& Challenge::operator=(const Challenge& other)
{
	if (this != &other)
	{
		delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		occ = other.occ;
		rating = other.rating;
		currSum = other.currSum;
		numOfRaters = other.numOfRaters;
	}
	return *this;
}

void Challenge::print()
{
	std::cout << "name: " << name << std::endl;
	std::cout << "occ: " << occ << std::endl;
}