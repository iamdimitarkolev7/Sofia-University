#include <iostream>
#include <queue>

void filterOdd(std::queue<int>& q)
{
	int size = q.size();
	
	for (int i = 0; i < size; i++)
	{
		int crrElement = q.front();
		
		if (crrElement % 2 == 0)
		{
			q.push(crrElement);
		}

		q.pop();
	}
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
	std::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	filterOdd(q);
	printQueue(q);
	
	return 0;
}