#pragma once
#include <vector>
#include "Formula.h"

class Book
{
private:
	std::vector<Formula> formulas;
	std::vector<int> elementAmounts;

public:
	Book();
	Book(const Book& other);
	Book& operator=(const Book& other);
	
	int getEarthAmount();
	int getFireAmount();
	int getWaterAmount();
	int getAirAmount();
	void addToBook(Formula formula);
	bool isValid();
	void filterFormulas();



	~Book();
};
