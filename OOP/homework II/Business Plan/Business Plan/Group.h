#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Institution.h"
#include "Payer.h"

class Group : public Institution
{
private:
	std::vector<std::string> peopleList;

public:
	Group();
	Group(std::string name);
	Group(std::string name, Payer* payer);
	Group(const Group& other);
	Group& operator=(const Group& other);

	int getUsersCount();
	bool isValid();
	bool hasMember(std::string name);
	void addMember(std::string personName);
	void print();
};

