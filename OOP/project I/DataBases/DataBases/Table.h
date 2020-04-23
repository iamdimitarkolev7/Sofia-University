#pragma once
#include <string>
#include <vector>
#include "Column.h"

class Table
{
private:
	std::string name;
	std::string destFileName;
	std::vector<Column> columns;

public:
	Table();
	Table(const Table& other);
	Table& operator=(const Table& other);

	~Table();
};

