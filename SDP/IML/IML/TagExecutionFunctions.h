#pragma once
#ifndef _TAGEXFUNC
#define _TAGEXFUNC
#include <vector>

using mapFn = int(*)(const int&, int);

class TagExecutionFunctions
{
	std::vector<int> map(mapFn mapFunction);
	std::vector<int> agg(const mapFn reducer, const int& initialValue);
	
public:
	static void increase(const std::vector<int>& target, int inc_value);
	static void multiply(const std::vector<int>& target, int mlt_value);

	static void sum(const std::vector<int>& target);
	static void pro(const std::vector<int>& target);
	static void average(const std::vector<int>& target);
	static void first(const std::vector<int>& target);
	static void last(const std::vector<int>& target);

	static void reverse(const std::vector<int>& target);
	static void sortAsc(const std::vector<int>& target);
	static void sortDsc(const std::vector<int>& target);
	static void slice(const std::vector<int>& target, int position);
	static void removeDuplicates(const std::vector<int>& target);
};

#endif
