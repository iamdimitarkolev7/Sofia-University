#pragma once

#include <iostream>
#include <vector>

class Hall
{
private:
	int hallNumber;
	int rows;
	int places;
	std::vector<std::vector<int>> scheme;
	/*
		0 means free
		1 means booked
		2 means bought
	*/

public:
	Hall();
	Hall(const Hall& other);
	Hall(int hallNumber, int rows, int places);
	Hall& operator=(const Hall& other);

	int getHallNumber() const;
	int getRows() const;
	int getPlacesOnARow() const;
	int capacity();
	bool isAvailable(int row, int seat);
	int getFreePlaces();
	void addBooking(int row, int seat);
	int getBookings();
	void addBuying(int row, int seat);
	int getBuyings();
	void removeBooking(int row, int seat);
};

