#include <iostream>
#include "Table.h"

Table::Table()
{
	name = "";
	destFileName = "";
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
	destFileName = other.destFileName;

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
		destFileName = other.destFileName;

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
	std::cout << "There are " << table.size() << " columns" << std::endl;

	for (int i = 0; i < table[0].size(); i++)
	{
		std::cout << "#" << (i + 1) << " column type: " << table[0][i].getType() << std::endl;
	}
}

Table::~Table()
{

}