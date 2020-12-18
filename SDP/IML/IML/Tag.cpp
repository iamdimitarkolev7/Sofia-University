#include "Tag.h"

Tag::Tag(std::string &name, std::vector<std::string> values, std::string additionalParam)
{
	//TODO Validation
	tagName = name;
	tagParam = additionalParam;
	tagValues= mapToList(values);
}

std::list<int> Tag::mapToList(const std::vector<std::string> &values) const
{
	//TODO error handling and reading negative numbers
	std::list<int> result;

	for (size_t i = 0; i < values.size(); i++)
	{
		result.push_back(std::stoi(values[i]));
	}

	return result;
}

std::list<int> Tag::executeTag()
{
	if (tagName == "MAP-INC")
	{
		int inc_val = std::stoi(tagParam.substr(1, tagParam.size() - 2));
		std::list<int>::iterator it;

		for (it = tagValues.begin(); it != tagValues.end(); ++it)
			*it += inc_val;
	}
	else if (tagName == "MAP-MLT")
	{
		int mlt_val = std::stoi(tagParam.substr(1, tagParam.size() - 2));
		std::list<int>::iterator it;

		for (it = tagValues.begin(); it != tagValues.end(); ++it)
			*it += mlt_val;
	}
	else if (tagName == "AGG-SUM")
	{
		int result = std::reduce(tagValues.begin(), tagValues.end(), 0,
			[](int a, int b)->int {return a + b; });
		tagValues.clear();
		tagValues.push_back(result);
	}
	else if (tagName == "AGG-PRO")
	{
		const int result = std::reduce(tagValues.begin(), tagValues.end(), 1,
			[](int a, int b)->int {return a * b; });
		tagValues.clear();
		tagValues.push_back(result);
	}
	else if (tagName == "AGG-AVG")
	{
		const int result = std::reduce(tagValues.begin(), tagValues.end(), 0,
			[](int a, int b)->int {return a + b; }) / tagValues.size();
		tagValues.clear();
		tagValues.push_back(result);
	}
	else if (tagName == "AGG-FST")
	{
		const int result = tagValues.front();
		tagValues.clear();
		tagValues.push_back(result);
	}
	else if (tagName == "AGG-LST")
	{
		const int result = tagValues.back();
		tagValues.clear();
		tagValues.push_back(result);
	}
	else if (tagName == "SRT-REV")
		tagValues.reverse();
	else if (tagName == "SRT-ORD" && tagParam == "\"ASC\"")
		tagValues.sort();
	else if (tagName == "SRT-ORD" && tagParam == "\"DSC\"")
		tagValues.sort([](int a, int b)->bool {return a > b; });
	else if (tagName == "SRT-SLC")
	{
		//TODO fix error
		size_t position = std::stoi(tagParam.substr(1, tagParam.size() - 2));
		std::list<int>::iterator it = tagValues.begin();
		
		while (position != 0)
		{
			++it;
			position--;
		}

		tagValues.splice(it, tagValues);
	}
	else if (tagName == "SRT-DST")
		tagValues.unique();

	return tagValues;
}

void Tag::addValues(std::list<int> values)
{
	std::list<int>::iterator it;

	for (it = values.begin(); it != values.end(); ++it)
	{
		tagValues.push_back(*it);
	}
}

std::string Tag::getTagName() const
{
	return tagName;
}

std::list<int> Tag::getValues() const
{
	return tagValues;
}