#include "Book.h"

Book::Book()
{
	formulas.resize(0);
	elementAmounts.resize(4);
	elementAmounts[0] = 0; //Earth amount
	elementAmounts[1] = 0; //Fire amount
	elementAmounts[2] = 0; //Water amount
	elementAmounts[3] = 0; //Air amount
}

Book::Book(const Book& other)
{
	formulas.resize(other.formulas.size());

	for (int i = 0; i < other.formulas.size(); i++)
	{
		formulas[i] = other.formulas[i];
	}

	elementAmounts.resize(4);

	elementAmounts[0] = other.elementAmounts[0];
	elementAmounts[1] = other.elementAmounts[1];
	elementAmounts[2] = other.elementAmounts[2];
	elementAmounts[3] = other.elementAmounts[3];
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		formulas.resize(other.formulas.size());

		for (int i = 0; i < other.formulas.size(); i++)
		{
			formulas[i] = other.formulas[i];
		}

		elementAmounts.resize(4);

		elementAmounts[0] = other.elementAmounts[0];
		elementAmounts[1] = other.elementAmounts[1];
		elementAmounts[2] = other.elementAmounts[2];
		elementAmounts[3] = other.elementAmounts[3];
	}

	return *this;
}

void Book::addToBook(Formula formula)
{
	formulas.push_back(formula);
}

bool Book::isValid()
{
	for (int i = 0; i < formulas.size(); i++)
	{
		if (formulas[i].getFormula().find("Philosopher's Stone"))
			return true;
	}

	return false;
}

void Book::filterFormulas()
{
	std::string pSFormula;

	for (int i = 0; i < formulas.size(); i++)
	{
		if (formulas[i].getFormula().find("Philosopher's Stone"))
			pSFormula = formulas[i].getFormula();
	}

	std::string helperFormula = pSFormula;
	std::vector<std::string> tokens;
	std::string token, lastToken;
	int index = helperFormula.find(" = ");
	lastToken = helperFormula.substr(index + 3, helperFormula.length() - 1);
	helperFormula.erase(index, helperFormula.length() - 1);

	while ((index = helperFormula.find(" + ")) != std::string::npos)
	{
		token = helperFormula.substr(0, index);
		tokens.push_back(token);
		helperFormula.erase(0, index + 3);
	}

	tokens.push_back(helperFormula);
	tokens.push_back(lastToken);

	int fireCounter = 0, waterCounter = 0, airCounter = 0, earthCounter = 0;

	while (!tokens.empty())
	{
		std::string element = tokens[0];

		if (element == "Fire")
		{
			fireCounter++;
			tokens.erase(tokens.begin());
		}
		else if (element == "Water")
		{
			waterCounter++;
			tokens.erase(tokens.begin());
		}
		else if (element == "Earth")
		{
			earthCounter++;
			tokens.erase(tokens.begin());
		}
		else if (element == "Air")
		{
			airCounter++;
			tokens.erase(tokens.begin());
		}
		else
		{
			for (int i = 0; i < formulas.size(); i++)
			{
				std::string current = formulas[i].getFormula();

				int index = current.find_last_of(" = ");

				if (current.substr(index + 1) == element)
				{
					int ind = 0;
					std::string token;
					std::vector<std::string> newTokens;

					while ((ind = current.find(" + ")) != std::string::npos || (ind = current.find(" = ")) != std::string::npos)
					{
						token = current.substr(0, ind);
						newTokens.push_back(token);
						current.erase(0, ind + 3);
					}

					newTokens.push_back(current);
					tokens.erase(tokens.begin());

					for (int i = 0; i < newTokens.size() - 1; i++)
					{
						tokens.insert(tokens.begin(), newTokens[i]);
					}

					break;
				}
			}
		}
	}

	elementAmounts[0] = earthCounter;
	elementAmounts[1] = fireCounter;
	elementAmounts[2] = waterCounter;
	elementAmounts[3] = airCounter;
}

int Book::getEarthAmount()
{
	return elementAmounts[0];
}

int Book::getFireAmount()
{
	return elementAmounts[1];
}

int Book::getWaterAmount()
{
	return elementAmounts[2];
}
int Book::getAirAmount()
{
	return elementAmounts[3];
}

Book::~Book()
{

}