#pragma once
#ifndef __IML_READER
#define __IML_READER

#include <fstream>
#include <stack>
#include "Tag.h"

class IML_Reader
{
private:
	std::string inputFileName, outputFileName;
	std::stack<Tag> objectModelTree;

	void readTag(const std::string& tag, const std::string& values);
	void execTag(const std::string& tag, const std::string& value);
	
	void inspect(const std::string& data);
	std::vector<std::string> split(std::string str, const std::string& delimiter);

	std::list<int> mapToInteger(const std::string& values);

	//bool validLanguage(std::string data);
	
public:
	IML_Reader(std::string inputFileName, std::string outputFileName);
	
	void read(std::ifstream&, std::ofstream&);
};

#endif