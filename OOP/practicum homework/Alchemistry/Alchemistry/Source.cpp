#include <iostream>
#include <vector>
#include <string>
#include "Fire.h"
#include "Water.h"
#include "Earth.h"
#include "Air.h"
#include "Gold.h"
#include "Spirit.h"
#include "Stone.h"
#include "Energy.h"
#include "Metal.h"
#include "Alchemic.h"
#include "Book.h"

std::vector<std::string> split(std::string str, std::string delimiter)
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

void readElements(Fire& fire, Water& water, Air& air, Earth& earth)
{
	std::string input;

	for (int i = 0; i < 4; i++)
	{
		std::getline(std::cin, input);
		std::vector<std::string> tokens = split(input, " ");
		int amount = std::stoi(tokens[0]);
		std::string element = tokens[1];

		if (element == "Fire")
		{
			Fire _fire(amount);
			fire = _fire;
		}
		else if (element == "Water")
		{
			Water _water(amount);
			water = _water;
		}
		else if (element == "Air")
		{
			Air _air(amount);
			air = _air;
		}
		else if (element == "Earth")
		{
			Earth _earth(amount);
			earth = _earth;
		}
	}
}

void readFormulas(Book& formulasBook)
{
	std::string input;

	while (true)
	{
		std::getline(std::cin, input);

		if (input == "end")
		{
			break;
		}
		else
		{
			Formula formula(input);

			if (input[0] != '/')
			{
				if (formula.isValid())
				{
					formulasBook.addToBook(formula);
				}
			}
			
		}
	}
}

int main()
{
	Fire fire; Water water;  Air air; Earth earth;
	Book formulasBook;
	Alchemic alchemic;
	
	//First we read elements and their amounts
	readElements(fire, water, air, earth);

	//Now we read formulas from the book; type "end" to finish the book
	readFormulas(formulasBook);
	
	if (formulasBook.isValid())
	{
		formulasBook.filterFormulas();

		std::vector<int> elementAmounts;

		elementAmounts.push_back(earth.getAmount());
		elementAmounts.push_back(fire.getAmount());
		elementAmounts.push_back(water.getAmount());
		elementAmounts.push_back(air.getAmount());
	
		alchemic.giveBook(formulasBook);
		alchemic.giveElAmounts(elementAmounts);

		if (alchemic.canCreateStone())
		{
			std::cout << "It is possible to create the Philosopher's Stone!" << std::endl;
		}
		else
		{
			std::cout << "It is NOT possible to create the Philosopher's Stone!" << std::endl;
		}
	}
	else
	{
		std::cout << "It is NOT possible to create the Philosopher's Stone!" << std::endl;
	}

	return 0;
}