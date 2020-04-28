#include "Hall.h"

Hall::Hall()
{
	hallNumber = 0;
	rows = 0;
	places = 0;
}

Hall::Hall(int _hallNumber, int _rows, int _places)
{
	hallNumber = _hallNumber;
	rows = _rows;
	places = _places;

	scheme.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		scheme[i].resize(places);
		for (int j = 0; j < places; j++)
		{
			scheme[i][j] = 0;
		}
	}
}

Hall::Hall(const Hall& other)
{
	hallNumber = other.hallNumber;
	rows = other.rows;
	places = other.places;
	scheme = other.scheme;
}

Hall& Hall::operator=(const Hall& other)
{
	if (this != &other)
	{
		hallNumber = other.hallNumber;
		rows = other.rows;
		places = other.places;
		scheme = other.scheme;
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

int Hall::capacity()
{
	return rows * places;
}

bool Hall::isAvailable(int row, int seat)
{
	if (row > rows)
	{
		std::cout << "Invalid row in this hall!" << std::endl;
		return false;
	}

	if (seat > places)
	{
		std::cout << "Invalid seat in this row of the hall!" << std::endl;
		return false;
	}

	return scheme[row - 1][seat - 1] == 0;
}

int Hall::getFreePlaces()
{
	int result = 0;

	for (int i = 0; i < scheme.size(); i++)
	{
		for (int j = 0; j < scheme[i].size(); j++)
		{
			if (scheme[i][j] == 0)
			{
				result++;
			}
		}
	}

	return result;
}

void Hall::addBooking(int row, int seat)
{
	scheme[row - 1][seat - 1] = 1;
}

int Hall::getBookings()
{
	int result = 0;

	for (int i = 0; i < scheme.size(); i++)
	{
		for (int j = 0; j < scheme[i].size(); j++)
		{
			if (scheme[i][j] == 1)
			{
				result++;
			}
		}
	}

	return result;
}

void Hall::addBuying(int row, int seat)
{
	scheme[row - 1][seat - 1] = 2;
}

int Hall::getBuyings()
{
	int result = 0;

	for (int i = 0; i < scheme.size(); i++)
	{
		for (int j = 0; j < scheme[i].size(); j++)
		{
			if (scheme[i][j] == 2)
			{
				result++;
			}
		}
	}

	return result;
}

void Hall::removeBooking(int row, int seat)
{
	scheme[row - 1][seat - 1] = 0;
}