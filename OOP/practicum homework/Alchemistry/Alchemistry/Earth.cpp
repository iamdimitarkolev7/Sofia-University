#include "Earth.h"

Earth::Earth()
{
	amount = 0;
}

Earth::Earth(int _amount)
{
	amount = _amount;
}

Earth::Earth(const Earth& other)
{
	amount = other.amount;

	interactionList.clear();
	for (int i = 0; i < other.interactionList.size(); i++)
	{
		interactionList.push_back(other.interactionList[i]);
	}
}

Earth& Earth::operator= (const Earth& other)
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

bool Earth::interacts(std::string other)
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
			if (el == other)
			{
				return true;
			}
		}
	}

	return false;
}

int Earth::getAmount()
{
	return amount;
}