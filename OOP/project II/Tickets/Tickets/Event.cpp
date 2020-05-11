#include "Event.h"

Event::Event()
{
	name = "";
	hallNumber = 0;
	date = "";
	views = 0;
}

Event::Event(std::string _date, int _hallNumber, std::string _name)
{
	name = _name;
	hallNumber = _hallNumber;
	date = _date;
	views = 0;
}

Event::Event(const Event& other)
{
	name = other.name;
	hallNumber = other.hallNumber;
	date = other.date;
	views = other.views;
}

Event& Event::operator=(const Event& other)
{
	if (this != &other)
	{
		name = other.name;
		hallNumber = other.hallNumber;
		date = other.date;
		views = other.views;
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

int Event::getViews() const
{
	return views;
}

void Event::incrementViews()
{
	views++;
}

void Event::decrementViews()
{
	views--;
}
