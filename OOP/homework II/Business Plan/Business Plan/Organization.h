#pragma once
#include <vector>
#include <string>
#include "Institution.h"
#include "Group.h"

class Organization : public Institution
{
private:
	std::vector<Group> institutionList;
	std::string organizationAddress;

public:
	Organization();
	Organization(std::string name, std::string address, Payer* payer);
	Organization(const Organization& other);
	Organization& operator=(const Organization& other);

	int getUsersCount();
	bool isValid();
	bool isCompatibleWith(const Organization& other);
	void addGroup(const Group& group);
	std::string getAddress();
};

