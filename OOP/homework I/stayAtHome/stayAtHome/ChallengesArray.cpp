#include <iostream>
#include <cstring>
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