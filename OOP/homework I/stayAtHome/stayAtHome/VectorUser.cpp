#include <iostream>
#include <cstring>
#include "VectorUser.h"

VectorUser::VectorUser()
{
	users = nullptr;
	size = 0;
}

VectorUser::~VectorUser()
{
	delete[] users;
}

void VectorUser::push(const User& user)
{
	int newSize = size + 1;

	User* biggerBuffer = new User[newSize];

	if (!biggerBuffer)
	{
		std::cout << "Not enoug memory!" << std::endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		biggerBuffer[i] = users[i];
	}

	biggerBuffer[size] = user;

	delete[] users;

	size = newSize;
	users = biggerBuffer;
}

User& VectorUser::operator[](int i)
{
	return this->users[i];
}

size_t VectorUser::getSize() const
{
	return size;
}

bool VectorUser::contains(const char* userName)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(userName, users[i].getName()) == 0)
		{
			return true;
		}
	}

	return false;
}

void VectorUser::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "User: " << users[i].getName() << std::endl;
	}
}