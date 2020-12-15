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

std::vector<int> Tag::map(mapFn mapFunction)
{
	const int additional_param = std::stoi(tagParam.substr(1, tagParam.size() - 2));
	std::vector<int> result;
	
	for (int element : tagValues)
	{
		element = mapFunction(element, additional_param);
		result.push_back(element);
	}

	return result;
}

std::vector<int> Tag::agg(const mapFn reducer, const int& initialValue)
{
	std::vector<int> result;
	int res = initialValue;

	for (int el : tagValues)
	{
		res = reducer(res, el);
	}

	result.push_back(res);
	return result;
}

std::vector<int> Tag::executeTag()
{
	TagExecutionFunctions f;
	
	if (tagName == "MAP-INC")
		tagValues = map(f.increase);
	else if (tagName == "MAP-MLT")
		tagValues = map(f.multiply);
	else if (tagName == "AGG-SUM")
		tagValues = agg(f.sum, 0);
	else if (tagName == "AGG-PRO")
		tagValues = agg(f.multiply, 1);
	else if (tagName == "AGG-AVG")
	{
		const int tagValuesInitialSize = tagValues.size();
		tagValues = agg(f.sum, 0);
		tagValues[0] /= tagValuesInitialSize;
	}
	
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