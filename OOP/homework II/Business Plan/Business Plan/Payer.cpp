#include "Payer.h"

Payer::Payer()
{
	payerName = "";
}

Payer::Payer(std::string name, int _id, std::function<bool(int, int)> rule)
{
	payerName = name;
	id = _id;
	payerMemberRule = rule;
}

Payer::Payer(const Payer& other)
{
	payerName = other.payerName;
	id = other.id;
}

Payer& Payer::operator=(const Payer& other)
{
	if (this != &other)
	{
		payerName = other.payerName;
		id = other.id;
	}

	return *this;
}

std::string Payer::getName()
{
	return payerName;
}

unsigned int Payer::getID()
{
	return id;
}

bool Payer::applyRule(int personID, int groupID)
{
	return payerMemberRule(personID, groupID);
}