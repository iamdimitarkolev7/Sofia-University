#include <iostream>
#include <exception>
#include <functional>
#include <stack>
#include <queue>

template <class T>
using func = T * (const T&, const T&);

template <class T>
struct Node
{
	T data;
	Node<T>* next;
};

template <class T>
size_t nodeCounter(Node<T>* first)
{
	size_t counter = 0;

	while (first != nullptr)
	{
		counter++;
		first = first->next;
	}

	return counter;
}

template <class T>
T reduce(Node<T>* first, func<T> f)
{
	if (nodeCounter(first) == 0)
	{
		std::_Throw_range_error("Length must be higher than 0");
	}

	if (nodeCounter(first) == 1)
	{
		return f(first->data, first->data);
	}
	
	Node<T>* current = first;

	while (current->next != nullptr)
	{
		Node<T>* newNode = { f(current->data, current->next->data), current->next->next };
		delete current->next;
		delete current;
		current = newNode;
	}

	return current;
}

int main()
{
	Node<int>* first = new Node<int>{ 1,
						new Node<int>{2,
						new Node<int>{3,
						new Node<int>{4, nullptr}}} };


	
	
	return 0;
}