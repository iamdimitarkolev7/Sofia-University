#include <iostream>
#include "BinTree.cpp"

int main()
{
	BinTree<int> t;

	t.push(100, "");
	t.push(20, "L");
	t.push(3, "R");
	t.push(40, "LL");
	t.push(50, "LR");
	t.push(60, "RL");

	if (t.contains(83))
	{
		std::cout << "Found!" << std::endl;
	}
	else
	{
		std::cout << "ERROR 404!" << std::endl;
	}

	std::cout << "Min: " << t.min() << std::endl;
	std::cout << "Max: " << t.max() << std::endl;

	if (t.isEven())
	{
		std::cout << "All elements are even!" << std::endl;
	}
	else
	{
		std::cout << "There are odd elements in the tree" << std::endl;
	}	
	
	return 0;
}