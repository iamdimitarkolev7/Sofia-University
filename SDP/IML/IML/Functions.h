#pragma once
#include <list>

class Functions
{
public:
	void increase(std::list<int>&, int value);
	void multiply(std::list<int>&, int value);

	void agg_sum(std::list<int>&);
	void agg_pro(std::list<int>&);
	void agg_avg(std::list<int>&);
	void agg_first(std::list<int>&);
	void agg_last(std::list<int>&);

	void reverse(std::list<int>&);
	void sort_asc(std::list<int>&);
	void sort_dsc(std::list<int>&);
	void slice(std::list<int>&, size_t position);
	void remove_duplicates(std::list<int>&);
};


