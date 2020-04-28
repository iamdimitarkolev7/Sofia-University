#pragma once
#include <vector>
#include <string>

class System
{
public:
	static System& i();
	System(const System&) = delete;
	void operator=(const System&) = delete;

	void run();

	~System();
private:
	System();

	std::vector<std::string> split(std::string input, std::string delimiter);
	bool isDateValid(std::string date);
	bool isHallFree(std::string date, int hallNumber);
	bool isNameValid(std::string name);
	bool isHallNumValid(int hallNumber);
	void bookTicket(int row, int seat, std::string date, std::string eventName, std::string note);
	void unbookTicket(int row, int seat, std::string date, std::string eventName);
	int stringToInt(std::string str);
};