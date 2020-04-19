#include <iostream>
#include <cstring>
#include "User.h"

User::User()
{
	name = nullptr;
	strcpy(age, "");
	strcpy(email, "");
	ID = 0;
}

User::User(const char* _name, const char* _age, const char* _email, int _ID)
{
	name = new char[strlen(_name) + 1];

	strcpy(name, _name);
	strcpy(age, _age);
	strcpy(email, _email);
	ID =_ID;
}

User::~User()
{
	delete[] name;
}

bool User::isValid()
{
	return isNameValid() && isAgeValid();
}

bool User::isNameValid()
{
	for (int i = 0; i < strlen(name); i++)
	{
		if (!isalpha(name[i]))
		{
			std::cout << "Invalid name! Name must consist only letters!" << std::endl;
			return false;
		}
	}
	
	return true;
}

bool User::isAgeValid()
{
	int length = strlen(age);
	int _age;

	if (strcmp(age, "Unknown") == 0)
	{
		return true;
	}

	if (length >= 3 || (age[0] == '9' && age[1] >= '1' && age[1] <= '9'))
	{
		std::cout << "Invalid age! Age must consists only digits and must be in the interval [1-90]" << std::endl;
		return false;
	}

	return true;
}

char* User::getName() const
{
	return name;
}

const char* User::getAge() const
{
	return age;
}

const char* User::getEmail() const
{
	return email;
}

int User::getID() const
{
	return ID;
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		delete[] name;

		name = new char[strlen(other.name) + 1];

		strcpy(name, other.name);
		strcpy(age, other.age);
		strcpy(email, other.email);
		unfinished = other.unfinished;
		ID = other.ID;
	}

	return *this;
}