#pragma once
#include <string>
#include <functional>
using func = bool (*)(unsigned int, unsigned int);

class Payer
{
private:
	std::string payerName;
	unsigned int id;
	std::function<bool (int, int)> payerMemberRule;

public:
	Payer();
	Payer(std::string name, int _id, std::function<bool(int, int)> rule);
	Payer(const Payer& other);
	Payer& operator=(const Payer& other);

	std::string getName();
	unsigned int getID();
	bool applyRule(int personID, int groupID);
};

