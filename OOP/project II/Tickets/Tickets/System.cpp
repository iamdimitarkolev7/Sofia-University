#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "System.h"

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

	if (month > 12 || year < 2020)
		return false;

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

				for (int j = 0; j < events.size(); j++)
				{
					if (events[j].getName() == eventName && events[j].getDate() == date)
					{
						events[j].incrementViews();
					}
				}

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
			bool found = false;
			int index = 0;

			for (int j = 0; j < bookings.size(); j++)
			{
				if (bookings[j].getDate() == date && bookings[j].getEventName() == eventName
					&& bookings[j].getRow() == row && bookings[j].getSeat() == seat)
				{
					found = true;
					index = j;
				}
			}

			if (found)
			{
				bookings.erase(bookings.begin() + index);
				eventHalls[i].removeBooking(row, seat);
				std::cout << "Booking sucessfully removed!" << std::endl;

				for (int j = 0; j < events.size(); j++)
				{
					if (events[j].getName() == eventName && events[j].getDate() == date)
					{
						events[j].decrementViews();
					}
				}

				return;
			}
			else
			{
				std::cout << "There is no such booking!" << std::endl;
				return;
			}
		}
	}
}

void System::buyTicket(int row, int seat, std::string date, std::string eventName)
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
				BoughtTicket ticket(eventName, date, row, seat);
				boughtTickets.push_back(ticket);
				eventHalls[i].addBuying(row, seat);

				std::cout << "Buying sucessfully made!" << std::endl;

				for (int j = 0; j < events.size(); j++)
				{
					if (events[j].getName() == eventName && events[j].getDate() == date)
					{
						events[j].incrementViews();
					}
				}

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

void System::freeSeatsData(std::string date, std::string name)
{
	int evntHallNum = 0;

	for (int i = 0; i < events.size(); i++)
	{
		if (events[i].getName() == name)
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
			std::cout << "There are " << eventHalls[i].getFreePlaces() << " free seats for " << name
				<< " event on " << date << " day at hall number " << evntHallNum << "!" << std::endl;
		}
	}
}

void System::checkTicketInformation(int code)
{
	bool notFound = true;

	for (int i = 0; i < boughtTickets.size(); i++)
	{
		if (boughtTickets[i].getID() == code)
		{
			std::cout << "Ticket with ID " << code << " is valid. It is on row"
				<< boughtTickets[i].getRow() << " - seat " << boughtTickets[i].getSeat() << "." << std::endl;

			notFound = false;
		}
	}

	if (notFound)
	{
		std::cout << "Not a valid code for a ticket!" << std::endl;
	}
}

void System::showBookings()
{
	for (int i = 0; i < events.size(); i++)
	{
		std::cout << "Bookings for " << events[i].getName() << " on " << events[i].getDate() << ": ";

		for (int j = 0; j < eventHalls.size(); j++)
		{
			if (events[i].getHallNumber() == eventHalls[j].getHallNumber())
			{
				std::cout << eventHalls[j].getBookings() << std::endl;
			}
		}
	}
}

void System::showBookings(std::string inputData)
{
	bool isDate = isDateValid(inputData);
	bool isName = isNameValid(inputData);

	if (!isDate && !isName)
	{
		std::cout << "Invalid parameter!" << std::endl;
		return;
	}

	if (isDate)
	{
		bool doneWork = false;

		for (int i = 0; i < events.size(); i++)
		{
			if (events[i].getDate() == inputData)
			{
				doneWork = true;

				std::cout << "Bookings for " << events[i].getName() << " on " << events[i].getDate() << ": ";

				for (int j = 0; j < eventHalls.size(); j++)
				{
					if (events[i].getHallNumber() == eventHalls[j].getHallNumber())
					{
						std::cout << eventHalls[j].getBookings() << std::endl;
					}
				}
			}
		}

		if (!doneWork)
		{
			std::cout << "There are no events on this date!" << std::endl;
			return;
		}
	}

	if (isName)
	{
		bool doneWork = false;

		for (int i = 0; i < events.size(); i++)
		{
			if (events[i].getName() == inputData)
			{
				doneWork = true;

				std::cout << "Bookings for " << events[i].getName() << " on " << events[i].getDate() << ": ";

				for (int j = 0; j < eventHalls.size(); j++)
				{
					if (events[i].getHallNumber() == eventHalls[j].getHallNumber())
					{
						std::cout << eventHalls[j].getBookings() << std::endl;
					}
				}
			}
		}

		if (!doneWork)
		{
			std::cout << "There is no such event in event list!" << std::endl;
			return;
		}
	}
}

