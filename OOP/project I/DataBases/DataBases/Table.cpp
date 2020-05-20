#include <iostream>
#include <vector>
#include "Table.h"
#include "Cell.h"

Table::Table()
{
	name = "";
}

Table::Table(std::vector<std::vector<Cell>> _table, std::string _name)
{
	name = _name;

	table.resize(_table.size());
	for (int i = 0; i < _table.size(); i++)
	{
		table[i].resize(_table[i].size());
		for (int j = 0; j < _table[i].size(); j++)
		{
			table[i][j] = _table[i][j];
		}
	}
}

Table::Table(const Table& other)
{
	name = other.name;

	table.clear();

	for (int i = 0; i < other.table.size(); i++)
	{
		table.push_back(other.table[i]);
	}
}

Table& Table::operator=(const Table& other)
{
	if (this != &other)
	{
		name = other.name;

		table.clear();

		for (int i = 0; i < other.table.size(); i++)
		{
			table.push_back(other.table[i]);
		}
	}

	return *this;
}

std::string Table::getName()
{
	return name;
}

std::vector<std::vector<Cell>> Table::getTable()
{
	return table;
}

bool Table::isValid()
{
	for (int i = 0; i < table[0].size(); i++)
	{
		std::string currentType = table[0][i].getType();

		for (int j = 0; j < table.size(); j++)
		{
			if (table[j][i].getType() != currentType)
			{
				if (table[j][i].getType() == "null")
					continue;
				else
					return false;
			}
		}
	}
}

void Table::print()
{
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			std::cout << table[i][j].getData() << " ";
		}

		std::cout << std::endl;
	}
}

void Table::showInformation()
{
	std::cout << "There are " << table[0].size() << " columns in the selected table: " << std::endl;

	for (int i = 0; i < table[0].size(); i++)
	{
		std::cout << "\t#" << (i + 1) << " column type: " << table[0][i].getType() << std::endl;
	}
}

int Table::getRows()
{
	return table.size();
}

int Table::getCols()
{
	return table[0].size();
}

void Table::addCol(int pos, const Cell& cell)
{
	for (auto& row : table) 
	{
		row.insert(row.begin() + pos, cell);
	}
}

Table::~Table()
{

}