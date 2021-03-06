#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "System.h"
#include "Table.h"
#include "Cell.h"

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
	std::cout << "Exiting program..." << std::endl;
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

//Sample Table from file:
/*
TableName
123 123.02 "Hello Dimitar" 15.5
15 -66.3 "Zdr Mitko" NULL
123 +5.04 "kolev" NULL
NULL -2.5 NULL NULL
NULL NULL NULL NULL
*/
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

	if (isNameValid(tableName))
	{
		std::cout << "There is already a table with such name!" << std::endl;
		return;
	}

	dataBase.push_back(tableToAdd);

	if(file.is_open())
	{
		int len = tableToAdd.getName().length();
		file.write((char*)&len, sizeof(len));
		file.write((char*)&tableToAdd.getName()[0], len);

		int rows = tableToAdd.getRows();
		int cols = tableToAdd.getCols();

		file.write((char*)&rows, sizeof(rows));
		file.write((char*)&cols, sizeof(cols));

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				len = tableToAdd.getTable()[i][j].getData().length();
				file.write((char*)&len, sizeof(len));
				file.write((char*)&tableToAdd.getTable()[i][j].getData()[0], len);
			}
		}
	}

	std::cout << "Successfully imported table!" << std::endl;
}

void System::showTables()
{
	if (dataBase.size() == 0)
	{
		std::cout << "No loaded tables!" << std::endl;
		return;
	}

	int ind = 1;
	
	for (int i = 0; i < dataBase.size(); i++)
	{
		if (dataBase[i].getName() == "" || dataBase[i].getName() == " ")
		{
			continue;
		}

		std::cout << ind << ". " << dataBase[i].getName() << std::endl;
		ind++;
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
	if (!isNameValid(tableName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}
	
	std::fstream out(destFileName, std::ios::out | std::ios::trunc);

	if (!out.is_open())
	{
		std::cout << "Cannot open/create this file!" << std::endl;
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
			if (pos < 0 || pos > dataBase[i].getCols())
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

	std::cout << "Successfully added column!" << std::endl;
}

void System::rename(std::string oldName, std::string newName)
{
	if (!isNameValid(oldName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}

	if (isNameValid(newName))
	{
		std::cout << "The new name of the table must be unique!" << std::endl;
		return;
	}

	for (int i = 0; i < dataBase.size(); i++)
	{
		if (dataBase[i].getName() == oldName)
			dataBase[i].changeName(newName);
	}

	std::cout << "Successfully changed " << oldName << " to " << newName << std::endl;
}

void System::countRows(std::string tableName, int searchColumn, std::string searchValue)
{
	if (!isNameValid(tableName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}

	for (int i = 0; i < dataBase.size(); i++)
	{
		if (tableName == dataBase[i].getName())
		{
			if (searchColumn < 1 || searchColumn > dataBase[i].getCols())
			{
				std::cout << "Invalid column!" << std::endl;
				return;
			}
			
			for (int p = 0; p < dataBase[i].getRows(); p++)
			{
				for (int k = 0; k < dataBase[i].getCols(); k++)
				{
					if (k == (searchColumn - 1))
					{
						if (dataBase[i].getTable()[p][k].getData() == searchValue)
						{
							std::cout << "Number of columns: " << dataBase[i].getCols() << std::endl;
							return;
						}
					}
				}
			}
		}
	}

	std::cout << "No such value in the selected column!" << std::endl;
}

void System::update(std::string tableName, int searchColumn, std::string searchValue, int targetColumn, std::string targetValue)
{
	if (!isNameValid(tableName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}

	bool doneWork = false;

	for (int i = 0; i < dataBase.size(); i++)
	{
		if (tableName == dataBase[i].getName())
		{
			if (searchColumn < 1 || searchColumn > dataBase[i].getCols() 
				|| targetColumn < 1 || targetColumn > dataBase[i].getCols())
			{
				std::cout << "Invalid column!" << std::endl;
				return;
			}

			for (int p = 0; p < dataBase[i].getRows(); p++)
			{
				/*for (int k = 0; k < dataBase[i].getCols(); k++)
				{
					if (k == (searchColumn - 1))
					{
						if (dataBase[i].getTable()[p][k].getData() == searchValue)
						{
							for (int m = 0; m < dataBase[i].getRows(); m++)
							{
								for (int n = 0; n < dataBase[i].getCols(); n++)
								{
									if (n == (targetColumn - 1))
									{
										Cell cell(targetValue);

										if (dataBase[i].getTable()[m][n].getType() != cell.getType())
										{
											if (dataBase[i].getTable()[m][n].getType() != "null")
											{
												std::cout << "You cannot change cell\'s data from one type to another!"
													<< std::endl;
												return;
											}
										}


										dataBase[i].updateCell(m, n, targetValue);
										doneWork = true;
									}
								}
							}
						}
					}
				}*/
				if (searchValue == dataBase[i].getTable()[p][searchColumn - 1].getData())
				{
					Cell cell(targetValue);

					if (dataBase[i].getTable()[p][targetColumn - 1].getType() != cell.getType())
					{
						if (dataBase[i].getTable()[p][targetColumn - 1].getType() != "null")
						{
							std::cout << "You cannot change cell\'s data from one type to another!"
								<< std::endl;
							return;
						}
					}
					dataBase[i].updateCell(p, targetColumn - 1, targetValue);
					doneWork = true;
				}
			}
		}
	}

	if (doneWork)
	{
		std::cout << "Successfully updated data!" << std::endl;
	}
	else
	{
		std::cout << "Search value does not exist in the searched column or is not correct!" << std::endl;
	}
}

void System::deleteRow(std::string tableName, int searchColumn, std::string searchValue)
{
	if (!isNameValid(tableName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}

	bool doneWork = false;

	for (int i = 0; i < dataBase.size(); i++)
	{
		if (tableName == dataBase[i].getName())
		{
			if (searchColumn < 1 || searchColumn > dataBase[i].getCols())
			{
				std::cout << "Invalid column!" << std::endl;
				return;
			}

			for (int p = 0; p < dataBase[i].getRows(); p++)
			{
				for (int k = 0; k < dataBase[i].getCols(); k++)
				{
					if (k == (searchColumn - 1))
					{
						if (dataBase[i].getTable()[p][k].getData() == searchValue)
						{
							dataBase[i].deleteRow(p);
							doneWork = true;
							p--;
						}
					}
				}
			}
		}
	}

	if (doneWork)
	{
		std::cout << "Successfully deleted row!" << std::endl;
	}
	else
	{
		std::cout << "Search value does not exist in the searched column or is not correct!" << std::endl;
	}
}

void System::selectRows(std::string tableName, int searchColumn, std::string searchValue)
{
	if (!isNameValid(tableName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}

	bool doneWork = false;

	for (int i = 0; i < dataBase.size(); i++)
	{
		if (dataBase[i].getName() == tableName)
		{
			if (searchColumn < 1 || searchColumn > dataBase[i].getCols())
			{
				std::cout << "Invalid column!" << std::endl;
				return;
			}

			for (int p = 0; p < dataBase[i].getRows(); p++)
			{
				for (int k = 0; k < dataBase[i].getCols(); k++)
				{
					if (k == (searchColumn - 1))
					{
						if (dataBase[i].getTable()[p][k].getData() == searchValue)
						{
							dataBase[i].printRow(p);
							std::cout << std::endl;
							doneWork = true;
						}
					}
				}
			}
		}
	}

	if (!doneWork)
	{
		std::cout << "Search value does not exist in the searched column or is not correct!" << std::endl;
	}
}

void System::insertRow(std::string tableName, std::vector<std::string> data)
{
	if (!isNameValid(tableName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}

	Table newTable;

	for (int i = 0; i < dataBase.size(); i++)
	{
		if (dataBase[i].getName() == tableName)
		{
			newTable = dataBase[i];
		}
	}

	if (data.size() > newTable.getCols())
	{
		std::cout << "Too many parameters for " << newTable.getName() << " table!" << std::endl;
		return;
	}

	newTable.pushRow(data);

	if (newTable.isValid())
	{
		for (int i = 0; i < dataBase.size(); i++)
		{
			if (dataBase[i].getName() == tableName)
			{
				dataBase[i] = newTable;
			}
		}

		std::cout << "Successfully added row!" << std::endl;
	}
	else
	{
		std::cout << "The row is not valid for the selected table!" << std::endl;
	}
}

void System::aggregate(std::string tableName, int searchColumn, std::string searchValue, int targetColumn, std::string operation)
{
	if (!isNameValid(tableName))
	{
		std::cout << "No such loaded table!" << std::endl;
		return;
	}

	bool found = false;

	for (int i = 0; i < dataBase.size(); i++)
	{
		if (tableName == dataBase[i].getName())
		{
			if (searchColumn < 1 || searchColumn > dataBase[i].getCols()
				|| targetColumn < 1 || targetColumn > dataBase[i].getCols())
			{
				std::cout << "Invalid column!" << std::endl;
				return;
			}

			for (int p = 0; p < dataBase[i].getRows(); p++)
			{
				for (int k = 0; k < dataBase[i].getCols(); k++)
				{
					if (k == (searchColumn - 1))
					{
						if (dataBase[i].getTable()[p][k].getData() == searchValue)
						{
							found = true;
						}
					}
				}
			}

			if (!found)
			{
				std::cout << "No such value in selected column!" << std::endl;
				return;
			}

			for (int p = 0; p < dataBase[i].getRows(); p++)
			{
				for (int k = 0; k < dataBase[i].getCols(); k++)
				{
					if (k == (targetColumn - 1))
					{
						if (operation == "sum")
						{
							if (dataBase[i].getTable()[p][k].getType() == "string")
							{
								std::cout << "Sum operation is only supported with integer and double types!" << std::endl;
								return;
							}
							else if (dataBase[i].getTable()[p][k].getType() == "integer")
							{
								std::cout << "Sum: " << dataBase[i].sumColumn(targetColumn - 1) << std::endl;
								return;
							}
							else if (dataBase[i].getTable()[p][k].getType() == "double")
							{
								std::cout << "Sum: " << dataBase[i].sumColumn(targetColumn - 1) << std::endl;
								return;
							}
						}
						else if (operation == "product")
						{
							if (dataBase[i].getTable()[p][k].getType() == "string")
							{
								std::cout << "Product operation is only supported with integer and double types!" << std::endl;
								return;
							}
							else if (dataBase[i].getTable()[p][k].getType() == "integer")
							{
								std::cout << "Product: " << dataBase[i].productColumn(targetColumn - 1) << std::endl;
								return;
							}
							else if (dataBase[i].getTable()[p][k].getType() == "double")
							{
								std::cout << "Product: " << dataBase[i].productColumn(targetColumn - 1) << std::endl;
								return;
							}
						}
						else if (operation == "maximum")
						{
							if (dataBase[i].getTable()[p][k].getType() == "string")
							{
								std::cout << "Maximum operation is only supported with integer and double types!" << std::endl;
								return;
							}
							else if (dataBase[i].getTable()[p][k].getType() == "integer")
							{
								std::cout << "Max: " << dataBase[i].maxElementColumn(targetColumn - 1) << std::endl;
								return;
							}
							else if (dataBase[i].getTable()[p][k].getType() == "double")
							{
								std::cout << "Max: " << dataBase[i].maxElementColumn(targetColumn - 1) << std::endl;
								return;
							}
						}
						else if (operation == "minimum")
						{
							if (dataBase[i].getTable()[p][k].getType() == "string")
							{
								std::cout << "Minimum operation is only supported with integer and double types!" << std::endl;
								return;
							}
							else if (dataBase[i].getTable()[p][k].getType() == "integer")
							{
								std::cout << "Min: " << dataBase[i].minElementColumn(targetColumn - 1) << std::endl;
								return;
							}
							else if (dataBase[i].getTable()[p][k].getType() == "double")
							{
								std::cout << "Min: " << dataBase[i].minElementColumn(targetColumn - 1) << std::endl;
								return;
							}
						}
						else
						{
							std::cout << "Wrong operation!" << std::endl;
							return;
						}

					}
				}
			}
		}
	}
}

void System::open(std::string path)
{
	if (file.is_open())
	{
		std::cout << "There is already an opened file!" << std::endl;
		return;
	}

	std::ifstream in(path);

	if (!in.is_open())
	{
		file.open(path, std::ios::out | std::ios::binary);
		file.close();
		file.open(path, std::ios::in | std::ios::out | std::ios::binary);
	}
	else
	{
		if (!in.is_open())
		{
			std::cout << "Error!" << std::endl;
			return;
		}
		if (in.peek() == std::ifstream::traits_type::eof())
		{
			file.open(path, std::ios::out, std::ios::binary);
			file.close();
			file.open(path, std::ios::in | std::ios::out | std::ios::binary);

			if (!file.is_open())
			{
				std::cout << "Error!" << std::endl;
				return;
			}

			std::vector<std::string> tokens = split(path, "\\");
			fileName = tokens[tokens.size() - 1];
			std::cout << "Successfully opened " << fileName << std::endl;

			return;
		}

		while (!in.eof())
		{
			std::vector<std::vector<Cell>> result;
			std::string tableName, data;
			int rows, cols;

			int len;
			in.read((char*)&len, sizeof(len));
			tableName.resize(len);
			in.read((char*)&tableName[0], len);

			in.read((char*)&rows, sizeof(rows));
			in.read((char*)&cols, sizeof(cols));

			result.resize(rows);
			for (int p = 0; p < rows; p++)
			{
				result[p].resize(cols);

				for (int j = 0; j < cols; j++)
				{
					in.read((char*)&len, sizeof(len));
					data.resize(len);
					in.read((char*)&data[0], len);

					Cell cell(data);
					result[p][j] = cell;
				}
			}

			Table table(result, tableName);
			dataBase.push_back(table);
		}

		in.close();
		file.open(path, std::ios::out, std::ios::binary);
		file.close();
		file.open(path, std::ios::in | std::ios::out | std::ios::binary);

		if (!file.is_open())
		{
			std::cout << "Error!" << std::endl;
			return;
		}
	}

	std::vector<std::string> tokens = split(path, "\\");
	fileName = tokens[tokens.size() - 1];

	std::cout << "Successfully opened " << fileName << std::endl;
}

void System::save()
{
	if (!file.is_open())
	{
		std::cout << "There is no opened file!" << std::endl;
		return;
	}

	file.close();
	file.open(filePath, std::ios::out | std::ios::trunc);
	file.close();
	file.open(filePath);

	for (int i = 0; i < dataBase.size(); i++)
	{
		int len = dataBase[i].getName().length();
		file.write((char*)&len, sizeof(len));
		file.write((char*)&dataBase[i].getName()[0], len);

		int rows = dataBase[i].getRows();
		int cols = dataBase[i].getCols();

		file.write((char*)&rows, sizeof(rows));
		file.write((char*)&cols, sizeof(cols));

		for (int p = 0; p < dataBase[i].getRows(); p++)
		{
			for (int j = 0; j < dataBase[i].getCols(); j++)
			{
				len = dataBase[i].getTable()[p][j].getData().length();
				file.write((char*)&len, sizeof(len));
				file.write((char*)&dataBase[i].getTable()[p][j].getData(), len);
			}
		}
	}

	std::cout << "Successfully saved in " << fileName << " file" << std::endl;
}

void System::saveas(std::string path)
{
	if (path == filePath)
	{
		for (int i = 0; i < dataBase.size(); i++)
		{
			int len = dataBase[i].getName().length();
			file.write((char*)&len, sizeof(len));
			file.write((char*)&dataBase[i].getName()[0], len);

			int rows = dataBase[i].getRows();
			int cols = dataBase[i].getCols();

			file.write((char*)&rows, sizeof(rows));
			file.write((char*)&cols, sizeof(cols));

			for (int p = 0; p < dataBase[i].getRows(); p++)
			{
				for (int j = 0; j < dataBase[i].getCols(); j++)
				{
					len = dataBase[i].getTable()[p][j].getData().length();
					file.write((char*)&len, sizeof(len));
					file.write((char*)&dataBase[i].getTable()[p][j].getData(), len);
				}
			}
		}

		std::cout << "Successfully saved in " << path << " file" << std::endl;
	}
	else
	{
		std::fstream newstream(path);
		if (!newstream.is_open())
		{
			newstream.close();
			std::fstream openFile(path);
			if (!openFile.is_open())
			{
				std::cout << "File could not open" << std::endl;
				return;
			}
			else
			{
				openFile.close();
				newstream.open(path);
				if (!newstream.is_open())
				{
					std::cout << "Error" << std::endl;
					return;
				}
				else
				{
					for (int i = 0; i < dataBase.size(); i++)
					{
						int len = dataBase[i].getName().length();
						file.write((char*)&len, sizeof(len));
						file.write((char*)&dataBase[i].getName()[0], len);

						int rows = dataBase[i].getRows();
						int cols = dataBase[i].getCols();

						file.write((char*)&rows, sizeof(rows));
						file.write((char*)&cols, sizeof(cols));

						for (int p = 0; p < dataBase[i].getRows(); p++)
						{
							for (int j = 0; j < dataBase[i].getCols(); j++)
							{
								len = dataBase[i].getTable()[p][j].getData().length();
								file.write((char*)&len, sizeof(len));
								file.write((char*)&dataBase[i].getTable()[p][j].getData(), len);
							}
						}
					}

					std::cout << "Successfully saved in " << path << " file" << std::endl;

					newstream.close();
				}
			}
		}
		else
		{
			newstream.close();
			newstream.open(path, std::ios::out | std::ios::trunc);
			newstream.close();
			newstream.open(path);

			for (int i = 0; i < dataBase.size(); i++)
			{
				int len = dataBase[i].getName().length();
				file.write((char*)&len, sizeof(len));
				file.write((char*)&dataBase[i].getName()[0], len);

				int rows = dataBase[i].getRows();
				int cols = dataBase[i].getCols();

				file.write((char*)&rows, sizeof(rows));
				file.write((char*)&cols, sizeof(cols));

				for (int p = 0; p < dataBase[i].getRows(); p++)
				{
					for (int j = 0; j < dataBase[i].getCols(); j++)
					{
						len = dataBase[i].getTable()[p][j].getData().length();
						file.write((char*)&len, sizeof(len));
						file.write((char*)&dataBase[i].getTable()[p][j].getData(), len);
					}
				}
			}

			std::cout << "Successfully saved in " << path << " file" << std::endl;

			newstream.close();
		}
	}
}

void System::closeFile()
{
	if (!file.is_open())
	{
		std::cout << "There is no opened file!" << std::endl;
		return;
	}

	file.close();

	std::cout << "Successfully closed " << fileName << std::endl;
	fileName = "";
	filePath = "";
}

void System::help()
{
	std::cout << "The following commands are supported: " << std::endl;
	std::cout << "open <file>\t\t\t\t\topens <file>" << std::endl;
	std::cout << "close\t\t\t\t\t\tcloses currently opened file" << std::endl;
	std::cout << "save\t\t\t\t\t\tsaves the currently open file" << std::endl;
	std::cout << "saveas <file>\t\t\t\t\tsaves the currently open file in <file>" << std::endl;
	std::cout << "help\t\t\t\t\t\tprints this information" << std::endl;
	std::cout << "exit\t\t\t\t\t\texists the program" << std::endl;
	std::cout << "import <file name>\t\t\t\tloads a valid table" << std::endl;
	std::cout << "showtables\t\t\t\t\tshows loaded tables" << std::endl;
	std::cout << "describe <name>\t\t\t\t\tshows data about column's data type" << std::endl;
	std::cout << "print <name>\t\t\t\t\tprints a loaded table" << std::endl;
	std::cout << "export <name> <file name>\t\t\tsaves table to a file" << std::endl;
	std::cout << "select <column-n> <value> <table name>\t\tprints row if value exists" << std::endl;
	std::cout << "addcolumn <table name> <column n> <column type>\tadds column to a table" << std::endl;
	std::cout << "update <table name> <search column n>\t\tupdates target cell's data if " << std::endl;
	std::cout << "<search value> <target column n> <target value>\tsearch value exists" << std::endl;
	std::cout << "delete <table name>" << std::endl;
	std::cout << "<search column n> <search value>\t\tdeletes a value/makes it NULL" << std::endl;
	std::cout << "insert <table name> <column 1> ... <column n>\tinserts a row" << std::endl;
	std::cout << "innerjoin <table 1> <column n1>\t\t\tmakes an innerjoin to two" << std::endl;
	std::cout << "<table 2> <column n2>\t\t\t\tcolumns and makes a new table" << std::endl;
	std::cout << "rename <old name> <new name>\t\t\trenames existing table" << std::endl;
	std::cout << "count <table name> <search column n>\t\tshows the amount of rows in a table" << std::endl;
	std::cout << "<search value>\t\t\t\t\tif searched value exists" << std::endl;
	std::cout << "aggregate <table name>\t\t\t\tmakes an operatin over a column if search" << std::endl;
	std::cout << "<search column n> <search value>\t\tvalue and target value supported operations" << std::endl;
	std::cout << "<target column n> <operation>\t\t\tare: sum, product, minimum and maximum" << std::endl;

}

bool System::isNameValid(std::string name)
{
	for (int i = 0; i < dataBase.size(); i++)
	{
		if (dataBase[i].getName() == name)
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

			//importing table from .txt file
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
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string tableName = tokens[2], searchValue = tokens[1];
			int searchColumn = stringToInt(tokens[0]);

			selectRows(tableName, searchColumn, searchValue);
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
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string tableName = tokens[0], searchValue = tokens[2], targetValue = tokens[4];
			int searchColumn = stringToInt(tokens[1]), targetColumn = stringToInt(tokens[3]);

			update(tableName, searchColumn, searchValue, targetColumn, targetValue);
		}
		else if (operation == "delete")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string tableName = tokens[0], searchValue = tokens[2];
			int searchColumn = stringToInt(tokens[1]);

			deleteRow(tableName, searchColumn, searchValue);
		}
		else if (operation == "insert")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string tableName = tokens[0];
			std::vector<std::string> data;

			for (int i = 1; i < tokens.size(); i++)
			{
				data.push_back(tokens[i]);
			}

			insertRow(tableName, data);
		}
		else if (operation == "innerjoin")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string firstTable = tokens[0], secondTable = tokens[2];
			int firstTableColumn = stringToInt(tokens[1]), secondTableColumn = stringToInt(tokens[3]);
		}
		else if (operation == "rename")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string oldName = tokens[0], newName = tokens[1];

			rename(oldName, newName);
		}
		else if (operation == "count")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string tableName = tokens[0], searchValue = tokens[2];
			int searchColumn = stringToInt(tokens[1]);

			countRows(tableName, searchColumn, searchValue);
		}
		else if (operation == "aggregate")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string tableName = tokens[0], searchValue = tokens[2], operation = tokens[4];
			int searchColumn = stringToInt(tokens[1]), targetColumn = stringToInt(tokens[3]);

			aggregate(tableName, searchColumn, searchValue, targetColumn, operation);
		}
		else if (operation == "open")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string fileToOpen = tokens[0];

			open(fileToOpen);
		}
		else if (operation == "save")
		{
			save();
		}
		else if (operation == "saveas")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string fileToSave = tokens[0];

			saveas(fileToSave);
		}
		else if (operation == "close")
		{
			closeFile();
		}
		else if (operation == "help")
		{
			help();
		}
		else if (operation == "exit")
		{
			if (file.is_open())
			{
				file.close();
				std::cout << "Closing " << fileName << std::endl;
			}

			break;
		}
		else
		{
			std::cout << "Unknown command! Type 'help' for available commands." << std::endl;
		}
    }
}