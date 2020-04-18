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

void ChallengesArray::push(const Challenge& challenge)
{
	int newSize = size + 1;

	Challenge* biggerBuffer = new Challenge[newSize];

	if (!biggerBuffer)
	{
		std::cout << "Not enoug memory!" << std::endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		biggerBuffer[i] = challenges[i];
	}

	biggerBuffer[size] = challenge;

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
	}
}