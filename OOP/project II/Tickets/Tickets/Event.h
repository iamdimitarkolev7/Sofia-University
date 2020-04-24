#pragma once
#include <string>
#include "Hall.h"

class Event
{
private:
	std::string date;
	std::string hallName;
	std::string name;
	int buyings;

public:
	Event();
	Event(const Event& other);
	Event& operator=(const Event& other);

	std::string getDate() const;
	std::string getName() const;
	std::string getHallName() const;
	int getBuyings() const;
};

