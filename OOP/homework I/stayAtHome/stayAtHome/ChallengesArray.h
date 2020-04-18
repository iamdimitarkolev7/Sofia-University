#pragma once
#include "Challenge.h"

class ChallengesArray
{
private:
	Challenge* challenges;
	size_t size;

public:
	ChallengesArray();
	~ChallengesArray();

	size_t getSize() const;
	void push(const Challenge& user);
	Challenge& operator[](int i);
	bool contains(const char* userName);
	void print();
};

