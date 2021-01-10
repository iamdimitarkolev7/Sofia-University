#include "Tag.h"
#include <iostream>
#include <stdexcept>
#include "Functions.h"

Tag::Tag(std::string &name, std::vector<std::string> values, std::string additionalParam)
{
	if (validName(name))
		tagName = name;
	if (validParam(additionalParam))
		tagParam = additionalParam;
	
	tagValues= mapToList(values);
}

std::list<double> Tag::mapToList(const std::vector<std::string> &values) const
{
	std::list<double> result;

	for (size_t i = 0; i < values.size(); i++)
	{
		try
		{
			result.push_back(std::stod(values[i]));
		}
		catch(const std::exception &err)
		{
			throw std::logic_error(values[i] + " is not a valid value for " + tagName + " tag");
		}
	}

	return result;
}

std::list<double> Tag::executeTag()
{
	Functions f;
	
	if (tagName == "MAP-INC")
		f.increase(tagValues, std::stod(tagParam.substr(1, tagParam.size() - 2)));
	else if (tagName == "MAP-MLT")
		f.multiply(tagValues, std::stod(tagParam.substr(1, tagParam.size() - 2)));
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
		f.slice(tagValues, std::stod(tagParam.substr(1, tagParam.size() - 2)));
	else if (tagName == "SRT-DST")
		f.remove_duplicates(tagValues);

	return tagValues;
}

void Tag::addValues(std::list<double> values)
{
	std::list<double>::iterator it;

	for (it = values.begin(); it != values.end(); ++it)
	{
		tagValues.push_back(*it);
	}
}

std::string Tag::getTagName() const
{
	return tagName;
}

std::list<double> Tag::getValues() const
{
	return tagValues;
}

bool Tag::validName(std::string name) const
{
	std::vector<std::string> allValidTags = { "MAP-INC", "MAP-MLT", "AGG-SUM", "AGG-PRO", "AGG-AVG",
		"AGG-FST", "AGG-LST", "SRT-REV", "SRT-ORD", "SRT-SLC", "SRT-DST" };

	if (!(std::find(allValidTags.begin(), allValidTags.end(), name) != allValidTags.end()))
	{
		throw std::logic_error(name + " is not a valid tag");
	}

	return true;
}

bool Tag::validParam(std::string param) const
{
	if (tagName == "MAP-INC" || tagName == "MAP-MLT" || tagName == "SRT-SLC")
	{
		try
		{
			double value = std::stod(param.substr(1, param.size() - 2));
		}
		catch (const std::exception& err)
		{
			std::cout << "The param of " << tagName << " must be a valid double number!" << std::endl;
			return false;
		}
	}
	else if (tagName == "SRT-ORD")
	{
		if (param.empty())
		{
			throw std::logic_error("The " + tagName + " must have additional parameter: \"ASC\" or \"DSC\"!");
		}
		if (param != "\"ASC\"" && param != "\"DSC\"")
		{
			throw std::logic_error("The " + tagName + " must have a valid parameter: \"ASC\" or \"DSC\"!");
		}
	}

	return true;
}