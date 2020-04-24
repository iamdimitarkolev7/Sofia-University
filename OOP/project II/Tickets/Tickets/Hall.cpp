#include "Hall.h"

Hall::Hall()
{
	hallNumber = 0;
	rows = 0;
	places = 0;
}

Hall::Hall(const Hall& other)
{
	hallNumber = other.hallNumber;
	rows = other.rows;
	places = other.places;
}

Hall& Hall::operator=(const Hall& other)
{
	if (this != &other)
	{
		hallNumber = other.hallNumber;
		rows = other.rows;
		places = other.places;
	}

	return *this;
}

int Hall::getHallNumber() const
{
	return hallNumber;
}

int Hall::getRows() const
{
	return rows;
}

int Hall::getPlacesOnARow() const
{
	return places;
}