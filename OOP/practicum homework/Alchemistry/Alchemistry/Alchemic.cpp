#include "Alchemic.h"

void Alchemic::giveBook(Book book)
{
	alchemicalBook = book;
}

void Alchemic::giveElAmounts(std::vector<int> amounts)
{
	for (int i = 0; i < amounts.size(); i++)
	{
		elementAmounts.push_back(amounts[i]);
	}
}

bool Alchemic::canCreateStone()
{
	return (elementAmounts[0] >= alchemicalBook.getEarthAmount())
		&& (elementAmounts[1] >= alchemicalBook.getFireAmount())
		&& (elementAmounts[2] >= alchemicalBook.getWaterAmount())
		&& (elementAmounts[3] >= alchemicalBook.getAirAmount());
}