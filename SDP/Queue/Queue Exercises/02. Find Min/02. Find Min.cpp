#include <iostream>
#include <queue>

int findMinElement(std::queue<int> q)
{
	int minElement = q.front();
	q.push(q.front());
	q.pop();
	
	for (int i = 1; i < q.size(); i++)
	{
		int crrEl = q.front();
		
		if (crrEl < minElement)
		{
			minElement = crrEl;
		}

		q.push(q.front());
		q.pop();
	}

	return minElement;
}

int main()
{
	std::queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(0);
	queue.push(4);
	queue.push(5);

	std::cout << findMinElement(queue) << std::endl;
}