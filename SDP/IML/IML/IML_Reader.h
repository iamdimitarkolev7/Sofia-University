#pragma once
#ifndef __IML_READER
#define __IML_READER
#include <fstream>
#include <list>
#include <stack>
#include "Tag.h"

class IML_Reader
{
private:
	std::string inputFileName, outputFileName;
	std::stack<Tag*> objectModelTree;

	void tokenize(std::string data);
	std::string trim(const std::string& data);
	std::vector<std::string> split(std::string str, std::string delimiter);
	//bool validLanguage(std::string data);
	
public:
	IML_Reader(std::string inputFileName, std::string outputFileName);
	
	void read(std::ifstream&, std::ofstream&);
};

#endif