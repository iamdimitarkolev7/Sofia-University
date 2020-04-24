#pragma once
class System
{
public:
	static System& i();
	System(const System&) = delete;
	void operator=(const System&) = delete;

	void run();

	~System();
private:
	System();
};