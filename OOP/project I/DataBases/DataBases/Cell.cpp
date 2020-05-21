#include "Cell.h"

Cell::Cell()
{
	data = "NULL";
	type = "null";
}

Cell::Cell(std::string _data)
{
	data = _data;
	checkType(data);
}

Cell::Cell(std::string _data, std::string _type)
{
	data = _data;
	type = _type;
}

Cell::Cell(const Cell& other)
{
	type = other.type;
	data = other.data;
}

Cell& Cell::operator=(const Cell& other)
{
	if (this != &other)
	{
		type = other.type;
		data = other.data;
	}

	return *this;
}

Cell::~Cell()
{

}

std::string Cell::getType()
{
	return type;
}

std::string Cell::getData()
{
	return data;
}

void Cell::setData(std::string _data)
{
	data = _data;
}

void Cell::checkType(std::string data)
{
	if (isInteger(data))
		type = "integer";
	else if (isDouble(data))
		type = "double";
	else if (data == "NULL")
		type = "null";
	else
		type = "string";
}

bool Cell::isInteger(std::string data)
{
	int startIndex = 0;

	if (data[0] == '+' || data[0] == '-')
		startIndex = 1;

	for (int i = startIndex; i < data.length(); i++)
	{
		if (data[i] < '0' || data[i] > '9')
			return false;
	}

	return true;
}

bool Cell::isDouble(std::string data)
{
	try
	{
		std::stod(data);
	}
	catch (...)
	{
		return false;
	}
	return true;
}
