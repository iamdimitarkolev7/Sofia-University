#include <iostream>
#include "LList.cpp"

int main()
{
	LList<int> list;
	/*list.atBegining(3);
	list.atBegining(2);
	list.atBegining(1);
	list.atEnd(5);
	list.atEnd(4);
	list.at(6, 5);*/
	list.atEnd(1);
	list.atEnd(2);
	list.atEnd(1);
	list.atEnd(2);
	list.atEnd(7);
	list.atEnd(3);
	list.atEnd(3);
	list.print();
	list.unique();
	//list.deleteAt(1);
	//list.swapNodes(0, 5);
	//list.reverse();
	list.print();
	//std::cout << list.longestIncreasing() << std::endl;

	return 0;
}