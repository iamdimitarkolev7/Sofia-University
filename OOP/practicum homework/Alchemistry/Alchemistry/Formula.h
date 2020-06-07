#pragma once
#include <iostream>
#include <string>
#include <vector>

class Formula
{
private:
	std::string formula;

public:

    Formula();
    Formula(std::string _formula);
    Formula(const Formula& other);
    Formula& operator=(const Formula& other);

    std::string getFormula();
    bool isValid();

    ~Formula();
};

