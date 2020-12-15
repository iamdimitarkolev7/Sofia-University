#include "IML_Reader.h"
#include <iostream>

IML_Reader::IML_Reader(std::string inputFileName, std::string outputFileName)
{
	this->inputFileName = inputFileName;
	this->outputFileName = outputFileName;
}

std::string IML_Reader::trim(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');

	if (std::string::npos == first)
	{
		return str;
	}

	size_t last = str.find_last_not_of(' ');

	return str.substr(first, (last - first + 1));
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

void IML_Reader::tokenize(std::string data)
{
	//TODO logic should be updated
	std::vector<std::string> tokens = split(data, "<");

	if (tokens[0] != "")
	{
		throw std::logic_error("Error in language");
	}
	
	for (size_t i = 1; i < tokens.size(); i++)
	{
		std::vector<std::string> tagTokens = split(tokens[i], ">");

		for (size_t j = 0; j < tagTokens.size(); j += 2)
		{
			if (tagTokens[j][0] != '/')
			{
				std::vector<std::string> newTokens = split(tagTokens[j], " ");
				std::string tagName = newTokens[0];
				std::vector<std::string> values = split(tagTokens[j + 1], " ");
				
				if (newTokens.size() == 2)
				{
					//TODO error handling
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
					//TODO throw error
				}
			}
			else
			{
				std::string closingTagName = tagTokens[j].erase(0, 1);

				if (closingTagName == objectModelTree.top().getTagName())
				{
					std::vector<int> result = objectModelTree.top().executeTag();
					objectModelTree.pop();

					if (!objectModelTree.empty())
						objectModelTree.top().addValues(result);
					else if (objectModelTree.size() == 1)
					{
						for (int element : objectModelTree.top().getValues())
						{
							std::cout << element << " ";
						}

						std::cout << std::endl;
					}
				}
			}
		}
	}
}

void IML_Reader::read(std::ifstream& in, std::ofstream& out)
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

	//TODO error handling

	tokenize(trim(data));
}