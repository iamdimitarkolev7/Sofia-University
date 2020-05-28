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
	void changeName(std::string newName);
	void updateCell(int row, int col, std::string value);
	void deleteRow(int row);
	void printRow(int row);
	void pushRow(std::vector<std::string> data);
	double sumColumn(int col);
	double minElementColumn(int col);
	double maxElementColumn(int col);
	double productColumn(int col);

	~Table();
};

