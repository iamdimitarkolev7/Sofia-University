#pragma once
#ifndef __TAG
#define __TAG

#include <string>
#include <vector>

class Tag
{
	std::string tagName;
	std::pair<std::string, std::vector<int>> tagParams;
	
public:
	Tag(std::string name, std::vector<int> values, std::string additionalParam = "");
	
};

#endif
