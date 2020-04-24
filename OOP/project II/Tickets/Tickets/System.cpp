#include <iostream>
#include <string>
#include <vector>
#include "System.h"
#include "Hall.h"
#include "Event.h"
#include "Ticket.h"
#include "BoughtTicket.h"

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

		if (operation == "addevent")
		{
			std::cout << "Event added" << std::endl;
		}
		else if (operation == "freeseats")
		{

		}
		else if (operation == "book")
		{
			std::cout << "Successfully booked" << std::endl;
		}
		else if (operation == "unbook")
		{

		}
		else if (operation == "buy")
		{

		}
		else if (operation == "bookings")
		{

		}
		else if (operation == "check")
		{

		}
		else if (operation == "report")
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
			break;
		}
		else
		{
			std::cout << "Unknown command! Type 'help' for available commands." << std::endl;
		}
	}
}