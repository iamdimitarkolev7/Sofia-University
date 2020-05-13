#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Hall.h"
#include "Event.h"
#include "Ticket.h"
#include "BoughtTicket.h"

class System
{
public:
	static System& i();
	System(const System&) = delete;
	void operator=(const System&) = delete;

	void run();

	~System();
private:
	std::vector<Hall> eventHalls;
	std::vector<Event> events;
	std::vector<Ticket> bookings;
	std::vector<BoughtTicket> boughtTickets;

	std::fstream file;
	std::string fileName, filePath;

	System();

	std::vector<std::string> split(std::string input, std::string delimiter);
	bool isDateValid(std::string date);
	bool isHallFree(std::string date, int hallNumber);
	bool isNameValid(std::string name);
	bool isHallNumValid(int hallNumber);
	void freeSeatsData(std::string date, std::string name);
	void bookTicket(int row, int seat, std::string date, std::string eventName, std::string note);
	void unbookTicket(int row, int seat, std::string date, std::string eventName);
	void buyTicket(int row, int seat, std::string date, std::string eventName);
	void checkTicketInformation(int code);
	void showBookings();
	void showBookings(std::string inputData);
	void showBookings(std::string date, std::string name);
	void report(std::string from, std::string to, int hallNumber);
	void report(std::string from, std::string to);
	bool isDateInRange(std::string from, std::string to, std::string date);
	void showMostViewedEvents();
	void showLeastViewedEvents();
	void eventsSort();

	void open(std::string path);
	void save();
	void saveas(std::string path);
	void help();
	void closeFile();

	int stringToInt(std::string str);
};