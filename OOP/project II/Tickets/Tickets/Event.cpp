#include "Event.h"

Event::Event()
{
	name = "";
	hallNumber = 0;
	date = "";
	buyings = 0;
}

Event::Event(std::string _date, int _hallNumber, std::string _name)
{
	name = _name;
	hallNumber = _hallNumber;
	date = _date;
	buyings = 0;
}

Event::Event(const Event& other)
{
	name = other.name;
	hallNumber = other.hallNumber;
	date = other.date;
	buyings = other.buyings;
}

Event& Event::operator=(const Event& other)
{
	if (this != &other)
	{
		name = other.name;
		hallNumber = other.hallNumber;
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

int Event::getHallNumber() const
{
	return hallNumber;
}

int Event::getBuyings() const
{
	return buyings;
}