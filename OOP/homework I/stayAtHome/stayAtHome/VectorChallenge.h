#pragma once
#include "Challenge.h"

class VectorChallenge
{
private:
	Challenge* challenges;
	size_t size;

public:
	VectorChallenge();
	~VectorChallenge();

	size_t getSize() const;
	void push(const Challenge& _challenge);
	Challenge& operator[](int i);
	bool contains(Challenge& _challengeName);
	void print();
};

