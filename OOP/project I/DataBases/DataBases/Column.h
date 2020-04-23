#pragma once
#include <string>
#include <vector>

class Column
{
private:
	std::string type;
	std::vector<std::string> data;

public:
	Column();
	Column(const Column& other);
	Column& operator=(const Column& other);

	~Column();
};

