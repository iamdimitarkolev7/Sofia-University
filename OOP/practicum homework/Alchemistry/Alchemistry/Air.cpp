#include "Air.h"

Air::Air()
{
	amount = 0;
}

Air::Air(int _amount)
{
	amount = _amount;
}

Air::Air(const Air& other)
{
	amount = other.amount;

	interactionList.clear();
	for (int i = 0; i < other.interactionList.size(); i++)
	{
		interactionList.push_back(other.interactionList[i]);
	}
}

Air& Air::operator= (const Air& other)
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

bool Air::interacts(std::string element)
{
	std::string element1, element2;

	if (element == "Stone")
	{
		element1 = "Fire";
		element2 = "Water";
	}
	else if (element == "Energy")
	{
		element1 = "Water";
		element2 = "Air";
	}
	else if (element == "Spirit")
	{
		element1 = "Air";
		element2 = "Air";
	}
	else if (element == "Gold")
	{
		element1 = "Fire";
		element2 = "Earth";
	}

	if (element1 != "" && element2 != "")
	{
		for (std::string el : interactionList)
		{
			if (el == element1 || el == element2)
			{
				return true;
			}
		}
	}
	else
	{
		for (std::string el : interactionList)
		{
			if (el == element)
			{
				return true;
			}
		}
	}

	return false;
}

int Air::getAmount()
{
	return amount;
}