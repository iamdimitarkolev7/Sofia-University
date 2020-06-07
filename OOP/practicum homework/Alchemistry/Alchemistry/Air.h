#pragma once
#include <string>
#include <vector>

class Air
{
protected:
	int amount;
	std::vector<std::string> interactionList = { "Fire", "Air", "Water", "Earth" };

public:
	Air();
	Air(const Air& other);
	Air(int _amount);
	Air& operator= (const Air& other);

	bool interacts(std::string other);

	int getAmount();
};

