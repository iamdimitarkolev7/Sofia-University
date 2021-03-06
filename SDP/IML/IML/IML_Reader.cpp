#include "IML_Reader.h"
#include <iostream>
#include <algorithm>

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

std::list<double> IML_Reader::mapToDouble(const std::string& values)
{
	std::list<double> result;
	std::vector<std::string> vals = split(values, " ");

	for (size_t i = 0; i < vals.size(); i++)
	{
		result.push_back(std::stod(vals[i]));
	}

	return result;
}

void IML_Reader::readTag(const std::string& tag, const std::string& params)
{
	std::vector<std::string> newTokens = split(tag, " ");
	std::string tagName = newTokens[0];
	std::vector<std::string> values = split(params, " ");
	std::vector<std::string> filteredValues;

	for (std::string value : values)
	{
		if (value != "")
			filteredValues.push_back(value);
	}

	if (newTokens.size() == 2)
	{
		std::string additionalParam = newTokens[1];

		Tag newTag(tagName, filteredValues, additionalParam);
		objectModelTree.push(newTag);
	}
	else if (newTokens.size() == 1)
	{
		if (values[0] != "")
		{
			Tag newTag(tagName, filteredValues);
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
		throw std::logic_error("Incorrect IML usage!");
	}
}

void IML_Reader::execTag(const std::string& tag, const std::string& values)
{
	if (tag == objectModelTree.top().getTagName())
	{
		std::list<double> result = objectModelTree.top().executeTag();
		
		objectModelTree.pop();

		if (!objectModelTree.empty())
		{
			objectModelTree.top().addValues(result);
			
			if (values != "")
			{
				const std::list<double> additionalValue = mapToDouble(values);
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
		throw std::logic_error("Incorrect IML nesting of tags! Every tag must have a closing tag");
	}
}

void IML_Reader::inspect(const std::string& data)
{
	std::vector<std::string> tokens = split(data, "<");

	if (tokens[0] != "")
	{
		throw std::logic_error("The IML must start with an opening tag!");
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
			if (!objectModelTree.empty())
			{
				std::string closingTagName = tag.erase(0, 1);
				execTag(closingTagName, values);
			}
			else
			{
				throw std::logic_error(tag.substr(1, tag.size()) + " does not have an opening tag!");
			}
		}
	}

	if (!objectModelTree.empty())
	{
		throw std::logic_error("There are tags that are not closed!");
	}
}

void IML_Reader::read(std::ifstream& in)
{
	std::string inputData, data;

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

void IML_Reader::write(std::ofstream& out, std::list<double> data)
{	
	out.open(outputFileName);

	std::list<double>::iterator it;

	for (it = data.begin(); it != data.end(); ++it)
	{
		out << *it;
		out << " ";
	}

	out.close();
}
