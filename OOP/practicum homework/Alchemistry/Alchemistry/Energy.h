#pragma once
#include "Air.h"
#include "Water.h"

class Energy : public Air, public Water
{
public:
	bool interacts(std::string other);
};

