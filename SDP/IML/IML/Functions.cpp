#include "Functions.h"

#include <numeric>
#include <string>

void Functions::increase(std::list<double>& lst, double value)
{
	std::list<double>::iterator it;

	for (it = lst.begin(); it != lst.end(); ++it)
		*it += value;
}

void Functions::multiply(std::list<double>& lst, double value)
{
	std::list<double>::iterator it;

	for (it = lst.begin(); it != lst.end(); ++it)
		*it *= value;
}

void Functions::agg_sum(std::list<double>& lst)
{
	const double result = std::reduce(lst.begin(), lst.end(), 0, [](double a, double b)->double {return a + b; });
	lst.clear();
	lst.push_back(result);
}

void Functions::agg_pro(std::list<double>& lst)
{
	const double result = std::reduce(lst.begin(), lst.end(), 1, [](double a, double b)->double {return a * b; });
	lst.clear();
	lst.push_back(result);
}

void Functions::agg_avg(std::list<double>& lst)
{
	const double sum = std::reduce(lst.begin(), lst.end(), 0, [](double a, double b)->double {return a + b; });
	const int size = lst.size();
	lst.clear();
	lst.push_back(sum / size);
}

void Functions::agg_first(std::list<double>& lst)
{
	const double result = lst.front();
	lst.clear();
	lst.push_back(result);
}

void Functions::agg_last(std::list<double>& lst)
{
	const int result = lst.back();
	lst.clear();
	lst.push_back(result);
}

void Functions::reverse(std::list<double>& lst)
{
	lst.reverse();
}

void Functions::sort_asc(std::list<double>& lst)
{
	lst.sort();
}

void Functions::sort_dsc(std::list<double>& lst)
{
	lst.sort([](double a, double b)->bool {return a > b; });
}

void Functions::slice(std::list<double>& lst, size_t position)
{
	std::list<double> result;
	size_t helperIndex = 0;
	std::list<double>::iterator it;

	for (it = lst.begin(); it != lst.end(); ++it)
	{
		if (helperIndex >= position)
			result.push_back(*it);

		helperIndex++;
	}

	lst = result;
}

void Functions::remove_duplicates(std::list<double>& lst)
{
	lst.unique();
}
