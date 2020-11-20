#ifndef __LLIST_CPP
#define __LLIST__CPP

#include <iostream>
#include <cassert>
#include <cmath>

template <class T>
class LList
{
	struct Node
	{
		T data;
		Node* next;
	};

	Node* first;

	void clear();

public:
	LList();
	~LList();

	Node* getAt(size_t index);
	Node* min();
	Node* max();
	size_t length();
	void atBegining(const T& data);
	void atEnd(const T& data);
	void at(const T& data, size_t index);
	void deleteAt(size_t index);
	void print();
	void reverse();
	void swapNodes(size_t i, size_t j); // swaps 2 Nodes in given indexes
	void swap(size_t i, size_t j); // swaps values
	void sort();
	void unique();
	bool hasCycle();
	int longestIncreasing(); // finds longest increasing sequence of data in a list
};

template <class T>
void LList<T>::clear()
{
	Node* current = first;

	while (current != nullptr)
	{
		Node* temp = current;
		current = current->next;
		delete temp;
	}
}

template <class T>
size_t LList<T>::length()
{
	Node* current = first;
	size_t length = 0;

	while(current != nullptr)
	{
		length++;
		current = current->next;
	}

	return length;
}

template <class T>
LList<T>::LList():first(nullptr) {}

template <class T>
LList<T>::~LList()
{
	clear();
}

template <class T>
typename LList<T>::Node* LList<T>::getAt(size_t index)
{
	Node* current = first;

	while (current != nullptr && index > 0)
	{
		current = current->next;
		--index;
	}

	return current;
}

template <class T>
void LList<T>::atBegining(const T& data)
{
	Node* newNode = new Node();
	newNode->data = data;

	if (first == nullptr)
	{
		first = newNode;
		return;
	}

	newNode->next = first;
	first = newNode;
}

template <class T>
void LList<T>::atEnd(const T& data)
{
	Node* current = first;
	Node* newNode = new Node();
	newNode->data = data;

	if (first == nullptr)
	{
		atBegining(data);
		return;
	}

	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = newNode;
}

template <class T>
void LList<T>::at(const T& data, size_t index)
{
	if (index < 0 || index > length())
	{
		std::cout << "Wrong index!" << std::endl;
		return;
	}

	Node* current = first;
	Node* newNode = new Node();
	newNode->data = data;

	if (index == 0)
	{
		atBegining(data);
		return;
	}

	while (current != nullptr && index > 1)
	{
		current = current->next;
		index--;
	}

	newNode->next = current->next;
	current->next = newNode;
}

template <class T>
void LList<T>::deleteAt(size_t index)
{
	if (index < 0 || index >= length())
	{
		std::cout << "Wrong index!" << std::endl;
		return;
	}

	Node* current = first;

	if (index == 0)
	{
		Node* temp = first;
		first = first->next;
		delete temp;
		return;
	}

	while (current->next != nullptr && index > 1)
	{
		current = current->next;
		--index;
	}
	
	Node* temp = current->next;
	current->next = current->next->next;
	delete temp;
}

template <class T>
int LList<T>::longestIncreasing()
{
	Node* current = first;
	int longestSequence = 0;

	while (current != nullptr)
	{
		int currentSequence = 1;
		
		while (current->next != nullptr && (current->data < current->next->data))
		{
			currentSequence++;
			current = current->next;

			if (currentSequence > longestSequence)
			{
				longestSequence = currentSequence;
			}
		}

		currentSequence = 1;
		current = current->next;
	}

	return longestSequence;
}

template <class T>
void LList<T>::print()
{
	if (first == nullptr)
	{
		std::cout << "Empty list!" << std::endl;
		return;
	}

	Node* current = first;
	
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}

	std::cout << std::endl;
}

template <class T>
void LList<T>::reverse()
{
	Node* current = first;
	Node* previous = nullptr, * next = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	first = previous;
}

template <class T>
void LList<T>::swapNodes(size_t i, size_t j)
{
	if (i == j) return;
	
	Node* current = first;
	Node* previousI = nullptr, * elementI = nullptr;
	Node* previousJ = nullptr, * elementJ = nullptr;

	while (current != nullptr && i > 0)
	{
		previousI = current;
		current = current->next;
		--i;
	}
	elementI = current;

	current = first;

	while (current != nullptr && j > 0)
	{
		previousJ = current;
		current = current->next;
		--j;
	}
	elementJ = current;

	Node* temp = elementI->next;
	
	if (previousI != nullptr)
	{
		previousI->next = elementJ;
	}
	else
	{
		first = elementJ;
	}

	elementI->next = elementJ->next;
	
	if (previousJ != nullptr)
	{
		previousJ->next = elementI;
	}
	else
	{
		first = elementI;
	}

	elementJ->next = temp;
}

template <class T>
void LList<T>::swap(size_t i, size_t j)
{
	Node* current = first;

	while (current != nullptr && i > 0)
	{
		current = current->next;
		--i;
	}
	Node* nodeI = current;

	current = first;

	while (current != nullptr && j > 0)
	{
		current = current->next;
		--j;
	}
	Node* nodeJ = current;

	Node* temp = new Node();
	temp->data = nodeI->data;
	nodeI->data = nodeJ->data;
	nodeJ->data = temp->data;
	
}

template <class T>
typename LList<T>::Node* LList<T>::max()
{
	Node* current = first;
	Node* max = first;

	while (current != nullptr)
	{
		if (current->data > max->data)
		{
			max = current;
		}

		current = current->next;
	}

	return max;
}

template <class T>
typename LList<T>::Node* LList<T>::min()
{
	Node* current = first;
	Node* min = first;

	while (current != nullptr)
	{
		if (current->data < min->data)
		{
			min = current;
		}

		current = current->next;
	}

	return min;
}

template <class T>
void LList<T>::sort()
{
	Node* tempCurrent = first;
	Node* newFirst = nullptr, * newCurrent = nullptr;

	while (tempCurrent != nullptr)
	{
		Node* current = tempCurrent;
		Node* previous = nullptr;

		Node* currentMin = current, * previousMin = previous;
		while (current != nullptr)
		{
			if (currentMin->data > current->data)
			{
				currentMin = current;
				previousMin = previous;
			}

			previous = current;
			current = current->next;
		}

		if (tempCurrent == currentMin)
		{
			tempCurrent = tempCurrent->next;
		}
		else
		{
			previousMin->next = previousMin->next->next;
		}

		if (newFirst == nullptr)
		{
			newFirst = currentMin;
			newCurrent = newFirst;
		}
		else
		{
			newCurrent->next = currentMin;
			newCurrent = newCurrent->next;
			newCurrent->next = nullptr;
		}
	}

	first = newFirst;
}

template <class T>
void LList<T>::unique()
{
	Node* tempCurrent = first;
	Node* save = nullptr;

	while (tempCurrent != nullptr)
	{
		Node* current = tempCurrent->next;
		Node* previous = tempCurrent;

		while (current != nullptr)
		{
			if (current->data == tempCurrent->data)
			{
				Node* save = current;
				previous->next = previous->next->next;
				current = current->next;
				delete save;
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}

		tempCurrent = tempCurrent->next;
	}
}

template <class T>
bool LList<T>::hasCycle()
{
	if (first == nullptr)
	{
		return false;
	}
	
	Node* slow = first, * fast = first;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return true;
		}
	}

	return false;
}

#endif
