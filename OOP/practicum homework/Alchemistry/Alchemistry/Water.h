#pragma once
#include <string>
#include <vector>

class Water
{
protected:
	int amount;
	std::vector<std::string> interactionList = { "Fire", "Air" };

public:
	Water();
	Water(const Water& other);
	Water(int _amount);
	Water& operator= (const Water& other);

	bool interacts(std::string other);

	int getAmount();
};

