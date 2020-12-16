#pragma once
#ifndef __TAG
#define __TAG

#include <string>
#include <vector>

class Tag
{
	std::string tagName;
	std::vector<int> tagValues;
	std::string tagParam;
	
	std::vector<int> mapToInteger(const std::vector<std::string>& values) const;
	
public:
	Tag(std::string &name, std::vector<std::string> &values, std::string additionalParam = "");

	std::vector<int> executeTag();
	void addValues(const std::vector<int>&);
	std::string getTagName() const;
	std::vector<int> getValues() const;
};

#endif
