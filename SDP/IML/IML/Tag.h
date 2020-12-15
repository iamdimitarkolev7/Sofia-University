#pragma once
#ifndef __TAG
#define __TAG

#include <string>
#include <vector>
#include <functional>

using mapFn = int(*)(const int&, const int);

class Tag
{
	std::string tagName;
	std::vector<int> tagValues;
	std::string tagParam;
	
	std::vector<int> mapToInteger(const std::vector<std::string>& values) const;

	std::vector<int> map(mapFn mapFunction);
	std::vector<int> agg(const mapFn reducer, const int& initialValue);
	std::vector<int> srt(const std::function<bool(int)> predicate);
	
public:
	Tag(std::string &name, std::vector<std::string> &values, std::string additionalParam = "");

	std::vector<int> executeTag();
	void addValues(const std::vector<int>&);
	std::string getTagName() const;
	std::vector<int> getValues() const;
};

#endif
