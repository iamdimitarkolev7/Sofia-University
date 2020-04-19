#pragma once
#ifndef _CHALLENGE_H
#define _CHALLENGE_H

class Challenge
{
private:
	char* name;
	int occ;
	double rating, currSum;
	int numOfRaters;

public:
	Challenge();
	Challenge(const char* name);
	Challenge(const Challenge& other);
	~Challenge();

	bool isValid();
	char* getName() const;
	int getOcc() const;
	double getRating() const;
	double getCurrSum() const;
	int getNumOfRaters() const;
 	void incrementOcc();

	Challenge& operator=(const Challenge& other);

	void print();
};

#endif