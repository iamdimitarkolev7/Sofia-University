#pragma once
#include "Earth.h"
#include "Fire.h"

class Metal : public Earth, public Fire
{
public:
	bool interacts(std::string other);
};

