#include "Ticket.h"

Ticket::Ticket()
{
	eventName = "";
	date = "";
	row = 0;
	seat = 0;
	note = "";
}

Ticket::Ticket(std::string _eventName, std::string _date, int _row, int _seat, std::string _note)
{
	eventName = _eventName;
	date = _date;
	row = _row;
	seat = _seat;
	note = _note;
}

Ticket::Ticket(const Ticket& other)
{
	eventName = other.eventName;
	date = other.date;
	row = other.row;
	seat = other.seat;
	note = other.note;
}

Ticket& Ticket::operator=(const Ticket& other)
{
	if (this != &other)
	{
		eventName = other.eventName;
		date = other.date;
		row = other.row;
		seat = other.seat;
		note = other.note;
	}

	return *this;
}

std::string Ticket::getEventName() const
{
	return eventName;
}

std::string Ticket::getDate() const
{
	return date;
}

int Ticket::getRow() const
{
	return row;
}

int Ticket::getSeat() const
{
	return seat;
}

std::string Ticket::getNote() const
{
	return note;
}