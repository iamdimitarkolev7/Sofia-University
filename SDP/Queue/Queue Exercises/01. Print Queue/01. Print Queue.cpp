#include <iostream>
#include <queue>

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
	std::queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);

	printQueue(queue);

	queue.push(6);
	queue.push(7);

	printQueue(queue);
	return 0;
}