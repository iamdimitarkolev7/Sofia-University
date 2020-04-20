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
	void push(const Challenge& challenge);
	void remove(const char* challengeName);
	Challenge& operator[](int i);
	bool contains(const char* challengeName);
	void print();
	ChallengesArray& operator=(const ChallengesArray& other);
};

