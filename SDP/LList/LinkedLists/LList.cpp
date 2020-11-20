#include <iostream>
#include <cassert>

template <typename T>
class LList
{
	struct box
	{
		box(const T& _data, box* _next);
		T data;
		box* next;
	};

	box* at(size_t pos);
	box *first, *last;

public:

	using value_type = T;
	
	LList();
	~LList();

	void push(const T& x);
	void push_back(const T& x);
	void pop();
	void insertAfter(const T& x, size_t pos);
	void deleteAfter(size_t pos);
	void reverse();
	void print();
	void sort();
	size_t size() const;
	int longestIncreasing();

	T& operator[](size_t i);
	T operator[](size_t i) const;

	class Iterator
	{
		box* current;

	public:
		Iterator(box* element);
		bool operator != (const Iterator& it);
		Iterator& operator ++ ();
		T& operator * ();
	};

	Iterator begin();
	Iterator end();
};


template <typename T>
LList<T>::LList()
{
	first = nullptr;
	last = nullptr;
}

template <typename T>
LList<T>::~LList()
{
	box* crr = first;
	
	while (crr != nullptr)
	{
		box* save = crr;
		crr = crr->next;
		delete save;
	}
}

template <typename T>
void LList<T>::push(const T& x)
{
	/*box* newBox = new box(x, nullptr);
	newBox->next = first;
	first = newBox;*/

	first = new box(x, first);

	if (last == nullptr)
	{
		last = first;
	}
}

template <typename T>
void LList<T>::push_back(const T& x)
{
	if (first == nullptr)
	{
		push(x);
		return;
	}

	last = last->next = new box(x, nullptr);
}

template <typename T>
void LList<T>::pop()
{
	if (first != nullptr)
	{
		box* save = first;
		first = first->next;
		delete save;
	}
	else
	{
		last = nullptr;
		std::cout << "The list is empty!" << std::endl;
	}
}

template <typename T>
size_t LList<T>::size() const
{
	int counter = 0;
	box* crr = first;

	while (crr != nullptr)
	{
		crr = crr->next;
		++counter;
	}

	return counter;
}

template <typename T>
int LList<T>::longestIncreasing()
{
	box* crr = first;
	size_t crrSequence = 1;
	size_t longestSequence = 0;
	
	while(crr != nullptr)
	{
		while (crr->next != nullptr && crr->data <= crr->next->data)
		{
			crrSequence++;
			crr = crr->next;
		}

		if (crrSequence > longestSequence)
		{
			longestSequence = crrSequence;
		}

		crrSequence = 1;
		crr = crr->next;
	}

	return longestSequence;
}

template <typename T>
void LList<T>::insertAfter(const T& x, size_t pos)
{
	box* pred = at(pos);

	/*box* newElement = new box(x, nullptr);
	newElement->next = pred->next;
	pred->next = newElement;*/

	pred->next = new box(x, pred->next);
	if (pred == last)
	{
		last = last->next;
	}
}

template <typename T>
void LList<T>::deleteAfter(size_t pos)
{
	box* pred = at(pos);
	box* save = pred->next;

	if (pred->next == nullptr)
	{
		return;
	}

	pred->next = pred->next->next;

	if (save == last)
	{
		last = pred;
	}

	delete save;
}

template <typename T>
void LList<T>::reverse()
{
	assert(first != nullptr);
	box* current = first;
	box* prev = nullptr, *next = nullptr;

	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	first = prev;
}

template <typename T>
void LList<T>::print()
{
	assert(first != nullptr);
	box* current = first;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}

	std::cout << std::endl;
}

template <typename T>
void LList<T>::sort()
{
	assert(first != nullptr);
	bool swapped = true;
	int i;
	box* box1 = first;
	box* box2 = nullptr;

	while (swapped) {
		swapped = false;
		box1 = first;

		while (box1->next != box2)
		{
			if (box1->data > box1->next->data)
			{
				T temp = box1->data;
				box1->data = box2->data;
				box2->data = temp;
				swapped = true;
			}

			box1 = box1->next;
		}

		box2 = box1;
	}
}

template <typename T>
T& LList<T>::operator[](size_t i)
{
	return at(i)->data;
}

template <typename T>
T LList<T>::operator[](size_t i) const
{
	return at(i)->data;
}

template <typename T>
LList<T>::box::box(const T& _data, box* _next) : data(_data), next(_next) {}

template <typename T>
typename LList<T>::box* LList<T>::at(size_t pos)
{
	assert(first != nullptr);
	box* crr = first;
	while (pos > 0 && crr != nullptr)
	{
		crr = crr->next;
		--pos;
	}
	assert(crr != nullptr);

	return crr;
}

template <typename T>
LList<T>::Iterator::Iterator(box* element) :current(element)
{

}

template <typename T>
bool LList<T>::Iterator::operator!=(const typename Iterator& it)
{
	return current != it.current;
}

template <typename T>
typename LList<T>::Iterator& LList<T>::Iterator::operator++()
{
	assert(current != nullptr);
	current = current->next;
	return *this;
}

template <typename T>
T& LList<T>::Iterator::operator*()
{
	assert(current != nullptr);
	return current->data;
}

template <typename T>
typename LList<T>::Iterator LList<T>::begin()
{
	return typename LList<T>::Iterator(first);
}

template <typename T>
typename LList<T>::Iterator LList<T>::end()
{
	return typename LList<T>::Iterator(nullptr);
}