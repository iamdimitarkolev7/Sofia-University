#include "Spirit.h"

bool Spirit::interacts(std::string other)
{
	for (std::string el : Air::interactionList)
	{
		if (el == other)
		{
			return true;
		}
	}

	return false;
}