#pragma once
#include <string>

class Cell
{
private:
	std::string type;
	std::string data;

	void checkType(std::string data);
	bool isInteger(std::string data);
	bool isDouble(std::string data);

public:
	Cell();
	Cell(std::string data);
	Cell(std::string data, std::string type);
	Cell(const Cell& other);
	Cell& operator=(const Cell& other);

	std::string getType();
	std::string getData();

	void setData(std::string _data);
	
	~Cell();
};

