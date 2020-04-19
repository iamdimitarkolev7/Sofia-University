#pragma once
#ifndef _VECTORUSER_H
#define _VECTORUSER_H
#include "User.h"

class VectorUser
{
private:
	User* users;
	size_t size;

public:
	VectorUser();
	~VectorUser();

	size_t getSize() const;
	void push(const User& user);
	User& operator[](int i);
	bool contains(const char* userName);
	void print();
	VectorUser& operator=(const VectorUser& other);
};

#endif
