#include "IML_Reader.h"
#include <iostream>

IML_Reader::IML_Reader(std::string inputFileName, std::string outputFileName)
{
	this->inputFileName = inputFileName;
	this->outputFileName = outputFileName;
}

std::vector<std::string> IML_Reader::split(std::string str, std::string delimiter)
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

void IML_Reader::readTag(const std::string& tag)
{
	std::vector<std::string> newTokens = split(tag, " ");
	std::string tagName = newTokens[0];
	std::vector<std::string> values = split(tag, " ");

	if (newTokens.size() == 2)
	{
		std::string additionalParam = newTokens[1];

		Tag newTag(tagName, values, additionalParam);
		objectModelTree.push(newTag);
	}
	else if (newTokens.size() == 1)
	{
		Tag newTag(tagName, values);
		objectModelTree.push(newTag);
	}
	else
	{
		throw std::logic_error("Incorrect grammar of IML");
	}
}

void IML_Reader::execTag(const std::string& tag)
{
	if (tag == objectModelTree.top().getTagName())
	{
		std::vector<int> result = objectModelTree.top().executeTag();
		objectModelTree.pop();

		if (!objectModelTree.empty())
			objectModelTree.top().addValues(result);
		else
		{
			//TODO ready to write file
		}
	}
	else
	{
		throw std::logic_error("Incorrect grammar of IML");
	}
}

void IML_Reader::tokenize(const std::string& data)
{
	std::vector<std::string> tokens = split(data, "<");

	try
	{
		if (tokens[0] != "")
		{
			throw std::logic_error("The IML must start with opening tag!");
		}

		for (size_t i = 1; i < tokens.size(); i++)
		{
			std::vector<std::string> tagTokens = split(tokens[i], ">");

			for (size_t j = 0; j < tagTokens.size(); j += 2)
			{
				if (tagTokens[j][0] != '/')
				{
					readTag(tagTokens[j]);
				}
				else
				{
					std::string closingTagName = tagTokens[j].erase(0, 1);
					execTag(closingTagName);
				}
			}
		}
	}
	catch(const std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}
}

void IML_Reader::read(std::ifstream& in, std::ofstream& out)
{
	std::string inputData, data;

	try
	{
		in.open(inputFileName);

		if (in.is_open())
		{
			while (!in.eof())
			{
				std::getline(in, inputData);
				data += inputData;
			}
		}
		else
		{
			throw std::logic_error("Cannot open that file");
		}
		
		tokenize(data);
	}
	catch (const std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}
}