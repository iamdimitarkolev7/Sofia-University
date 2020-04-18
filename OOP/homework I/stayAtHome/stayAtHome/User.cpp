#include <iostream>
#include <cstring>
#include "User.h"

User::User()
{
	strcpy(name, "");
	strcpy(age, "");
	strcpy(email, "");
	ID = 0;
}

User::User(const char* _name, const char* _age, const char* _email, int _ID)
{
	strcpy(name, _name);
	strcpy(age, _age);
	strcpy(email, _email);
	ID =_ID;
}

User::~User()
{

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

	if (length >= 3 || (age[0] == '9' && age[1] >= '1' && age[1] <= '2'))
	{
		std::cout << "Invalid age! Age must consists only digits and must be in the interval [1-90]" << std::endl;
		return false;
	}

	return true;
}

char* User::getName() const
{
	char* _name;
	int length = strlen(name);

	_name = new char[length];

	strcpy(_name, name);

	return _name;
}

char* User::getAge() const
{
	char* _age;
	int length = strlen(age);

	_age = new char[length];

	strcpy(_age, age);

	return _age;
}

char* User::getEmail() const
{
	char* _email;
	int length = strlen(email);

	_email = new char[length];

	strcpy(_email, email);

	return _email;
}

int User::getID() const
{
	return ID;
}