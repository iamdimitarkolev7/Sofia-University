#pragma once
#include "Water.h"
#include "Fire.h"

class Stone : public Water, public Fire
{
public:
	bool interacts(std::string other);
};

