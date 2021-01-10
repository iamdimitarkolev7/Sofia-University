#pragma once
#include <list>

class Functions
{
public:
	void increase(std::list<double>&, double value);
	void multiply(std::list<double>&, double value);

	void agg_sum(std::list<double>&);
	void agg_pro(std::list<double>&);
	void agg_avg(std::list<double>&);
	void agg_first(std::list<double>&);
	void agg_last(std::list<double>&);

	void reverse(std::list<double>&);
	void sort_asc(std::list<double>&);
	void sort_dsc(std::list<double>&);
	void slice(std::list<double>&, size_t position);
	void remove_duplicates(std::list<double>&);
};


