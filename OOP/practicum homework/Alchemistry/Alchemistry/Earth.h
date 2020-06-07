#pragma once
#include <string>
#include <vector>

class Earth
{
protected:
	int amount;
	std::vector<std::string> interactionList = { "Fire", "Air", "Water" };

public:
	Earth();
	Earth(const Earth& other);
	Earth(int _amount);
	Earth& operator= (const Earth& other);

	bool interacts(std::string other);

	int getAmount();
};

