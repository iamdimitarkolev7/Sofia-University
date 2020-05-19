#include "Column.h"

Column::Column()
{
	type = "null";
	cells[0].setData("NULL");
}

Column::Column(const Column& other)
{
	type = other.type;
	cells.clear();

	for (int i = 0; i < other.cells.size(); i++)
	{
		cells.push_back(other.cells[i]);
	}
}

Column& Column::operator=(const Column& other)
{
	if (this != &other)
	{
		type = other.type;
		cells.clear();

		for (int i = 0; i < other.cells.size(); i++)
		{
			cells.push_back(other.cells[i]);
		}
	}

	return *this;
}

Column::~Column()
{

}

std::string Column::getType()
{
	return type;
}