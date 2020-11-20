#include <iostream>
#include <queue>

std::queue<int> buildQueue(int n, int k)
{
	std::queue<int> result;
	int counter = 1, element = n;

	result.push(element);
	
	while (k != 0)
	{
		if (counter % 2 == 0)
		{
			result.push(element * 2);
			element = element + 1;
		}
		else
		{
			result.push(element + 1);
		}
		k--;
		counter++;
	}

	return result;
}

void printQueue(std::queue<int> s)
{
	while (!s.empty())
	{
		std::cout << s.front() << " ";
		s.pop();
	}

	std::cout << std::endl;
}

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::queue<int> result = buildQueue(n, k);
	printQueue(result);

	return 0;
}