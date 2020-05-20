#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "System.h"
#include "Table.h"
#include "Cell.h"

std::vector<Table> dataBase;
std::vector<std::string> loadedTables;

System& System::i()
{
	static System instance;
	return instance;
}

System::System()
{
	
}

System::~System()
{
	std::cout << "End of the program!" << std::endl;
}

std::vector<std::string> System::split(std::string str, std::string delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	int delimiterIndex = str.find(delimiter);

	while (delimiterIndex != std::string::npos)
	{
		token = str.substr(0, delimiterIndex);
		tokens.push_back(token);
		str.erase(0, delimiterIndex + delimiter.size());
		delimiterIndex = str.find(delimiter);
	}

	tokens.push_back(str);

	return tokens;
}

void System::import(std::string fileName)
{
	std::fstream in(fileName);
	int columns = 0, rows = 0;
	std::string tableName, firstLine;
	
	checkRowsCols(rows, columns, in);

	in.open(fileName);

	if (!in.is_open())
	{
		std::cout << "No such file!" << std::endl;
		return;
	}

	in >> tableName;
	in.ignore();
	std::vector<std::vector<Cell>> table = createTable(rows, columns, in);
	in.close();

	Table tableToAdd(table, tableName);

	if (!tableToAdd.isValid())
	{
		std::cout << "Invalid table! Unsuccessful import!" << std::endl;
		return;
	}

	dataBase.push_back(tableToAdd);
	loadedTables.push_back(tableToAdd.getName());

	std::cout << "Successfully imported table!" << std::endl;
}

void System::showTables()
{
	if (loadedTables.size() == 0)
	{
		std::cout << "No loaded tables!" << std::endl;
		return;
	}
	
	for (int i = 0; i < loadedTables.size(); i++)
	{
		std::cout << (i + 1) << ". " << loadedTables[i] << std::endl;
	}
}

void System::describeTable(std::string name)
{
	if (!isNameValid(name))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}

	for (int i = 0; i < dataBase.size(); i++)
	{
		if (dataBase[i].getName() == name)
			dataBase[i].showInformation();
	}
}

void System::printTable(std::string tableName)
{
	if (!isNameValid(tableName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}

	for (int i = 0; i < dataBase.size(); i++)
	{
		if (dataBase[i].getName() == tableName)
			dataBase[i].print();
	}
}

void System::exportTable(std::string tableName, std::string destFileName)
{
	std::fstream out(destFileName, std::ios::out | std::ios::trunc);

	if (!out.is_open())
	{
		std::cout << "Cannot open/create this file!" << std::endl;
		return;
	}

	if (!isNameValid(tableName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}

	for (int i = 0; i < dataBase.size(); i++)
	{
		if (dataBase[i].getName() == tableName)
		{
			out << dataBase[i].getName() << std::endl;

			std::string line;

			for (int p = 0; p < dataBase[i].getTable().size(); p++)
			{
				line = "";

				for (int k = 0; k < dataBase[i].getTable()[p].size() - 1; k++)
				{
					line += dataBase[i].getTable()[p][k].getData() + " ";
				}

				line += dataBase[i].getTable()[p][dataBase[i].getTable()[p].size() - 1].getData();
				out << line << std::endl;
			}
		}
	}

	out.close();
	std::cout << "Table successfully exported to " << destFileName << std::endl;
}

void System::addColumn(std::string tableName, int pos, std::string type)
{
	if (!isNameValid(tableName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}
	
	for (int i = 0; i < dataBase.size(); i++)
	{
		if (dataBase[i].getName() == tableName)
		{
			if (pos < 0 || pos > dataBase[i].getCols() + 1)
			{
				std::cout << "Invalid column position!" << std::endl;
				return;
			}

			if (type != "integer" && type != "double" && type != "string" && type != "null")
			{
				std::cout << "Invalid type! Supported cell types are: integer, double, string and null" << std::endl;
				return;
			}

			Cell cell("NULL", type);
			dataBase[i].addCol(pos, cell);
		}
	}
}

bool System::isNameValid(std::string name)
{
	for (int i = 0; i < loadedTables.size(); i++)
	{
		if (loadedTables[i] == name)
			return true;
	}

	return false;
}

void System::checkRowsCols(int& rows, int& cols, std::fstream& in)
{
	std::string tableName, firstLine;

	in >> tableName;
	in.ignore();
	getline(in, firstLine);

	for (int i = 0; i < firstLine.size(); i++)
	{
		if (firstLine[i] == '\"')
		{
			i++;

			while (firstLine[i] != '\"')
			{
				i++;
			}

			cols++;
		}
		else if (firstLine[i] == ' ')
			cols++;
		else
			continue;
	}


	for (std::string line; getline(in, line); )
		rows++;

	rows++;

	in.close();
}

std::string System::checkData(std::fstream& in)
{
	char c;
	std::string result;

	while (!in.eof())
	{
		in.get(c);

		if (c == '\"')
		{
			result += c;
			in.get(c);

			while (c != '\"')
			{
				result += c;
				in.get(c);
			}

			result += c;
		}
		else if (c == '\n' || c == '\r')
			break;
		else if (c != ' ' && !in.eof())
			result += c;
		else
			break;
	}

	return result;
}

std::vector<std::vector<Cell>> System::createTable(int& rows, int& cols, std::fstream& in)
{
	std::vector<std::vector<Cell>> result;
	std::string data;

	result.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		result[i].resize(cols);
		for (int j = 0; j < cols; j++)
		{
			data = checkData(in);
			Cell cell(data);
			result[i][j] = cell;
		}
	}

	return result;
}

int System::stringToInt(std::string str)
{
	int startIndex = 0, result = 0;

	if (str[0] == '0')
		startIndex = 1;

	for (int i = startIndex; i < str.size(); i++)
	{
		int digit = str[i] - '0';
		result += digit * pow(10, str.size() - 1 - i);
	}

	return result;
}

void System::run()
{
	std::string input;

    for (;;)
    {
		std::getline(std::cin, input);
		std::string operation = input.substr(0, input.find(" "));

		if (operation == "import")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string fileName = tokens[0];

			import(fileName);
		}
		else if (operation == "showtables")
		{
			showTables();
		}
		else if (operation == "describe")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string name = tokens[0];

			describeTable(name);
		}
		else if (operation == "print")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string name = tokens[0];

			printTable(name);
		}
		else if (operation == "export")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string tableName = tokens[0], destFileName = tokens[1];

			exportTable(tableName, destFileName);
		}
		else if (operation == "select")
		{

		}
		else if (operation == "addcolumn")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string tableName = tokens[0], columnType = tokens[2];
			int columnPos = stringToInt(tokens[1]);

			addColumn(tableName, columnPos, columnType);
		}
		else if (operation == "update")
		{

		}
		else if (operation == "delete")
		{

		}
		else if (operation == "insert")
		{

		}
		else if (operation == "innerjoin")
		{

		}
		else if (operation == "rename")
		{

		}
		else if (operation == "count")
		{

		}
		else if (operation == "aggregate")
		{

		}
		else if (operation == "open")
		{

		}
		else if (operation == "save")
		{

		}
		else if (operation == "saveas")
		{

		}
		else if (operation == "help")
		{

		}
		else if (operation == "exit")
		{

		}
		else
		{
			std::cout << "Unknown command! Type 'help' for available commands." << std::endl;
		}
    }
}