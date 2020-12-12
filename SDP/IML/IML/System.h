#pragma once
#ifndef __SYSTEM
#define __SYSTEM

#include <vector>
#include <string>

class System
{
	std::vector<std::string> tags;
	
	std::vector<std::string> split(std::string str, std::string delimiter);
	std::string trim(const std::string str);
	
	System();
	
public:
	static System& i();
	System(const System&) = delete;
	void operator=(const System&) = delete;

	bool validTxt(std::string fileName);
	void run();

	~System();
};

#endif
