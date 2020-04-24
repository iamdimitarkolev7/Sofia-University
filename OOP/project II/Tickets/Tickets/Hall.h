#pragma once
class Hall
{
private:
	int hallNumber;
	int rows;
	int places;

public:
	Hall();
	Hall(const Hall& other);
	Hall& operator=(const Hall& other);

	int getHallNumber() const;
	int getRows() const;
	int getPlacesOnARow() const;
};

