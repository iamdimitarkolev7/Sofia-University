#pragma once
#include <string>

class Ticket
{
protected:
	std::string eventName;
	std::string date;
	int row;
	int seat;
	std::string note;

public:
	Ticket();
	Ticket(const Ticket& ticket);
	Ticket& operator=(const Ticket& ticket);

	std::string getEventName() const;
	std::string getDate() const;
	int getRow() const;
	int getSeat() const;
	std::string getNote() const;
};
