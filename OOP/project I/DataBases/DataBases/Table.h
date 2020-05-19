#pragma once
#include <string>
#include <vector>
#include "Column.h"

class Table
{
private:
	std::string name;
	std::string destFileName;
	std::vector<std::vector<Cell>> table;

public:
	Table();
	Table(std::vector<std::vector<Cell>> _table, std::string _name);
	Table(const Table& other);
	Table& operator=(const Table& other);

	std::string getName();
	bool isValid();
	void print();
	void showInformation();

	~Table();
};

