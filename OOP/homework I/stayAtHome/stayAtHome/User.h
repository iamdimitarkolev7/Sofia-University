#pragma once
#ifndef _USER_H
#define _USER_H 
#include "Challenge.h"
#include "ChallengesArray.h"

class User
{
private:
	char *name;
	char age[10];
	char email[100];
	int ID;
	ChallengesArray unfinished;

	bool isNameValid();
	bool isAgeValid();
	
public:
	User();
	User(const char* _name, const char* _age, const char* _email, int _ID);
	~User();

	char* getName() const;
	const char* getAge() const;
	const char* getEmail() const;
	int getID() const;
	bool isValid();
	User& operator=(const User& other);
};

#endif

