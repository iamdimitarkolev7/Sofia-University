#pragma once
#ifndef __TAG
#define __TAG

#include <list>
#include <string>
#include <vector>
#include <numeric>

class Tag
{
	std::string tagName;
	std::list<double> tagValues;
	std::string tagParam;
	
	std::list<double> mapToList(const std::vector<std::string>& values) const;
	bool validName(std::string name) const;
	bool validParam(std::string param) const;
	
public:
	Tag(std::string& name);
	Tag(std::string& name, std::vector<std::string> values = {}, std::string additionalParam = "");

	std::list<double> executeTag();
	void addValues(std::list<double> values);
	std::string getTagName() const;
	std::list<double> getValues() const;
};

#endif