void System::showBookings(std::string date, std::string name)
{
	bool doneWork = false;

	for (int i = 0; i < events.size(); i++)
	{
		if (events[i].getDate() == date && events[i].getName() == name)
		{
			doneWork = true;

			std::cout << "Bookings for " << events[i].getName() << " on " << events[i].getDate() << ": ";

			for (int j = 0; j < eventHalls.size(); j++)
			{
				if (events[i].getHallNumber() == eventHalls[j].getHallNumber())
				{
					std::cout << eventHalls[j].getBookings() << std::endl;
				}
			}
		}
	}

	if (!doneWork)
	{
		std::cout << "There is no such event on this date!" << std::endl;
		return;
	}
}

bool System::isDateInRange(std::string from, std::string to, std::string date)
{
	std::vector<std::string> tokensFrom = split(from, "-"), tokensTo = split(to, "-"), tokensDate = split(date, "-");

	int yearFrom = stringToInt(tokensFrom[0]), monthFrom = stringToInt(tokensFrom[1]), dayFrom = stringToInt(tokensFrom[2]),
		yearTo = stringToInt(tokensTo[0]), monthTo = stringToInt(tokensTo[1]), dayTo = stringToInt(tokensTo[2]),
		yearDate = stringToInt(tokensDate[0]), monthDate = stringToInt(tokensDate[1]), dayDate = stringToInt(tokensDate[2]);

	//(year * 10000) + (month * 100) + day
	long startDate = (yearFrom * 10000) + (monthFrom * 100) + dayFrom;
	long endDate = (yearTo * 10000) + (monthTo * 100) + dayTo;
	long entryDate = (yearDate * 10000) + (monthDate * 100) + dayDate;

	return entryDate >= startDate && entryDate <= endDate;
}

void System::report(std::string from, std::string to)
{
	if (!isDateValid(from) || !isDateValid(to))
	{
		std::cout << "Invalid date format!" << std::endl;
		return;
	}

	for (int j = 0; j < events.size(); j++)
	{
		for (int i = 0; i < eventHalls.size(); i++)
		{
			if (isDateInRange(from, to, events[j].getDate()) && 
				events[j].getHallNumber() == eventHalls[i].getHallNumber())
			{
				std::cout << "For " << events[j].getName() << " event has been sold "
					<< eventHalls[i].getBuyings() << " tickets." << std::endl;
			}
		}
	}
}

void System::report(std::string from, std::string to, int hallNumber)
{
	if (!isHallNumValid(hallNumber))
	{
		std::cout << "Invalid hall!" << std::endl;
		return;
	}

	if (!isDateValid(from) || !isDateValid(to))
	{
		std::cout << "Invalid date format!" << std::endl;
		return;
	}

	for (int i = 0; i < eventHalls.size(); i++)
	{
		if (eventHalls[i].getHallNumber() == hallNumber)
		{
			for (int j = 0; j < events.size(); j++)
			{
				if (events[j].getHallNumber() == hallNumber && isDateInRange(from, to, events[j].getDate()))
				{
					std::cout << "For " << events[j].getName() << " event has been sold "
						<< eventHalls[i].getBuyings() << " tickets." << std::endl;
				}
			}
		}
	}
}

void System::eventsSort()
{	
	Event evnt;

	for (int i = 0; i < events.size() - 1; i++)
	{
		for (int j = 0; j < events.size() - i - 1; j++)
		{
			if (events[j].getViews() < events[j + 1].getViews())
			{
				evnt = events[j];
				events[j] = events[j + 1];
				events[j + 1] = evnt;
			}
		}
	}
}

