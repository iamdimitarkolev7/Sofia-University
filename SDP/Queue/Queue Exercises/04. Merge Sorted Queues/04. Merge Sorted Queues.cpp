#include <iostream>
#include <queue>

std::queue<int>& merge(std::queue<int>& q1, std::queue<int>& q2)
{
	int steps = q1.size() + q2.size();
	std::queue<int>* result = new std::queue<int>();
	
	for (int i = 0; i < steps; i++)
	{
		while (q1.size() > 0 && q2.size() > 0)
		{
			if (q1.front() < q2.front())
			{
				result->push(q1.front());
				q1.pop();
			}
			else
			{
				result->push(q2.front());
				q2.pop();
			}
		}
		
		while (q2.size() != 0)
		{
			result->push(q2.front());
			q2.pop();
		}

		while (q1.size() != 0)
		{
			result->push(q1.front());
			q1.pop();
		}
	}

	return *result;
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
	std::queue<int> q1, q2;

	q1.push(3);
	q1.push(5);
	q1.push(7);
	q1.push(18);
	q1.push(40);
	q2.push(1);
	q2.push(2);
	q2.push(17);
	q2.push(105);

	std::queue<int> result = merge(q1, q2);

	printQueue(result);

	return 0;
}