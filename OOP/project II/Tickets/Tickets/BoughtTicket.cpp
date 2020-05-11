#include "BoughtTicket.h"

int _id = 1;

BoughtTicket::BoughtTicket(std::string _eventName, std::string _date, int _row, int _seat)
{
	eventName = _eventName;
	date = _date;
	row = _row;
	seat = _seat;
	ID = _id;
	_id++;
}

int BoughtTicket::getID()
{
	return ID;
}