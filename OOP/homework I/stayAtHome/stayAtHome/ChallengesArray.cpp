#include <iostream>
#include <cstring>
#include <cassert>
#include "ChallengesArray.h"

ChallengesArray::ChallengesArray()
{
	challenges = nullptr;
	size = 0;
}

ChallengesArray::~ChallengesArray()
{
	delete[] challenges;
}

void ChallengesArray::push(const Challenge& _challenge)
{
	int newSize = size + 1;

	Challenge* biggerBuffer = new Challenge[newSize];

	if (!biggerBuffer)
	{
		std::cout << "Not enough memory!" << std::endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		biggerBuffer[i] = challenges[i];
	}

	biggerBuffer[size] = _challenge;

	delete[] challenges;

	size = newSize;
	challenges = biggerBuffer;
}

void ChallengesArray::remove(const char* challengeName)
{
	if (size - 1 < 0)
	{
		return;
	}

	int newSize = size - 1, index = 0;

	Challenge* smallerBuffer = new Challenge[newSize];

	for (int i = 0; i < size; i++)
	{
		if (strcmp(challengeName, challenges[i].getName()) == 0)
		{
			continue;
		}
		else
		{
			smallerBuffer[index] = challenges[i];
			index++;
		}
	}

	if (challenges != nullptr)
	{
		delete[] challenges;
	}

	challenges = smallerBuffer;
	size = newSize;
}

Challenge& ChallengesArray::operator[](int i)
{
	return challenges[i];
}

size_t ChallengesArray::getSize() const
{
	return size;
}

bool ChallengesArray::contains(const char* challengeName)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(challengeName, challenges[i].getName()) == 0)
		{
			return true;
		}
	}

	return false;
}

void ChallengesArray::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Challenge: " << challenges[i].getName() << std::endl;
		std::cout << "Occ: " << challenges[i].getOcc() << std::endl;
	}
}

ChallengesArray& ChallengesArray::operator=(const ChallengesArray& other)
{
	if (this != &other)
	{
		delete[] challenges;
		size = other.size;
		challenges = new Challenge[size];

		for (int i = 0; i < size; i++)
		{
			challenges[i] = other.challenges[i];
		}
	}
	return *this;
}