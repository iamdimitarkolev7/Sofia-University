#pragma once
#include <string>
#include <fstream>

class Event
{
private:
	std::string date;
	int hallNumber;
	std::string name;
	int views;

public:
	Event();
	Event(std::string _date, int _hallNumber, std::string _name);
	Event(const Event& other);
	Event& operator=(const Event& other);

	std::string getDate() const;
	std::string getName() const;
	int getHallNumber() const;
	int getViews() const;
	void incrementViews();
	void decrementViews();
};

