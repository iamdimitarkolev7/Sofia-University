#include "TagExecutionFunctions.h"

void TagExecutionFunctions::increase(const std::vector<int>& target, int inc_value)
{
	for (int element : target)
	{
		element += inc_value;
	}
}

void TagExecutionFunctions::multiply(const std::vector<int>& target, int mlt_value)
{
	for (int element : target)
	{
		element *= mlt_value;
	}
}

void TagExecutionFunctions::sum(const std::vector<int>& target)
{
}

void TagExecutionFunctions::pro(const std::vector<int>& target)
{
}

void TagExecutionFunctions::average(const std::vector<int>& target)
{
}

void TagExecutionFunctions::first(const std::vector<int>& target)
{
}

void TagExecutionFunctions::last(const std::vector<int>& target)
{
}

void TagExecutionFunctions::reverse(const std::vector<int>& target)
{
	std::reverse(target.begin(), target.end());
}

void TagExecutionFunctions::sortAsc(const std::vector<int>& target)
{
	//TODO
}

void TagExecutionFunctions::sortDsc(const std::vector<int>& target)
{
	//TODO
}

void TagExecutionFunctions::slice(const std::vector<int>& target, int position)
{
	//TODO
}

void TagExecutionFunctions::removeDuplicates(const std::vector<int>& target)
{
	//TODO
}