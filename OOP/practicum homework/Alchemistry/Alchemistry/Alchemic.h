#pragma once
#include "Book.h"
#include <vector>

class Alchemic
{
private:
	Book alchemicalBook;
	std::vector<int> elementAmounts;

public:
	void giveBook(Book book);
	void giveElAmounts(std::vector<int> amounts);
	bool canCreateStone();
};