void System::showMostViewedEvents()
{
	eventsSort();

	for (int i = 0; i < events.size(); i++)
	{
		std::cout << "\t"<< i + 1 << ". " << events[i].getName() << ": " << events[i].getViews() << " views." << std::endl;
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

		std::string date, name;
		int hallNumber, views, counter = 0;

		while (!in.eof())
		{
			int len;
			in.read((char*)&len, sizeof(len));
			date.resize(len);
			in.read((char*)&date[0], len);

			in.read((char*)&hallNumber, sizeof(hallNumber));

			in.read((char*)&len, sizeof(len));
			name.resize(len);
			in.read((char*)&name[0], len);

			Event evnt(date, hallNumber, name);
			events.push_back(evnt);
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

	for (int i = 0; i < events.size(); i++)
	{
		int len = events[i].getDate().length();
		file.write((char*)&len, sizeof(len));
		file.write((char*)&events[i].getDate()[0], len);

		int hallNumber = events[i].getHallNumber();
		file.write((char*)&hallNumber, sizeof(hallNumber));

		len = events[i].getName().length();
		file.write((char*)&len, sizeof(len));
		file.write((char*)&events[i].getName()[0], len);
	}

	std::cout << "Successfully saved in " << fileName << " file" << std::endl;
}

void System::saveas(std::string path)
{
	if (path == filePath)
	{
		for (int i = 0; i < events.size(); i++)
		{
			int len = events[i].getDate().length();
			file.write((char*)&len, sizeof(len));
			file.write((char*)&events[i].getDate()[0], len);

			int hallNumber = events[i].getHallNumber();
			file.write((char*)&hallNumber, sizeof(hallNumber));

			len = events[i].getName().length();
			file.write((char*)&len, sizeof(len));
			file.write((char*)&events[i].getName()[0], len);
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
					for (int i = 0; i < events.size(); i++)
					{
						int len = events[i].getDate().length();
						file.write((char*)&len, sizeof(len));
						file.write((char*)&events[i].getDate()[0], len);

						int hallNumber = events[i].getHallNumber();
						file.write((char*)&hallNumber, sizeof(hallNumber));

						len = events[i].getName().length();
						file.write((char*)&len, sizeof(len));
						file.write((char*)&events[i].getName()[0], len);
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

			for (int i = 0; i < events.size(); i++)
			{
				int len = events[i].getDate().length();
				file.write((char*)&len, sizeof(len));
				file.write((char*)&events[i].getDate()[0], len);
				
				int hallNumber = events[i].getHallNumber();
				file.write((char*)&hallNumber, sizeof(hallNumber));

				len = events[i].getName().length();
				file.write((char*)&len, sizeof(len));
				file.write((char*)&events[i].getName()[0], len);
			}

			std::cout << "Successfully saved in " << path << " file" << std::endl;

			newstream.close();
		}
	}
}

void System::help()
{
	std::cout << "The following commands are supported :" << std::endl;
	std::cout << "open <file>    opens <file>" << std::endl;
	std::cout << "close          closes currently opened file" << std::endl;
	std::cout << "save           saves the currently open file" << std::endl;
	std::cout << "saveas <file>  saves the currently open file in <file>" << std::endl;
	std::cout << "help           prints this information" << std::endl;
	std::cout << "exit           exists the program" << std::endl;
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

System::~System()
{
	std::cout << "Exiting program..." << std::endl;
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
				std::cout << "There is already an event on this date at this hall!" << std::endl;
				continue;
			}

			Event evnt(date, hallNumber, eventName);
			events.push_back(evnt);

			if (file.is_open())
			{
				int len = date.length();
				file.write((char*)&len, sizeof(len));
				file.write((char*)&date[0], len);

				file.write((char*)&hallNumber, sizeof(hallNumber));

				len = eventName.length();
				file.write((char*)&len, sizeof(len));
				file.write((char*)&eventName[0], len);
			}

			std::cout << "Event successfully added!" << std::endl;
		}
		else if (operation == "freeseats")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string date = tokens[0], eventName = tokens[1];

			freeSeatsData(date, eventName);
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
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			int row = stringToInt(tokens[0]), seat = stringToInt(tokens[1]);
			std::string date = tokens[2], eventName = tokens[3];

			buyTicket(row, seat, date, eventName);
		}
		else if (operation == "bookings")
		{
			if (input == "bookings")
			{
				showBookings();
				continue;
			}

			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			
			if (tokens.size() == 1)
				showBookings(tokens[0]);
			if (tokens.size() == 2)
				showBookings(tokens[0], tokens[1]);
		}
		else if (operation == "check")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			int code = stringToInt(tokens[0]);

			checkTicketInformation(code);
		}
		else if (operation == "report")
		{
			input.erase(0, input.find(" ") + 1);
			std::vector<std::string> tokens = split(input, " ");
			std::string from = tokens[0], to = tokens[1];

			if (tokens.size() == 3)
			{
				int hallNum = stringToInt(tokens[2]);
				report(from, to, hallNum);
				continue;
			}

			report(from, to);
		}
		else if (operation == "statistics")
		{
			showMostViewedEvents();
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
		else if (operation == "help")
		{
			help();
		}
		else if (operation == "close")
		{
			closeFile();
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