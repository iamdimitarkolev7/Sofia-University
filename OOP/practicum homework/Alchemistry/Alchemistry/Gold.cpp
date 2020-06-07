#include "Gold.h"

bool Gold::interacts(std::string element)
{
	for (std::string el : Fire::interactionList)
	{
		if (el == element)
		{
			return true;
		}
	}
	for (std::string el : Earth::interactionList)
	{
		if (el == element)
		{
			return true;
		}
	}

	return false;
}