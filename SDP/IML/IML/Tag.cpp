#include "Tag.h"
#include "TagExecutionFunctions.h"

Tag::Tag(std::string &name, std::vector<std::string> &values, std::string additionalParam)
{
	//TODO Validation
	tagName = name;
	tagParam = additionalParam;
	tagValues= mapToInteger(values);
}

std::vector<int> Tag::mapToInteger(const std::vector<std::string> &values) const
{
	//TODO error handling
	std::vector<int> result;

	for (size_t i = 0; i < values.size(); i++)
	{
		result.push_back(std::stoi(values[i]));
	}

	return result;
}

std::vector<int> Tag::executeTag()
{
	TagExecutionFunctions f;
	
	if (tagName == "MAP-INC")
		f.increase(tagValues, std::stoi(tagParam.substr(1, tagParam.size() - 2)));
	else if (tagName == "MAP-MLT")
		f.multiply(tagValues, std::stoi(tagParam.substr(1, tagParam.size() - 2)));
	else if (tagName == "AGG-SUM")
		f.sum(tagValues);
	else if (tagName == "AGG-PRO")
		f.pro(tagValues);
	else if (tagName == "AGG-AVG")
		f.average(tagValues);
	else if (tagName == "AGG-FST")
		f.first(tagValues);
	else if (tagName == "AGG-LST")
		f.last(tagValues);
	else if (tagName == "SRT-REV")
		f.reverse(tagValues);
	else if (tagName == "SRT-ORD" && tagParam == "ASC")
		f.sortAsc(tagValues);
	else if (tagName == "SRT-ORD" && tagParam == "DSC")
		f.sortDsc(tagValues);
	else if (tagName == "SRT-SLC")
		f.slice(tagValues, std::stoi(tagParam.substr(1, tagParam.size() - 2)));
	else if (tagName == "SRT-DST")
		f.removeDuplicates(tagValues);
	
	return tagValues;
}

void Tag::addValues(const std::vector<int>& values)
{
	for (int element : values)
	{
		tagValues.push_back(element);
	}
}

std::string Tag::getTagName() const
{
	return tagName;
}

std::vector<int> Tag::getValues() const
{
	return tagValues;
}