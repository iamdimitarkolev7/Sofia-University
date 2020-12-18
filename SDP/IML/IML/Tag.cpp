#include "Tag.h"

#include "Functions.h"

Tag::Tag(std::string &name, std::vector<std::string> values, std::string additionalParam)
{
	//TODO Validation
	tagName = name;
	tagParam = additionalParam;
	tagValues= mapToList(values);
}

std::list<int> Tag::mapToList(const std::vector<std::string> &values) const
{
	//TODO error handling
	std::list<int> result;

	for (size_t i = 0; i < values.size(); i++)
	{
		result.push_back(std::stoi(values[i]));
	}

	return result;
}

std::list<int> Tag::executeTag()
{
	Functions f;
	
	if (tagName == "MAP-INC")
		f.increase(tagValues, std::stoi(tagParam.substr(1, tagParam.size() - 2)));
	else if (tagName == "MAP-MLT")
		f.multiply(tagValues, std::stoi(tagParam.substr(1, tagParam.size() - 2)));
	else if (tagName == "AGG-SUM")
		f.agg_sum(tagValues);
	else if (tagName == "AGG-PRO")
		f.agg_pro(tagValues);
	else if (tagName == "AGG-AVG")
		f.agg_avg(tagValues);
	else if (tagName == "AGG-FST")
		f.agg_first(tagValues);
	else if (tagName == "AGG-LST")
		f.agg_last(tagValues);
	else if (tagName == "SRT-REV")
		f.reverse(tagValues);
	else if (tagName == "SRT-ORD" && tagParam == "\"ASC\"")
		f.sort_asc(tagValues);
	else if (tagName == "SRT-ORD" && tagParam == "\"DSC\"")
		f.sort_dsc(tagValues);
	else if (tagName == "SRT-SLC")
		f.slice(tagValues, std::stoi(tagParam.substr(1, tagParam.size() - 2)));
	else if (tagName == "SRT-DST")
		f.remove_duplicates(tagValues);

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