#include "Event.h"

Event::Event()
{
	name = "";
	hallName = "";
	date = "";
	buyings = 0;
}

Event::Event(const Event& other)
{
	name = other.name;
	hallName = other.hallName;
	date = other.date;
	buyings = other.buyings;
}

Event& Event::operator=(const Event& other)
{
	if (this != &other)
	{
		name = other.name;
		hallName = other.hallName;
		date = other.date;
		buyings = other.buyings;
	}

	return *this;
}

std::string Event::getDate() const
{
	return date;
}

std::string Event::getName() const
{
	return name;
}

std::string Event::getHallName() const
{
	return hallName;
}

int Event::getBuyings() const
{
	return buyings;
}