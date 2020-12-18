#include "IML_Reader.h"
#include <iostream>
#include <numeric>

IML_Reader::IML_Reader(std::string inputFileName, std::string outputFileName)
{
	this->inputFileName = inputFileName;
	this->outputFileName = outputFileName;
}

std::vector<std::string> IML_Reader::split(std::string str, const std::string& delimiter)
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

std::list<int> IML_Reader::mapToInteger(const std::string& values)
{
	std::list<int> result;
	std::vector<std::string> vals = split(values, " ");

	for (size_t i = 0; i < vals.size(); i++)
	{
		result.push_back(std::stoi(vals[i]));
	}

	return result;
}

void IML_Reader::readTag(const std::string& tag, const std::string& params)
{
	std::vector<std::string> newTokens = split(tag, " ");
	std::string tagName = newTokens[0];
	std::vector<std::string> values = split(params, " ");

	if (newTokens.size() == 2)
	{
		std::string additionalParam = newTokens[1];

		Tag newTag(tagName, values, additionalParam);
		objectModelTree.push(newTag);
	}
	else if (newTokens.size() == 1)
	{
		if (values[0] != "")
		{
			Tag newTag(tagName, values);
			objectModelTree.push(newTag);
		}
		else
		{
			Tag newTag(tagName, {});
			objectModelTree.push(newTag);
		}
	}
	else
	{
		throw std::logic_error("Incorrect grammar of IML");
	}
}

void IML_Reader::execTag(const std::string& tag, const std::string& values)
{
	if (tag == objectModelTree.top().getTagName())
	{
		std::list<int> result = objectModelTree.top().executeTag();
		
		objectModelTree.pop();

		if (!objectModelTree.empty())
		{
			objectModelTree.top().addValues(result);
			
			if (values != "")
			{
				const std::list<int> additionalValue = mapToInteger(values);
				objectModelTree.top().addValues(additionalValue);
			}
		}
		else
		{
			std::ofstream out;
			write(out, result);
		}
	}
	else
	{
		throw std::logic_error("Incorrect grammar of IML");
	}
}

void IML_Reader::inspect(const std::string& data)
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
			std::string tag = tagTokens[0], values = tagTokens[1];

			if (tag[0] != '/')
			{
				readTag(tag, values);
			}
			else
			{
				std::string closingTagName = tag.erase(0, 1);
				execTag(closingTagName, values);
			}
		}
	}
	catch(const std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}
}

void IML_Reader::read(std::ifstream& in)
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
		
		inspect(data);
		in.close();
	}
	catch (const std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}
}

void IML_Reader::write(std::ofstream& out, std::list<int> data)
{
	out.open(outputFileName);

	std::list<int>::iterator it;

	for (it = data.begin(); it != data.end(); ++it)
	{
		out << *it;
		out << " ";
	}

	out.close();
}
