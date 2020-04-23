#include <iostream>
#include <string>
#include <vector>
#include "System.h"
#include "Table.h"

std::vector<Table> dataBase;
std::vector<Table> loadedTables;

System& System::i()
{
	static System instance;
	return instance;
}

System::System()
{
	std::cout << "Start of the program: " << std::endl;
}

System::~System()
{
	std::cout << "End of the program!" << std::endl;
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
			
		}
		else if (operation == "showtables")
		{

		}
		else if (operation == "describe")
		{

		}
		else if (operation == "print")
		{

		}
		else if (operation == "export")
		{

		}
		else if (operation == "select")
		{

		}
		else if (operation == "addcolumn")
		{

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