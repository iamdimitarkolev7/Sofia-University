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

	std::vector<std::string> split(std::string str, std::string delimiter);
	void checkRowsCols(int& rows, int& cols, std::fstream& in);
	std::vector<std::vector<Cell>> createTable(int& rows, int& cols, std::fstream& in);
	std::string checkData(std::fstream& in);
	void print(std::string tableName);

	void run();
	~System();
private:
	System();
};

