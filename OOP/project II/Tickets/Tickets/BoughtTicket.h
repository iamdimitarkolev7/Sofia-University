#pragma once
#include "Ticket.h"

class BoughtTicket : public Ticket
{
private:
	int ID;

public:
	BoughtTicket(std::string eventName, std::string date, int row, int seat);
	int getID();
};
