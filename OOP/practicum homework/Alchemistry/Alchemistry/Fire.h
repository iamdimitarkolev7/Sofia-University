#pragma once
#include <string>
#include <vector>

class Fire
{
protected:
	int amount;
	std::vector<std::string> interactionList = { "Earth", "Water", "Fire" };

public:
	Fire();
	Fire(const Fire& other);
	Fire(int _amount);
	Fire& operator= (const Fire& other);

	bool interacts(std::string other);

	int getAmount();
};

