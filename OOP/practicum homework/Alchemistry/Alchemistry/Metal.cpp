#include "Metal.h"

bool Metal::interacts(std::string other)
{
	std::vector<std::string> updatedInteractionList;
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

	for (std::string el : Fire::interactionList)
	{
		updatedInteractionList.push_back(el);
	}

	for (std::string el : Earth::interactionList)
	{
		updatedInteractionList.push_back(el);
	}

	if (element1 != "" && element2 != "")
	{
		for (std::string el : updatedInteractionList)
		{
			if (el == element1 || el == element2)
			{
				return true;
			}
		}
	}
	else
	{
		for (std::string el : updatedInteractionList)
		{
			if (el == other)
			{
				return true;
			}
		}
	}

	return false;
}
