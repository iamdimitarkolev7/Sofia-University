#include <iostream>

template <class T>
struct Node
{
	T data;
	Node* next;
};

template <class T>
size_t length(Node<T>* first)
{
	size_t counter = 0;
	Node<T>* current = first;

	while (current != nullptr)
	{
		counter++;
		current = current->next;
	}

	return counter;
}

template <class T>
void shuffle(Node<T>*& first)
{

	if (first == nullptr || first->next == nullptr)
		return;
	
	size_t middleIndex = length(first) / 2;
	
	if (length(first) % 2 != 0)
		middleIndex++;

	Node<T>* current = first, * previous = nullptr;

	while (current != nullptr && middleIndex > 0)
	{
		middleIndex--;
		previous = current;
		current = current->next;
	}
	
	while (current != nullptr)
	{
		previous->next = current->next;
		Node<T>* temp = current->next;
		current->next = first;
		first = current;
		current = temp;
	}
}

template <class T>
void print(Node<T>* first)
{
	while (first != nullptr)
	{
		std::cout << first->data << "->";
		first = first->next;
	}

	std::cout << "nullptr" << std::endl;
}

int main()
{
	Node<int>* first = new Node<int>{ 1,
						new Node<int>{2,
						new Node<int>{3,
						new Node<int>{4,
						new Node<int>{5, nullptr}}}}};

	print(first);
	shuffle(first);
	print(first);
	
	return 0;
}