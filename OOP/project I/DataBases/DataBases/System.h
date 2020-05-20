#pragma once
#include <vector>
#include <string>
#include <vector>
#include "Cell.h";

class System
{
public:
	static System& i();
	System(const System&) = delete;
	void operator=(const System&) = delete;


	void import(std::string fileName);
	void showTables();
	void describeTable(std::string name);
	void printTable(std::string tableName);
	void exportTable(std::string tableName, std::string destFileName);
	void addColumn(std::string tableName, int pos ,std::string type);

	void run();

	~System();
private:

	std::vector<std::string> split(std::string str, std::string delimiter);
	void checkRowsCols(int& rows, int& cols, std::fstream& in);
	std::vector<std::vector<Cell>> createTable(int& rows, int& cols, std::fstream& in);
	std::string checkData(std::fstream& in);
	bool isNameValid(std::string name);
	int stringToInt(std::string str);

	System();
};

