#include <iostream>
#include <stack>
#include <queue>

void reverse(std::queue<int>& q)
{
	std::queue<int> result;
	std::stack<int> helper;
	int steps = q.size();

	for (int i = 0; i < steps; i++)
	{
		helper.push(q.front());
		q.pop();
	}

	while(!helper.empty())
	{
		result.push(helper.top());
		helper.pop();
	}

	q = result;
}

void printQueue(std::queue<int> q)
{
	for (int i = 0; i < q.size(); i++)
	{
		int element = q.front();
		std::cout << element << " ";
		q.push(element);
		q.pop();
	}

	std::cout << std::endl;
}

int main()
{
	std::queue<int> q1;

	q1.push(3);
	q1.push(5);
	q1.push(7);
	q1.push(18);
	q1.push(40);

	reverse(q1);
	printQueue(q1);
	return 0;
}