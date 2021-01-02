#include "System.h"
#include "IML_Reader.h"
#include <iostream>
#include <stdexcept>

System& System::i()
{
	static System instance;
	return instance;
}

System::System(){}

System::~System()
{
	std::cout << "Exiting program..." << std::endl;
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

bool System::validTxt(std::string fileName)
{
	std::vector<std::string> tokens = split(fileName, ".");

	if (tokens.size() < 2)
	{
		throw std::logic_error("Text file is not in format *.txt");
	}

	if (tokens[1] != "txt")
	{
		throw std::logic_error("The file must be in *.txt format");
	}

	return true;
}

void System::run()
{
	std::string input;
	std::getline(std::cin, input);

	try
	{
		std::vector<std::string> tokens = split(input, " ");

		if (tokens.size() != 2)
		{
			throw std::logic_error("You must type 2 parameters");
		}

		std::string inputFile = tokens[0], outputFile = tokens[1];
		std::ifstream in;

		if (validTxt(inputFile) && validTxt(outputFile))
		{
			IML_Reader iml = IML_Reader(inputFile, outputFile);
			iml.read(in);
		}
		else
		{
			throw std::logic_error("Input files are not valid *.txt files");
		}
	}
	catch (const std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}
}