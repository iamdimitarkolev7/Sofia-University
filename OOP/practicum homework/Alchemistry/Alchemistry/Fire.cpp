#include "Fire.h"

Fire::Fire()
{
	amount = 0;
}

Fire::Fire(int _amount)
{
	amount = _amount;
}

Fire::Fire(const Fire& other)
{
	amount = other.amount;

	interactionList.clear();
	for (int i = 0; i < other.interactionList.size(); i++)
	{
		interactionList.push_back(other.interactionList[i]);
	}
}

Fire& Fire::operator= (const Fire& other)
{
	if (this != &other)
	{
		amount = other.amount;

		interactionList.clear();
		for (int i = 0; i < other.interactionList.size(); i++)
		{
			interactionList.push_back(other.interactionList[i]);
		}
	}

	return *this;
}

bool Fire::interacts(std::string other)
{
	std::string element1, element2;

	if (other == "Stone")
	{
		element1 = "Fire";
		element2 = "Water";
	}
	else if (other == "Energy")
	{
		element1 = "Water";
		element2 = "Air";
	}
	else if (other == "Spirit")
	{
		element1 = "Air";
		element2 = "Air";
	}
	else if (other == "Gold")
	{
		element1 = "Fire";
		element2 = "Earth";
	}

	if (element1 != "" && element2 != "")
	{
		for (std::string el : interactionList)
		{
			if (el== element1 || el == element2)
			{
				return true;
			}
		}
	}
	else
	{
		for (std::string el : interactionList)
		{
			if (el == other)
			{
				return true;
			}
		}
	}

	return false;
}

int Fire::getAmount()
{
	return amount;
}