#include <iostream>
#include <cstring>
#include "Challenge.h"

Challenge::Challenge()
{
	strcpy(name, "");
	occ = 0;
	rating = 0;
	currSum = 0;
	numOfRaters = 0;
}

Challenge::Challenge(const char* _name)
{
	strcpy(name, _name);
	occ = 1;
	rating = 0; 
	currSum = 0;
	numOfRaters = 0;
}

Challenge::~Challenge()
{

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

	return true;
}

const char* Challenge::getName() const
{
	return name;
}

void Challenge::incrementOcc()
{
	occ++;
}

int Challenge::getOcc()
{
	return occ;
}

Challenge& Challenge::operator=(const Challenge& other)
{
	if (this != &other)
	{
		std::fill_n(name, 512, 0);
		strcpy(name, other.name);
		occ = other.occ;
		rating = other.rating;
		currSum = other.currSum;
	}

	return *this;
}

void Challenge::print()
{
	std::cout << "name: " << name << std::endl;
	std::cout << "occ: " << occ << std::endl;
}