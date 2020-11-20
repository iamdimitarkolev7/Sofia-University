#include <iostream>
#include <stack>
#include <queue>

template <class T>
std::queue<T> fillQueue(std::stack<T>& stack)
{
	std::queue<T> result;
	int counter = 1;
	std::stack<T> helperStack;

	while (!stack.empty())
	{
		helperStack.push(stack.top());
		stack.pop();
	}

	while (!helperStack.empty())
	{
		if (counter % 2 == 0)
		{
			result.push(helperStack.top());
		}
		
		stack.push(helperStack.top());
		helperStack.pop();
		counter++;
	}

	return result;
}

template <class T>
void printQueue(std::queue<T> queue)
{
	while (!queue.empty())
	{
		std::cout << queue.front() << " ";
		queue.pop();
	}

	std::cout << std::endl;
}

template <class T>
void printStack(std::stack<T> stack)
{
	while (!stack.empty())
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}

	std::cout << std::endl;
}

int main()
{
	std::stack<int> stack;
	stack.push(1); stack.push(2); stack.push(3); stack.push(4); stack.push(5); stack.push(6);
	std::queue<int> q = fillQueue<int>(stack);

	printQueue(q);
	printStack(stack);

	return 0;
}