#include <iostream>
#include <stack>
#include <queue>

template <class T>
struct Node
{
	T data;
	Node<T>* next;
};

template <class T>
size_t nodeCounter(Node<std::stack<T>>* first)
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
size_t stackElementCounter(Node<std::stack<T>>* first)
{
	size_t counter = 0;
	std::queue<T> helper;

	while (first != nullptr)
	{
		while (!first->data.empty())
		{
			counter++;
			helper.push(first->data.top());
			first->data.pop();
		}

		while (!helper.empty())
		{
			first->data.push(helper.front());
			helper.pop();
		}

		first = first->next;
	}

	return counter;
}

template <class T>
void equalize(Node<std::stack<T>>* first)
{
	size_t averageElementsInNode = stackElementCounter(first) / nodeCounter(first);

	Node<std::stack<T>>* current = first;
	std::queue<T> helper;

	while (current != nullptr)
	{
		while (current->data.size() > averageElementsInNode)
		{
			helper.push(current->data.top());
			current->data.pop();
		}

		while (current->data.size() < averageElementsInNode && !helper.empty())
		{
			current->data.push(helper.front());
			helper.pop();
		}

		current = current->next;
	}

	// The helper should be empty at the end that's why I iterate once again till the helper queue becomes empty
	while (!helper.empty())
	{
		current = first;

		while (current != nullptr && !helper.empty())
		{
			current->data.push(helper.front());
			helper.pop();
			current = current->next;
		}
	}
}

template <class T>
void print(Node<std::stack<T>>* first)
{
	while (first != nullptr)
	{
		while (!first->data.empty())
		{
			std::cout << first->data.top() << " ";
			first->data.pop();
		}
		
		std::cout << std::endl;
		first = first->next;
	}
}

int main()
{
	std::stack<int> stack1;
	stack1.push(1); stack1.push(2); stack1.push(3); stack1.push(8);

	std::stack<int> stack2;
	stack2.push(4); stack2.push(5);

	std::stack<int> stack3;
	stack3.push(6);

	Node<std::stack<int>>* first = new Node<std::stack<int>>{ stack1,
									new Node<std::stack<int>>{stack2,
									new Node<std::stack<int>>{stack3, nullptr}} };

	//print(first);
	equalize(first);
	print(first);

	return 0;
}