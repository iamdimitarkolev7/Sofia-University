#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "System.h"
#include "Hall.h"
#include "Event.h"
#include "Ticket.h"
#include "BoughtTicket.h"

std::vector<Hall> eventHalls;
std::vector<Event> events;
std::vector<Ticket> bookings;
std::vector<BoughtTicket> boughtTickets;

System& System::i()
{
	static System instance;
	return instance;
}

System::System()
{
	int number = 1, rows = 10, places = 20;

	for (int i = 0; i < 5; i++)
	{
		Hall hall(number, rows, places);
		eventHalls.push_back(hall);

		number++;
		rows += 2;
		places += 5;
	}
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

bool System::isDateValid(std::string date)
{
	std::vector<std::string> tokens = split(date, "-");

	int year = stringToInt(tokens[0]);
	int month = stringToInt(tokens[1]);
	int day = stringToInt(tokens[2]);

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day > 31)
			return false;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}

	if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day > 29)
			{
				return false;
			}
		}
		else
		{
			if (day > 28)
			{
				return false;
			}
		}
	}

	return true;
}

bool System::isHallFree(std::string date, int hallNumber)
{
	for (int i = 0; i < events.size(); i++)
	{
		if (events[i].getHallNumber() == hallNumber)
		{
			if (events[i].getDate() == date)
				return false;
		}
	}

	return true;
}

bool System::isNameValid(std::string name)
{
	for (int i = 0; i < name.size(); i++)
	{
		if ((name[i] < 'A' || name[i] > 'Z') && (name[i] < 'a' || name[i] > 'z'))
			return false;
	}

	return true;
}

bool System::isHallNumValid(int hallNumber)
{
	for (int i = 0; i < eventHalls.size(); i++)
	{
		if (eventHalls[i].getHallNumber() == hallNumber)
			return true;
	}

	return false;
}

void System::bookTicket(int row, int seat, std::string date, std::string eventName, std::string note)
{
	int evntHallNum = 0;

	for (int i = 0; i < events.size(); i++)
	{
		if (events[i].getName() == eventName)
		{
			if (events[i].getDate() == date)
			{
				evntHallNum = events[i].getHallNumber();
			}
			else
			{
				std::cout << "There is no such performance on this date!" << std::endl;
				return;
			}
		}
	}

	if (evntHallNum == 0)
	{
		std::cout << "No such performance in performance list!" << std::endl;
		return;
	}

	for (int i = 0; i < eventHalls.size(); i++)
	{
		if (eventHalls[i].getHallNumber() == evntHallNum)
		{
			if (eventHalls[i].isAvailable(row, seat))
			{
				Ticket ticket(eventName, date, row, seat, note);
				bookings.push_back(ticket);
				eventHalls[i].addBooking(row, seat);

				std::cout << "Booking sucessfully made!" << std::endl;
				return;
			}
			else
			{
				std::cout << "This place is not free!" << std::endl;
				return;
			}
		}
	}
}

void System::unbookTicket(int row, int seat, std::string date, std::string eventName)
{
	int evntHallNum = 0;

	for (int i = 0; i < events.size(); i++)
	{
		if (events[i].getName() == eventName)
		{
			if (events[i].getDate() == date)
			{
				evntHallNum = events[i].getHallNumber();
			}
			else
			{
				std::cout << "There is no such performance on this date!" << std::endl;
				return;
			}
		}
	}

	if (evntHallNum == 0)
	{
		std::cout << "No such performance in performance list!" << std::endl;
		return;
	}

	for (int i = 0; i < eventHalls.size(); i++)
	{
		if (eventHalls[i].getHallNumber() == evntHallNum)
		{
			//TODO...
		}
	}
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
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string date = tokens[0], eventName = tokens[2];
			int hallNumber = stringToInt(tokens[1]);

			if (!isDateValid(date))
			{
				std::cout << "Invalid date!" << std::endl;
				continue;
			}

			if (!isHallNumValid(hallNumber))
			{
				std::cout << "Invalid hall!" << std::endl;
				continue;
			}

			if (!isNameValid(eventName))
			{
				std::cout << "Invalid name of event!" << std::endl;
				continue;
			}

			if (!isHallFree(date, hallNumber))
			{
				std::cout << "There\'s already an event on this date at this hall!" << std::endl;
				continue;
			}

			Event evnt(date, hallNumber, eventName);
			events.push_back(evnt);
			std::cout << "Event successfully added!" << std::endl;
		}
		else if (operation == "freeseats")
		{
			
		}
		else if (operation == "book")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			int bookedRow = stringToInt(tokens[0]), bookedSeat = stringToInt(tokens[1]);
			std::string date = tokens[2], eventName = tokens[3], note;

			if (!isDateValid(date))
			{
				std::cout << "Invalid date!" << std::endl;
				continue;
			}

			for (int i = 4; i < tokens.size() - 1; i++)
				note += tokens[i] + " ";
			
			note += tokens[tokens.size() - 1];

			bookTicket(bookedRow, bookedSeat, date, eventName, note);
		}
		else if (operation == "unbook")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			int bookedRow = stringToInt(tokens[0]), bookedSeat = stringToInt(tokens[1]);
			std::string date = tokens[2], eventName = tokens[3];

			unbookTicket(bookedRow, bookedSeat, date, eventName);
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