#include "Formula.h"
#include "Fire.h"
#include "Water.h"
#include "Earth.h"
#include "Air.h"
#include "Gold.h"
#include "Spirit.h"
#include "Stone.h"
#include "Energy.h"
#include "Metal.h"

Formula::Formula()
{
    formula = "";
}

Formula::Formula(const Formula& other)
{
    formula = other.formula;
}

Formula::Formula(std::string _formula)
{
    formula = _formula;
}

Formula& Formula::operator=(const Formula& other)
{
    if (this != &other)
    {
        this->formula = other.formula;
    }

    return *this;
}

std::string Formula::getFormula()
{
    return formula;
}

bool Formula::isValid()
{
    Fire fire; Water water; Earth earth; Air air;
    Metal metal; Stone stone; Energy energy; Spirit spirit; Gold gold;

    std::string helperFormula = formula;
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

    for (int i = 0; i < tokens.size() - 1; i++)
    {
        if (tokens[i] == "Earth")
        {
            for (int j = 0; j < tokens.size() - 1; j++)
            {
                if (tokens[j] != "Earth")
                {
                    if (!earth.interacts(tokens[j]))
                        return false;
                }
            }
        }
        else if (tokens[i] == "Water")
        {
            for (int j = 0; j < tokens.size() - 1; j++)
            {
                if (tokens[j] != "Water")
                {
                    if (!water.interacts(tokens[j]))
                        return false;
                }
            }
        }
        else if (tokens[i] == "Earth")
        {
            for (int j = 0; j < tokens.size() - 1; j++)
            {
                if (tokens[j] != "Earth")
                {
                    if (!earth.interacts(tokens[j]))
                        return false;
                }
            }
        }
        else if (tokens[i] == "Air")
        {
            for (int j = 0; j < tokens.size() - 1; j++)
            {
                if (tokens[j] != "Air")
                {
                    if (air.interacts(tokens[j]) == false)
                        return false;
                }
            }
        }
        else if (tokens[i] == "Metal")
        {
            for (int j = 0; j < tokens.size() - 1; j++)
            {
                if (tokens[j] != "Metal")
                {
                    if (!metal.interacts(tokens[j]))
                        return false;
                }
            }
        }
        else if (tokens[i] == "Stone")
        {
            for (int j = 0; j < tokens.size() - 1; j++)
            {
                if (tokens[j] != "Stone")
                {
                    if (!stone.interacts(tokens[j]))
                        return false;
                }
            }
        }
        else if (tokens[i] == "Energy")
        {
            for (int j = 0; j < tokens.size() - 1; j++)
            {
                if (tokens[j] != "Energy")
                {
                    if (!energy.interacts(tokens[j]))
                        return false;
                }
            }
        }
        else if (tokens[i] == "Spirit")
        {
            for (int j = 0; j < tokens.size() - 1; j++)
            {
                if (tokens[j] != "Spirit")
                {
                    if (!spirit.interacts(tokens[j]))
                        return false;
                }
            }
        }
        else if (tokens[i] == "Gold")
        {
            for (int j = 0; j < tokens.size() - 1; j++)
            {
                if (tokens[j] != "Gold")
                {
                    if (gold.interacts(tokens[j]) == false)
                        return false;
                }
            }
        }
        else
            return false;
    }

    return true;
}

Formula::~Formula()
{

}