#pragma once
#ifndef __SYSTEM
#define __SYSTEM

#include <vector>
#include <string>

class System
{
	std::vector<std::string> split(std::string str, std::string delimiter);
	bool validTxt(std::string fileName);
	
	System();
	
public:
	static System& i();
	System(const System&) = delete;
	void operator=(const System&) = delete;

	void run();

	~System();
};

#endif
