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

	//TODO apply map, reduce and sort for better performance
	void execute_map_inc() const;
	void execute_map_mlt() const;
	void execute_agg_sum() const;
	void execute_agg_pro() const;
	void execute_agg_avg() const;
	void execute_agg_fst() const;
	void execute_agg_lst() const;
	void execute_srt_rev() const;
	void execute_srt_ord() const;
	void execute_srt_slc() const;
	void execute_srt_dst() const;
	
public:
	Tag(std::string &name, std::vector<std::string> &values, std::string additionalParam = "");

	std::vector<int> executeTag();
	void addValues(const std::vector<int>&);
};

#endif
