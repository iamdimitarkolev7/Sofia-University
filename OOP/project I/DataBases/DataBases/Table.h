#pragma once
#include <string>
#include <vector>
#include "Cell.h"

class Table
{
private:
	std::string name;
	std::vector<std::vector<Cell>> table;

public:
	Table();
	Table(std::vector<std::vector<Cell>> _table, std::string _name);
	Table(const Table& other);
	Table& operator=(const Table& other);

	std::vector<std::vector<Cell>> getTable();
	std::string getName();
	bool isValid();
	void print();
	void showInformation();
	int getRows();
	int getCols();
	void addCol(int pos, const Cell& cell);

	~Table();
};

