#pragma once
#include <string>
#include <vector>
#include "Cell.h"

class Column
{
private:
	std::string type;
	std::vector<Cell> cells;

public:
	Column();
	Column(const Column& other);
	Column& operator=(const Column& other);

	std::string getType();

	~Column();
};