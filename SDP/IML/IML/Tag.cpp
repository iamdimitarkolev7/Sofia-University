#include "Tag.h"

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

void Tag::execute_map_inc() const
{
	const int additionalParam = std::stoi(tagParam.substr(1, tagParam.size() - 2));

	for (int element : tagValues)
	{
		element += additionalParam;
	}
}

void Tag::execute_map_mlt() const
{
	const int additionalParam = std::stoi(tagParam.substr(1, tagParam.size() - 2));

	for (int element : tagValues)
	{
		element *= additionalParam;
	}
}

void Tag::execute_agg_sum() const
{
	//TODO
}

void Tag::execute_agg_pro() const
{
	//TODO
}

void Tag::execute_agg_avg() const
{
	//TODO
}

void Tag::execute_agg_fst() const
{
	//TODO
}

void Tag::execute_agg_lst() const
{
	//TODO
}

void Tag::execute_srt_rev() const
{
	//TODO
}

void Tag::execute_srt_ord() const
{
	//TODO
}

void Tag::execute_srt_slc() const
{
	//TODO
}

void Tag::execute_srt_dst() const
{
	//TODO
}

Tag::Tag(std::string &name, std::vector<std::string> &values, std::string additionalParam)
{
	//TODO Validation
	tagName = name;
	tagParam = additionalParam;
	tagValues= mapToInteger(values);
}

std::vector<int> Tag::executeTag()
{
	if (tagName == "MAP-INC")
		execute_map_inc();
	if (tagName == "MAP-MLT")
		execute_map_mlt();
	if (tagName == "AGG-SUM")
		execute_agg_sum();
	if (tagName == "AGG-PRO")
		execute_agg_pro();
	if (tagName == "AGG-AVG")
		execute_agg_avg();
	if (tagName == "AGG-FST")
		execute_agg_fst();
	if (tagName == "AGG-LST")
		execute_agg_lst();
	if (tagName == "SRT-REV")
		execute_srt_rev();
	if (tagName == "SRT-ORD")
		execute_srt_ord();
	if (tagName == "SRT-SLC")
		execute_srt_slc();
	if (tagName == "SRT-DST")
		execute_srt_dst();

	return tagValues;
}

void Tag::addValues(const std::vector<int>& values)
{
	for (int element : values)
	{
		tagValues.push_back(element);
	}
}
