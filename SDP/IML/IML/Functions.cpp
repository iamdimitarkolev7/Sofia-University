#include "Functions.h"

#include <numeric>
#include <string>

void Functions::increase(std::list<int>& lst, int value)
{
	std::list<int>::iterator it;

	for (it = lst.begin(); it != lst.end(); ++it)
		*it += value;
}

void Functions::multiply(std::list<int>& lst, int value)
{
	std::list<int>::iterator it;

	for (it = lst.begin(); it != lst.end(); ++it)
		*it *= value;
}

void Functions::agg_sum(std::list<int>& lst)
{
	const int result = std::reduce(lst.begin(), lst.end(), 0, [](int a, int b)->int {return a + b; });
	lst.clear();
	lst.push_back(result);
}

void Functions::agg_pro(std::list<int>& lst)
{
	const int result = std::reduce(lst.begin(), lst.end(), 1, [](int a, int b)->int {return a * b; });
	lst.clear();
	lst.push_back(result);
}

void Functions::agg_avg(std::list<int>& lst)
{
	const int sum = std::reduce(lst.begin(), lst.end(), 0, [](int a, int b)->int {return a + b; });
	const int size = lst.size();
	lst.clear();
	lst.push_back(sum / size);
}

void Functions::agg_first(std::list<int>& lst)
{
	const int result = lst.front();
	lst.clear();
	lst.push_back(result);
}

void Functions::agg_last(std::list<int>& lst)
{
	const int result = lst.back();
	lst.clear();
	lst.push_back(result);
}

void Functions::reverse(std::list<int>& lst)
{
	lst.reverse();
}

void Functions::sort_asc(std::list<int>& lst)
{
	lst.sort();
}

void Functions::sort_dsc(std::list<int>& lst)
{
	lst.sort([](int a, int b)->bool {return a > b; });
}

void Functions::slice(std::list<int>& lst, size_t position)
{
	std::list<int> result;
	size_t helperIndex = 0;
	std::list<int>::iterator it;

	for (it = lst.begin(); it != lst.end(); ++it)
	{
		if (helperIndex >= position)
			result.push_back(*it);

		helperIndex++;
	}

	lst = result;
}

void Functions::remove_duplicates(std::list<int>& lst)
{
	lst.unique();
}
