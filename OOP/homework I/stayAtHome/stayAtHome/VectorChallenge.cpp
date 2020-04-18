#include <iostream>
#include <cstring>
#include "VectorChallenge.h"

VectorChallenge::VectorChallenge()
{
	challenges = nullptr;
	size = 0;
}

VectorChallenge::~VectorChallenge()
{
	delete[] challenges;
}

size_t VectorChallenge::getSize() const
{
	return size;
}

void VectorChallenge::push(const Challenge& _challenge)
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

Challenge& VectorChallenge::operator[](int i)
{
	return challenges[i];
}

bool VectorChallenge::contains(Challenge& _challengeName)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(_challengeName.getName(), challenges[i].getName()) == 0)
		{
			return true;
		}
	}

	return false;
}

void VectorChallenge::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Challenge: " << challenges[i].getName() << std::endl;
		std::cout << "Occurence: " << challenges[i].getOcc() << std::endl;
	}
}
