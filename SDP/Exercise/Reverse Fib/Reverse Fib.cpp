#include <iostream>

template <class T>
struct Node
{
	T data;
	Node* next;
};

template <class T>
Node<T>* reverseFib(Node<T>* first)
{
	if (first == nullptr || first->next == nullptr || first->next->next == nullptr)
	{
		return nullptr;
	}

	Node<T>* result = new Node<T>{ first->data, nullptr };

	while (first->next->next != nullptr)
	{
		if (first->data + first->next->data != first->next->next->data)
		{
			Node<T>* current = result;

			while (current != nullptr)
			{
				Node<T>* save = current;
				current = current->next;
				delete save;
			}

			return nullptr;
		}

		first = first->next;
		Node<T>* newNode = new Node<T>{ first->data, result };
		result = newNode;
	}

	Node<T>* newNode = new Node<T>{ first->next->data, result };
	result = newNode;

	return result;
}

template <class T>
void printList(Node<T>* first)
{
	if (first == nullptr)
	{
		std::cout << "Empty list!" << std::endl;
		return;
	}
	Node<T>* current = first;

	while (current != nullptr)
	{
		std::cout << current->data << "->";
		current = current->next;
	}

	std::cout << "nullptr" << std::endl;
}


int main()
{
	Node<int>* first1 =
		new Node<int>{ 0,
			new Node<int>{1,
				new Node<int>{1,
					new Node<int>{2,
						new Node<int>{3, nullptr}}}} };

	Node<int>* newFirst1 = reverseFib(first1);
	printList(first1);
	printList(newFirst1);

	Node<int>* first2 =
		new Node<int>{ 0,
			new Node<int>{1,
				new Node<int>{2,
					new Node<int>{3,
						new Node<int>{4,
							new Node<int>{5,
								new Node<int>{6, nullptr}}}}}} };

	Node<int>* newFirst2 = reverseFib(first2);
	printList(first2);
	printList(newFirst2);

	return 0;
}