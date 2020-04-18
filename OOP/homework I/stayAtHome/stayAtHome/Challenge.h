#pragma once
#ifndef _CHALLENGE_H
#define _CHALLENGE_H

class Challenge
{
private:
	char name[32];
	int occ;
	double rating, currSum;
	int numOfRaters;

public:
	Challenge();
	Challenge(const char* name);
	~Challenge();

	bool isValid();
	const char* getName() const;
	void incrementOcc();
	int getOcc();

	Challenge& operator=(const Challenge& other);

	void print();
};

#endif