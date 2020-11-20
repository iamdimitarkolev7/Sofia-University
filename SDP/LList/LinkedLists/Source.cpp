#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "LList.cpp"
#include "doctest.h"

template <typename Container>
typename Container::value_type sum(Container& container)
{
	typename Container::value_type sum = 0;

	for (typename Container::value_type x : container)
	{
		sum += x;
	}

	return sum;
}

TEST_CASE("Test push method")
{
	LList<int> list;

	list.push(5);
	list.push(7);

	CHECK(list[0] == 7);
	CHECK(list[1] == 5);
}

TEST_CASE("Check operator =")
{
	LList<int> list;

	list.push(5);
	list.push(7);
	list[0] = 46;
	list[1] = 67;

	CHECK(list[0] == 46);
	CHECK(list[1] == 67);
}

TEST_CASE("Check insertAfter method")
{
	LList<int> list;

	list.push(5);
	list.push(7);
	list.insertAfter(8, 0);

	CHECK(list[0] == 7);
	CHECK(list[1] == 8);
	CHECK(list[2] == 5);
}

TEST_CASE("Check pop method")
{
	LList<int> list;

	list.push(5);
	list.push(7);
	list.push(8);

	list.pop();

	CHECK(list[0] == 7);
	CHECK(list[1] == 5);

	list.pop();

	CHECK(list[0] == 5);

	list.pop();

	CHECK(list.size() == 0);
}

TEST_CASE("Check deleteAfter method")
{
	LList<int> list;
	list.push(1);
	list.push(2);
	list.push(3);
	list.deleteAfter(0);

	CHECK(list[0] == 3);
	CHECK(list[1] == 1);

	list.deleteAfter(1);
	
	CHECK(list[0] == 3);
	CHECK(list[1] == 1);
}

TEST_CASE("Check push_back method")
{
	LList<int> list;
	list.push(1);
	list.push(2);
	list.push_back(123);

	CHECK(list[2] == 123);
}

TEST_CASE("Check longestIncreasing() method")
{
	LList<int> list;

	list.push(5);
	list.push(4);
	list.push(3);
	list.push(2);
	list.push(1);
	list.push(0);
	list.push(1);
	list.push(2);

	int longestSequence = list.longestIncreasing();

	CHECK(longestSequence == 6);

	LList<double> list2;

	CHECK(list2.longestIncreasing() == 0);
}

TEST_CASE("Check reverse() method")
{
	LList<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.reverse();

	CHECK(list[0] == 3);
	CHECK(list[1] == 2);
	CHECK(list[2] == 1);
}

TEST_CASE("Test sum function")
{
	LList<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	CHECK(sum(list) == 60);
}

TEST_CASE("Test sort function")
{
	LList<int> list;
	list.push_back(10);
	list.push_back(30);
	list.push_back(20);
	list.push_back(5);

	list.sort();
	list.print();
}

int main()
{	
	doctest::Context().run();

	return 0;
}