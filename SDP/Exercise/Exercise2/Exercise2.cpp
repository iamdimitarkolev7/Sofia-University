#include <iostream>

template <class T>
struct Node
{
	T data;
	Node* next;
};

void fillGaps(Node<int>* first)
{
	if (first == nullptr || first->next == nullptr)
		return;

	Node<int>* current = first;

	while (current->next != nullptr)
	{
		if (current->data + 1 < current->next->data)
		{
			Node<int>* newNode = new Node<int>{ current->data + 1, current->next };
			current->next = newNode;
		}

		current = current->next;
	}
}

void print(Node<int>* first)
{
	if (first == nullptr)
	{
		std::cout << "Empty List" << std::endl;
		return;
	}
	
	Node<int>* current = first;
	
	while (current != nullptr)
	{
		std::cout << current->data << "->";
		current = current->next;
	}

	std::cout << "nullptr"<< std::endl;
}

void removeDuplicates(Node<int>* first)
{
	if (first == nullptr)
		return;

	Node<int>* tempCurrent = first;

	while (tempCurrent != nullptr)
	{
		Node<int>* current = tempCurrent;

		while (current->next != nullptr)
		{
			if (tempCurrent->data == current->next->data)
			{
				Node<int>* save = current->next;
				current->next = current->next->next;
				delete save;
			}
			else
			{
				current = current->next;
			}
		}

		tempCurrent = tempCurrent->next;
	}
}

void mirror(Node<int>* first)
{
	if (first == nullptr)
		return;
	
	Node<int>* newListFirst = nullptr;
	Node<int>* current = first;

	while (current->next != nullptr)
	{
		Node<int>* newNode = new Node<int>{ current->data, newListFirst };
		newListFirst = newNode;
		current = current->next;
	}

	Node<int>* newNode = new Node<int>{ current->data, newListFirst };
	newListFirst = newNode;
	
	current->next = newListFirst;
}

int main()
{
	Node<int>* first = new Node<int>{ 1, new Node<int>{5,
						new Node<int>{2, new Node<int>{5,
						new Node<int>{5, nullptr}}}} };

	print(first);
	
	print(first);
	return 0;
}